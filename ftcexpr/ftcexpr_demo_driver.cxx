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

Driver::Driver() : scanner(create_scanner()), parser(*this, scanner) {
}

int64_t Driver::parse_cstring(const char *cstr)
{
	return this->parse_cstring(cstr, strlen(cstr));
}

int64_t Driver::parse_cstring(const char *cstr, size_t size)
{
	this->location.initialize(nullptr);
	// Allocate the buffer if necessary.
	{
		size_t bufsize = size + 2;
		if (this->line_buffer.capacity() < bufsize) {
			if (bufsize < MIN_BUF_SIZE) {
				bufsize = MIN_BUF_SIZE;
			}
			this->line_buffer.reserve(bufsize);
		}
	}
	// Get the string.
	{
		this->line_buffer.resize(size + 2);
		std::copy(cstr, &cstr[size], this->line_buffer.begin());
		this->line_buffer[size    ] = '\0'; // We need two '\0' terminators.
		this->line_buffer[size + 1] = '\0';
	}
	// Scan and parse.
	this->scan();

	return this->last_result;
}

void Driver::parse_from_scanner() {
	this->parser.set_debug_level(false);
	if (this->parser.parse() != 0) {
		throw std::runtime_error("Parsing failed");
	}
}

int64_t Driver::invalid() {
	throw std::runtime_error("Encountered unsupported operation");
}

enum DriverDemoFuncId {
	FUNC_S16HI = 100,
	FUNC_S16LO,
	FUNC_U16HI,
	FUNC_U16LO,
	FUNC_ABS,
	FUNC_S16EXT,
};

int64_t Driver::demo_getfunc(std::string const &fname) {
	if (fname == "@s16hi") { return FUNC_S16HI; }
	if (fname == "@s16lo") { return FUNC_S16LO; }
	if (fname == "@u16hi") { return FUNC_U16HI; }
	if (fname == "@u16lo") { return FUNC_U16LO; }
	if (fname == "@abs") { return FUNC_ABS; }
	if (fname == "@s16ext") { return FUNC_S16EXT; }
	throw std::runtime_error("Encountered unkown function name");
}

int64_t Driver::call(int64_t func, int64_t arg) {
	uint64_t uarg = (uint64_t)arg;
	int64_t res;
	switch (func) {
		case FUNC_S16HI: {
			uint64_t ures = (uarg >> 16);
			if (uarg & (1u << 16)) {
				ures += 1;
			}
			res = (int64_t)(ures & 0xffffu);
			break;
		}
		case FUNC_U16HI: {
			res = (int64_t)((uarg >> 16) & 0xffffu);
			break;
		}
		case FUNC_S16LO:
		case FUNC_U16LO: {
			res = (int64_t)(uarg & 0xffffu);
			break;
		}
		case FUNC_ABS: {
			res = arg;
			if (res < 0) {
				res = -res;
			}
			break;
		}
		case FUNC_S16EXT: {
			res = (int64_t)(int16_t)arg;
			break;
		}
		default:
			throw std::runtime_error("Encountered unkown function index");
	}
	return res;
}

}
