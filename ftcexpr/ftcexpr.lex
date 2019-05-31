%{ /* -*- C++ -*- */
#include "ftcexpr_demo_driver.hxx"
#include "ftcexpr_demo_parser.hxx"
#include <string>
%}

%option noyywrap nounput noinput batch debug

id      [a-zA-Z_][a-zA-Z0-9_\.]+
intlit	([0-9][0-9'_]*|0[xX][0-9a-fA-F_']+|0o[0-7_']+)[ulUL]*
blank   [ \t\r]

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv.location;
  // Code run each time yylex is called.
  loc.step ();
%}

{blank}+            { loc.step(); }
\n                  { loc.lines(yyleng); loc.step(); }
[-+*/%()<>[]&?:]    { return yy::parser::symbol_type(yytext[0], loc); }
"=="                { return yy::parser::make_EQ_OP(loc); }
"!="                { return yy::parser::make_NE_OP(loc); }
"<<"                { return yy::parser::make_LEFT_OP(loc); }
">>"                { return yy::parser::make_RIGHT_OP(loc); }
"<="                { return yy::parser::make_LE_OP(loc); }
">="                { return yy::parser::make_GE_OP(loc); }
"&&"                { return yy::parser::make_AND_OP(loc); }
"||"                { return yy::parser::make_OR_OP(loc); }
{id}                { return yy::parser::make_IDENTIFIER (yytext, loc); }
{intlit}            { return yy::parser::make_INTLIT(yytext, loc); }
.                   { throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext)); }
<<EOF>>             { return yy::parser::make_END (loc); }
%%

// TODO actually we only want to parse single lines.
void Driver::scan_begin(void)
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror(errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void Driver::scan_end(void)
{
  fclose (yyin);
}
