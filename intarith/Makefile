
.PHONY: all

all: intarith

intarith: intarith_yacc.c intarith_lex.c
	gcc intarith.c intarith_lex.c -o intarith

intarith.c: intarith.yacc
	bison --output=intarith_yacc.c intarith.yacc

intarith.yacc: intarith.yacc.m4 intarith_rules.yacc
	m4 intarith.yacc.m4 > intarith.yacc

intarith_lex.c: intarith.lex
	flex --output=intarith_lex.c