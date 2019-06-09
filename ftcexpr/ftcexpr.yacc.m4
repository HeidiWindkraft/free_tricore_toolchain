/* ftcexpr.yacc.m4
 * LICENSE: GPL v3
*/
changecom()dnl /* No comments */
changequote(`[[[',`]]]')dnl /* No easy to hit quotes */

%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.4"
%defines

%define api.namespace {ftcexpr}
%define api.prefix {ftcexpr_}
%define api.token.constructor
%define api.value.type variant
%define parse.assert

// This code needs to know the driver object.
// Avoid circular dependencies using forward declarations.
%code requires {
#include "ftcexpr_demo_driver_fwd.hxx"
}

// The lexing and parsing context.
%param { ftcexpr_demo::Driver& drv }
%param {void *yyscanner}

// Track locations.
%locations

%define parse.trace
%define parse.error verbose

%code {
#include "ftcexpr_demo_driver.hxx"
#include "ftcexpr_parse_intlit.hxx"

#define FTCEXPR_DRV() drv
}

%define api.token.prefix {TOK_}

// Tokens
%token <std::string> INTLITERAL
%token <std::string> IDENTIFIER
%token END 0 "end of file"
%token NEVER_TOKEN_MACC
%token NEVER_TOKEN_INC_OP
%token NEVER_TOKEN_DEC_OP
%token NEVER_TOKEN_ADDRESSOF
%token NEVER_TOKEN_DEREFER
%token NEVER_TOKEN_TYPE
%token LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP
%token NEVER_TOKEN_SIZEOF

%type <uint64_t> ftcexpr_primary_leaf_expression
%type <uint64_t> ftcexpr_LEFT_OP ftcexpr_RIGHT_OP ftcexpr_LE_OP ftcexpr_GE_OP ftcexpr_EQ_OP ftcexpr_NE_OP
%type <uint64_t> ftcexpr_AND_OP ftcexpr_OR_OP
%type <uint64_t> ftcexpr_argument_expression_list ftcexpr_member_access ftcexpr_INC_OP ftcexpr_DEC_OP
%type <uint64_t> ftcexpr_cast_expression ftcexpr_ADDRESSOF ftcexpr_DEREFER ftcexpr_type ftcexpr_SIZEOF

%printer { yyo << $$; } <*>;

%start input

include(ftcexpr_rule_types.yacc)

%%

input: ftcexpr_expression END { drv.last_result = $1; };

ftcexpr_primary_leaf_expression
	: INTLITERAL { $$ = ftcexpr::parse_intlit($1).value; }
	| IDENTIFIER { $$ = FTCEXPR_DRV().demo_getfunc($1); }
	;


ftcexpr_LEFT_OP : LEFT_OP  { $$ = 0; };
ftcexpr_RIGHT_OP: RIGHT_OP { $$ = 0; };
ftcexpr_LE_OP   : LE_OP    { $$ = 0; };
ftcexpr_GE_OP   : GE_OP    { $$ = 0; };
ftcexpr_EQ_OP   : EQ_OP    { $$ = 0; };
ftcexpr_NE_OP   : NE_OP    { $$ = 0; };
ftcexpr_AND_OP  : AND_OP   { $$ = 0; };
ftcexpr_OR_OP   : OR_OP    { $$ = 0; };

ftcexpr_argument_expression_list: ftcexpr_expression { $$ = $1; };
ftcexpr_member_access: NEVER_TOKEN_MACC { $$ = 0; };
ftcexpr_INC_OP  : NEVER_TOKEN_INC_OP { $$ = 0; };
ftcexpr_DEC_OP  : NEVER_TOKEN_DEC_OP { $$ = 0; };
ftcexpr_cast_expression: ftcexpr_unary_expression { $$ = $1; };
ftcexpr_ADDRESSOF: NEVER_TOKEN_ADDRESSOF { $$ = 0; };
ftcexpr_DEREFER: NEVER_TOKEN_DEREFER { $$ = 0; };
ftcexpr_type: NEVER_TOKEN_TYPE { $$ = 0; };

ftcexpr_SIZEOF: NEVER_TOKEN_SIZEOF { $$ = 0; }

include(ftcexpr_rules.yacc)

%%

void ftcexpr::parser::error(ftcexpr::location const &loc, std::string const &msg) {
	throw ftcexpr::parser::syntax_error(loc, msg);
}

