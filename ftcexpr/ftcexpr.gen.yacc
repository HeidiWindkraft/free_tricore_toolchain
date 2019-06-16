/* ftcexpr.yacc.m4
 * LICENSE: GPL v3
*/

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

/* ftcexpt_rule_types.yacc
 * LICENSE: GPL version 3, see LICENSE
 *
 * This file provides typing for integer expression rules.
*/

%type <ftcexpr_rule_type> ftcexpr_primary_expression  ftcexpr_postfix_expression ftcexpr_unary_expression
%type <ftcexpr_rule_type> ftcexpr_multiplicative_expression ftcexpr_additive_expression ftcexpr_shift_expression
%type <ftcexpr_rule_type> ftcexpr_relational_expression ftcexpr_equality_expression ftcexpr_and_expression
%type <ftcexpr_rule_type> ftcexpr_exclusive_or_expression ftcexpr_inclusive_or_expression
%type <ftcexpr_rule_type> ftcexpr_logical_and_expression ftcexpr_logical_or_expression ftcexpr_conditional_expression

%type <ftcexpr_rule_type> ftcexpr_expression



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

/* ftcexpt_rules.yacc
 * LICENSE: GPL version 3, see LICENSE
 *
 * This file contains rules for integer expressions.
 * It is meant to be processed by M4.
*/
/* [DRIVER] FTCEXPR_DRV() is meant to retrieve the driver interface and shall work in several languages.
 *          C: Could be a define to a global variable containing function pointers.
 *             Could be `*drv` where `drv` is an additional pointer argument to the parse function
 *               which points to a struct containing function pointers.
 *          C++: Could be `drv` where `drv` is an additional reference argument to the parse function
 *                 which points to an object having methods.
 *          Java: Could be a method returning an object which has methods.
*/
/* [RULE_CALLOUT]
 *   ftcexpr_primary_leaf_expression: INTEGER_LITERAL | IDENTIFIER | ...;
 *   ftcexpr_LEFT_OP : "<<"
 *   ftcexpr_RIGHT_OP: ">>"
 *   ftcexpr_LE_OP   : "<="
 *   ftcexpr_GE_OP   : ">="
 *   ftcexpr_EQ_OP   : "=="
 *   ftcexpr_NE_OP   : "!="
 *   ftcexpr_AND_OP  : "&&"
 *   ftcexpr_OR_OP   : "||"
 *   ftcexpr_argument_expression_list: ...
 *   ftcexpr_member_access: '.' IDENTIFIER | PTR_OP IDENTIFIER; ftcexpr_member_access: NEVER_TOKEN;
 *   ftcexpr_INC_OP  : "++"  : NEVER_TOKEN;
 *   ftcexpr_DEC_OP  : "--"  : NEVER_TOKEN;
 *   ftcexpr_cast_expression: ftcexpr_unary_expression
 *   ftcexpr_ADDRESSOF: "&" : NEVER_TOKEN;
 *   ftcexpr_DEREFER: "*" : NEVER_TOKEN;
 *   ftcexpr_type: ... : NEVER_TOKEN;
*/

ftcexpr_primary_expression
	: ftcexpr_primary_leaf_expression { $$ = $1; }
	| '(' ftcexpr_expression ')' { $$ = $2; }
	;

ftcexpr_postfix_expression
	: ftcexpr_primary_expression { $$ = $1; }
	| ftcexpr_postfix_expression '[' ftcexpr_expression ']' { $$ = FTCEXPR_DRV().subscript($1,$3); }
	| ftcexpr_postfix_expression '(' ftcexpr_argument_expression_list ')' { $$ = FTCEXPR_DRV().call($1,$3); }
	| ftcexpr_postfix_expression ftcexpr_member_access { $$ = FTCEXPR_DRV().member_access($1, $2); }
	| ftcexpr_postfix_expression ftcexpr_INC_OP { $$ = FTCEXPR_DRV().post_inc($1); }
	| ftcexpr_postfix_expression ftcexpr_DEC_OP { $$ = FTCEXPR_DRV().post_dec($1); }
	;

ftcexpr_unary_expression
	: ftcexpr_postfix_expression { $$ = $1; }
	| '+' ftcexpr_cast_expression { $$ = FTCEXPR_DRV().unary_plus($2); }
	| '-' ftcexpr_cast_expression { $$ = FTCEXPR_DRV().neg($2); }
	| '~' ftcexpr_cast_expression { $$ = FTCEXPR_DRV().bitwnot($2); }
	| '!' ftcexpr_cast_expression { $$ = FTCEXPR_DRV().logcnot($2); }
	| ftcexpr_ADDRESSOF ftcexpr_cast_expression { $$ = FTCEXPR_DRV().addressof($2); }
	| ftcexpr_DEREFER ftcexpr_cast_expression { $$ = FTCEXPR_DRV().derefer($2); }
	| ftcexpr_INC_OP ftcexpr_unary_expression { $$ = FTCEXPR_DRV().pre_inc($2); }
	| ftcexpr_DEC_OP ftcexpr_unary_expression { $$ = FTCEXPR_DRV().pre_dec($2); }
	| ftcexpr_SIZEOF ftcexpr_unary_expression { $$ = FTCEXPR_DRV().sizeof_expr($2); }
	| ftcexpr_SIZEOF '(' ftcexpr_type ')' { $$ = FTCEXPR_DRV().sizeof_type($3); }
	;

