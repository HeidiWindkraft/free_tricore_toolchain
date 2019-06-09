
.PHONY: all clean_gen

all: ftcexpr

YACC_CXX=ftcexpr_yacc.gen.cxx
YACC_DEFINES=ftcexpr_yacc_defines.gen.hxx
YACC_LOCATION=location.hh
LEX_CXX=ftcexpr_lex.gen.cxx
LEX_HXX=ftcexpr_lex.gen.hxx
PREPROC_YACC=ftcexpr.gen.yacc

ftcexpr: $(YACC_CXX) $(LEX_CXX) $(YACC_DEFINES) $(YACC_LOCATION) $(LEX_HXX)
	gcc $(YACC_CXX) $(LEX_CXX) -o $@

$(YACC_CXX): $(PREPROC_YACC)
	bison --output=$@ --defines=$(YACC_DEFINES) $^

$(PREPROC_YACC): ftcexpr.yacc.m4 ftcexpr_rules.yacc ftcexpr_rule_types.yacc
	m4 ftcexpr.yacc.m4 > $@

$(LEX_HXX): $(LEX_CXX)
$(LEX_CXX): ftcexpr.lex
	flex --outfile=$@ --header-file=$(LEX_HXX) $^

clean_gen:
	rm -f $(PREPROC_YACC)
	rm -f $(YACC_CXX)
	rm -f $(YACC_DEFINES)
	rm -f $(YACC_LOCATION)
	rm -f $(LEX_CXX)
	rm -f $(LEX_HXX)
