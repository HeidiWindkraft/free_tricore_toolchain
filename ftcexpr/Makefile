
.PHONY: all

all: ftcexpr

ftcexpr: ftcexpr_yacc.c ftcexpr_lex.c
	gcc ftcexpr.c ftcexpr_lex.c -o ftcexpr

ftcexpr.c: ftcexpr.yacc
	bison --output=ftcexpr_yacc.c ftcexpr.yacc

ftcexpr.yacc: ftcexpr.yacc.m4 ftcexpr_rules.yacc
	m4 ftcexpr.yacc.m4 > ftcexpr.yacc

ftcexpr_lex.c: ftcexpr.lex
	flex --output=ftcexpr_lex.c