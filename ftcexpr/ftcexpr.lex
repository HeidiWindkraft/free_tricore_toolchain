%{ /* -*- C++ -*- */
#include "ftcexpr_demo_driver.hxx"
#include <string>
%}

%option noyywrap nounput noinput batch debug
%option reentrant
%option prefix="ftcexpr_"

id          [a-zA-Z_\.@][a-zA-Z0-9_\.@]+
intlit      (0|[1-9][0-9'_]*|0[xX][0-9a-fA-F_']+|0[oO][0-7_']+|0[bB][01_']+)[ulUL]*
blank       [ \t\r]
operator    [\-\+\*\/\%\(\)\<\>\[\]\&\?\:]

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
  // A handy shortcut to the location held by the driver.
  ftcexpr::location& loc = drv.location;
  // Code run each time yylex is called.
  loc.step ();
%}

{blank}+            { loc.step(); }
\n                  { loc.lines(yyleng); loc.step(); }
{operator}          { return ftcexpr::parser::symbol_type(yytext[0], loc); }
"=="                { return ftcexpr::parser::make_EQ_OP(loc); }
"!="                { return ftcexpr::parser::make_NE_OP(loc); }
"<<"                { return ftcexpr::parser::make_LEFT_OP(loc); }
">>"                { return ftcexpr::parser::make_RIGHT_OP(loc); }
"<="                { return ftcexpr::parser::make_LE_OP(loc); }
">="                { return ftcexpr::parser::make_GE_OP(loc); }
"&&"                { return ftcexpr::parser::make_AND_OP(loc); }
"||"                { return ftcexpr::parser::make_OR_OP(loc); }
{id}                { return ftcexpr::parser::make_IDENTIFIER(yytext, loc); }
{intlit}            { return ftcexpr::parser::make_INTLITERAL(yytext, loc); }
.                   { throw ftcexpr::parser::syntax_error(loc, "invalid character: " + std::string(yytext)); }
<<EOF>>             { return ftcexpr::parser::make_END(loc); }
%%


void *ftcexpr_demo::Driver::create_scanner() {
	void *scanner = nullptr;
	if (ftcexpr_lex_init(&scanner) != 0) {
		throw std::runtime_error("Failed to initialize scanner");
	}
	return scanner;
}

// TODO actually we only want to parse single lines.
// TODO yy_scan_bytes (alocates) or yy_scan_buffer (needs \0\0 terminator and mutable memory)
// TODO yylex_destroy --yypush_buffer_state yypop_buffer_state yy_delete_buffer
void ftcexpr_demo::Driver::scan(void)
{
	if (!scanner) {
		throw std::runtime_error("Scanner not initialized");
	}

	YY_BUFFER_STATE bufst;

	bufst = ftcexpr__scan_buffer(line_buffer.data(), line_buffer.size(), scanner);

	parse_from_scanner(); // if this throws an exception scan_destroy will delete the buffer.

	ftcexpr__delete_buffer(bufst, scanner);
}

void ftcexpr_demo::Driver::scan_destroy(void)
{
	if (scanner) {
		if (ftcexpr_lex_destroy(scanner) != 0) {
			throw std::runtime_error("Failed to destroy scanner");
		}
		scanner = nullptr;
	}
}

