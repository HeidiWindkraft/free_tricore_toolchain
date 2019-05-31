
.PHONY: all parser

all:
	# Compile everything

gparser: src/gparser/ftctasm_lex.c src/gparser/ftctasm_yacc.c

src/gparser/ftctasm_lex.c: ftcasm.c.lex
	mkdir -p src/gparser/
	mkdir -p include/ftct/private/gparser/
	flex --outfile=src/gparser/ftctasm_lex.c --header-file=include/ftct/private/gparser/ftctasm_lex.h ftcasm.c.lex

src/gparser/ftctasm_yacc.c: ftcasm.c.yacc
	mkdir -p src/gparser/
	mkdir -p include/ftct/private/gparser/
	bison ftcasm.c.yacc
	lex --outfile src/gparser/ftctasm_lex.c ftcasm.c.lex
