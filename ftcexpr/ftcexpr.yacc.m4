%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.4"
%defines

%define api.token.constructor
%define api.value.type {int64_t}
%define parse.assert

// This code needs to know the driver object.
// Avoid circular dependencies using forward declarations.
%code requires {
#include "ftcexpr_demo_driver_fwd.hxx"
}

// The parsing context.
%param { ftcexpr_demo::Driver& drv }

// Track locations.
%locations

%define parse.trace
%define parse.error verbose

%code {
#include "ftcexpr_demo_driver.hxx"
}

%define api.token.prefix {TOK_}

// Tokens
%token <std::string> INTLITERAL
%token <std::string> IDENTIFIER
%token NEVER_TOKEN_MACC
%token NEVER_TOKEN_INC_OP
%token NEVER_TOKEN_DEC_OP
%token NEVER_TOKEN_ADDRESSOF
%token NEVER_TOKEN_DEREFER
%token NEVER_TOKEN_TYPE
%token LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP

%printer { yyo << $$; } <*>;

%%

%start input

include(`intarith_rules.yacc')

input: | ftcexpr_expression { printf("%" PRId64 "\n", $1); };

ftcexpr_primary_leaf_expression
	: INTLITERAL { $$ = ftcexpr_parse_intlit(yytext); }
	| IDENTIFIER { $$ = demo_getfunc(yytext); }
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


%%

/*int main(int argc, char **argv) {
	if (argc < 2) {
		return 1;
	} else {
		yyscan_t scanner;
		YY_BUFFER_STATE buf;

		yylex_init(&scanner);
		buf = yy_scan_string(argv[1], scanner);
		yylex(scanner);
		yylex_destroy(scanner)

		return 0;
	}
}*/

