/* The parser driver of the ftcexpr demo.
 *
 * See also: https://www.gnu.org/software/bison/manual/html_node/A-Complete-C_002b_002b-Example.html#A-Complete-C_002b_002b-Example
 *
 * License: GNU GPL 3, see LICENSE file.
*/
#include "ftcexpr_demo_driver.hxx"
#include <string>

namespace ftcexpr_demo {

Driver::Driver() {
	/* - */
}

int Driver::parse_cstring(const char *string)
{
	static const std::string scstr("cstring");
	this->location.initialize(&scstr);
	this->scan_begin();
	yy::parser parse(*this);
	parse.set_debug_level(false);
	int res = parse();
	this->scan_end();
	return res;
}

void Driver::scan_begin(void) {
	/* - */
}
void Driver::scan_end(void) {
	/* - */
}

}

#endif
