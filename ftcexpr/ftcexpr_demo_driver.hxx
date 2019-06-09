/* The parser driver of the ftcexpr demo.
 *
 * See also: https://www.gnu.org/software/bison/manual/html_node/A-Complete-C_002b_002b-Example.html#A-Complete-C_002b_002b-Example
 *
 * License: GNU GPL 3, see LICENSE file.
*/
#ifndef FTCEXPR_DEMO_DRIVER_HXX
#define FTCEXPR_DEMO_DRIVER_HXX 1

#include "ftcexpr_demo_driver_fwd.hxx"
#include "ftcexpr_yacc_defines.gen.hxx"
#include <vector>

namespace ftcexpr_demo {

class Driver {
public:
	int64_t last_result;

	// The token's location used by the scanner.
	ftcexpr::location location;

	// The scanner and the line buffer
	void *scanner;
	std::vector<char> line_buffer;

	// The parser
	ftcexpr::parser parser;

public:
	Driver();
	// Parse a string.
	int64_t parse_cstring(const char *);
	int64_t parse_cstring(const char *, size_t);

private:
	// Handling the scanner.
	static void *create_scanner();
	void scan();
	void parse_from_scanner();
	void scan_destroy();

public: // Parser rule handling
	int64_t demo_getfunc(std::string const &);
	int64_t subscript(int64_t, int64_t) { return invalid(); }
	int64_t call(int64_t, int64_t);
	int64_t member_access(int64_t, int64_t) { return invalid(); }
	int64_t post_inc(int64_t) { return invalid(); }
	int64_t post_dec(int64_t) { return invalid(); }
	int64_t unary_plus(int64_t v) { return +v; }
	int64_t neg(int64_t v) { return -v; }
	int64_t bitwnot(int64_t v) { return ~v; }
	int64_t logcnot(int64_t v) { return !v; }
	int64_t addressof(int64_t) { return invalid(); }
	int64_t derefer(int64_t) { return invalid(); }
	int64_t pre_inc(int64_t) { return invalid(); }
	int64_t pre_dec(int64_t) { return invalid(); }
	int64_t sizeof_expr(int64_t) { return invalid(); }
	int64_t sizeof_type(int64_t) { return invalid(); }
	int64_t mul(int64_t a, int64_t b) { return a * b; }
	int64_t div(int64_t a, int64_t b) {
		if (b != 0) {
			return a / b;
		} else {
			return (a < 0)? INT64_MIN : INT64_MAX;
		}
	}
	int64_t mod(int64_t a, int64_t b) {
		if (b != 0) {
			return a % b;
		} else {
			return 0;
		}
	}
	int64_t add(int64_t a, int64_t b) { return a + b; }
	int64_t sub(int64_t a, int64_t b) { return a - b; }
	int64_t shl(int64_t a, int64_t b) { return (int64_t)(((uint64_t)a) << b); }
	int64_t shr(int64_t a, int64_t b) { return (int64_t)(((uint64_t)a) >> b); }
	int64_t less(int64_t a, int64_t b) { return a < b; }
	int64_t greater(int64_t a, int64_t b) { return a > b; }
	int64_t less_eq(int64_t a, int64_t b) { return a <= b; }
	int64_t greater_eq(int64_t a, int64_t b) { return a >= b; }
	int64_t eq(int64_t a, int64_t b) { return a == b; }
	int64_t neq(int64_t a, int64_t b) { return a != b; }
	int64_t bitwand(int64_t a, int64_t b) { return a & b; }
	int64_t bitwor(int64_t a, int64_t b) { return a | b; }
	int64_t exor(int64_t a, int64_t b) { return a ^ b; }
	int64_t logcand(int64_t a, int64_t b) { return a && b; }
	int64_t logcor(int64_t a, int64_t b) { return a || b; }
	int64_t if_then_else(int64_t a, int64_t b, int64_t c) { return a?b:c; }


#if 0

#endif

private:
	int64_t invalid();

};

}

// Give Flex the prototype of yylex we want ...
# define YY_DECL \
  ftcexpr::parser::symbol_type ftcexpr_lex (ftcexpr_demo::Driver& drv, void *yyscanner)
// ... and declare it for the parser's sake.
YY_DECL;

#endif
