/* The parser driver of the ftcexpr demo.
 *
 * See also: https://www.gnu.org/software/bison/manual/html_node/A-Complete-C_002b_002b-Example.html#A-Complete-C_002b_002b-Example
 *
 * License: GNU GPL 3, see LICENSE file.
*/
#include "ftcexpr_demo_driver.hxx"
#include <string>
#include <string.h>
#include <algorithm>

#define MIN_BUF_SIZE 256u

namespace ftcexpr_demo {

static const std::string scstr("cstring");

Driver::Driver() {
	/* - */
}

int Driver::parse_cstring(const char *cstr)
{
	return this->parse_cstring(cstr, strlen(string));
}

int Driver::parse_cstring(const char *string, size_t size)
{
	this->location.initialize(&scstr);
	size_t bufsize = size + 2;
	if (this->line_buffer.size() < bufsize) {
		if (bufsize < MIN_BUF_SIZE) {
			bufsize = MIN_BUF_SIZE;
		}
		this->line_buffer.resize(size);
	}
	std::copy(cstr, &cstr[size], this->line_buffer.begin());
	cstr[size    ] = '\0'; // We need two '\0' terminators.
	cstr[size + 1] = '\0';

	yyscan_t scanner;

	this->scan_begin(&scanner);
	ftcexpr::parser parse(*this);
	parse.set_debug_level(false);
	int res = parse();
	this->scan_end(scanner);
	return res;
}

}

#endif
