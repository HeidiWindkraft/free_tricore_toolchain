/* The parser driver of the ftcexpr demo.
 *
 * See also: https://www.gnu.org/software/bison/manual/html_node/A-Complete-C_002b_002b-Example.html#A-Complete-C_002b_002b-Example
 *
 * License: GNU GPL 3, see LICENSE file.
*/
#ifndef FTCEXPR_DEMO_DRIVER_HXX
#define FTCEXPR_DEMO_DRIVER_HXX 1

#include "ftcexpr_demo_parser.hxx"
#include <stdint.h>
#include <vector>

namespace ftcexpr_demo {

class Driver {
public:
	int64_t result;

	// The current string
	const char *cur_string;
	size_t cur_string_size;

	// The token's location used by the scanner.
	ftcexpr::location location;

	// The scanner and the line buffer
	void *scanner;
	std::vector<char> line_buffer;

	// The parser
	// ftcexpr::parser
	

public:
	Driver();
	// Parse a string.
	int parse_cstring(const char *);
	int parse_cstring(const char *, cur_string_size);
	// Handling the scanner.
	void scan_begin();
	void scan_end();
};

}

// Give Flex the prototype of yylex we want ...
# define YY_DECL \
  ftcexpr::parser::symbol_type yylex (ftcexpr_demo::Driver& drv)
// ... and declare it for the parser's sake.
YY_DECL;

#endif
