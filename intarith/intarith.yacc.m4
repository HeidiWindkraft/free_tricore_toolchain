%{
#include "intarith.h"
%}

%start input 

%token INTLITERAL
%token IDENTIFIER 
%token NEVER_TOKEN

%define api.value.type {int64_t}

%%

include(`intarith_rules.yacc')

input: | ftct_intarith_expression { printf("%" PRId64 "\n", $1); };

ftct_intarith_primary_leaf_expression
	: INTLITERAL { $$ = ftct_intarith_parse_intlit(yytext); }
	| IDENTIFIER { $$ = ftct_intarith_getfunc(yytext); }
	;

%%

int main(int argc, char **argv) {
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
}