ftcexpr_multiplicative_expression
	: ftcexpr_cast_expression { $$ = $1; }
	| ftcexpr_multiplicative_expression '*' ftcexpr_unary_expression { $$ = FTCEXPR_DRV().mul($1,$3); }
	| ftcexpr_multiplicative_expression '/' ftcexpr_unary_expression { $$ = FTCEXPR_DRV().div($1,$3); }
	| ftcexpr_multiplicative_expression '%' ftcexpr_unary_expression { $$ = FTCEXPR_DRV().mod($1,$3); }
	;

ftcexpr_additive_expression
	: ftcexpr_multiplicative_expression { $$ = $1; }
	| ftcexpr_additive_expression '+' ftcexpr_multiplicative_expression { $$ = FTCEXPR_DRV().add($1,$3); }
	| ftcexpr_additive_expression '-' ftcexpr_multiplicative_expression { $$ = FTCEXPR_DRV().sub($1,$3); }
	;

ftcexpr_shift_expression
	: ftcexpr_additive_expression { $$ = $1; }
	| ftcexpr_shift_expression ftcexpr_LEFT_OP ftcexpr_additive_expression { $$ = FTCEXPR_DRV().shl($1,$3); }
	| ftcexpr_shift_expression ftcexpr_RIGHT_OP ftcexpr_additive_expression { $$ = FTCEXPR_DRV().shr($1,$3); }
	;

ftcexpr_relational_expression
	: ftcexpr_shift_expression { $$ = $1; }
	| ftcexpr_relational_expression '<' ftcexpr_shift_expression { $$ = FTCEXPR_DRV().less($1,$3); }
	| ftcexpr_relational_expression '>' ftcexpr_shift_expression { $$ = FTCEXPR_DRV().greater($1,$3); }
	| ftcexpr_relational_expression ftcexpr_LE_OP ftcexpr_shift_expression { $$ = FTCEXPR_DRV().less_eq($1,$3); }
	| ftcexpr_relational_expression ftcexpr_GE_OP ftcexpr_shift_expression { $$ = FTCEXPR_DRV().greater_eq($1,$3); }
	;

ftcexpr_equality_expression
	: ftcexpr_relational_expression { $$ = $1; }
	| ftcexpr_equality_expression ftcexpr_EQ_OP ftcexpr_relational_expression { $$ = FTCEXPR_DRV().eq($1,$3); }
	| ftcexpr_equality_expression ftcexpr_NE_OP ftcexpr_relational_expression { $$ = FTCEXPR_DRV().neq($1,$3); }
	;

ftcexpr_and_expression
	: ftcexpr_equality_expression { $$ = $1; }
	| ftcexpr_and_expression '&' ftcexpr_equality_expression { $$ = FTCEXPR_DRV().bitwand($1,$3); }
	;

ftcexpr_exclusive_or_expression
	: ftcexpr_and_expression { $$ = $1; }
	| ftcexpr_exclusive_or_expression '^' ftcexpr_and_expression { $$ = FTCEXPR_DRV().exor($1,$3); }
	;

ftcexpr_inclusive_or_expression
	: ftcexpr_exclusive_or_expression { $$ = $1; }
	| ftcexpr_inclusive_or_expression '|' ftcexpr_exclusive_or_expression { $$ = FTCEXPR_DRV().bitwor($1,$3); }
	;

ftcexpr_logical_and_expression
	: ftcexpr_inclusive_or_expression { $$ = $1; }
	| ftcexpr_logical_and_expression ftcexpr_AND_OP ftcexpr_inclusive_or_expression {
		$$ = FTCEXPR_DRV().logcand($1,$3);
	};

ftcexpr_logical_or_expression
	: ftcexpr_logical_and_expression { $$ = $1; }
	| ftcexpr_logical_or_expression ftcexpr_OR_OP ftcexpr_logical_and_expression { $$ = FTCEXPR_DRV().logcor($1,$3); }
	;

ftcexpr_conditional_expression
	: ftcexpr_logical_or_expression { $$ = $1; }
	| ftcexpr_logical_or_expression '?' ftcexpr_expression ':' ftcexpr_conditional_expression {
		$$ = FTCEXPR_DRV().if_then_else($1,$3,$5);
	};

ftcexpr_expression: ftcexpr_conditional_expression { $$ = $1; }



%%

void ftcexpr::parser::error(ftcexpr::location const &loc, std::string const &msg) {
	throw ftcexpr::parser::syntax_error(loc, msg);
}

