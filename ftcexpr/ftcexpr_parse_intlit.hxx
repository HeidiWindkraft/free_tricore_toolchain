/* Integer literal parsing function.
 *
 * GPL v3
*/

#ifndef FTCEXPR_PARSE_INTLIT_H
#define FTCEXPR_PARSE_INTLIT_H 1

#include <cstring>
#include <cstdint>

namespace ftcexpr {

struct IntLit {
	enum Flags : uint32_t {
		NO_FLAGS    = 0u,
		INITIALIZED = 1u << 0u,
		PARSE_ERROR = 1u << 1u,
		U           = 1u << 2u,
		L           = 1u << 3u,
		LL          = 1u << 4u,
	};
	enum ErrorCode : int {
		NO_ERROR = 0,
		UNKNOWN_ERROR,
		NO_DIGITS,
		INVALID_RADIX,
		INVALID_DIGIT,
		DIGIT_OUT_OF_RANGE,
		OVERFLOW_ERROR
	};
	uint64_t value;
	int radix;
	Flags flags;

	void add_flag(Flags fs) {
		flags = Flags(flags | fs);
	}

	IntLit &set_error(ErrorCode err) {
		add_flag(PARSE_ERROR);
		radix = -err;
		return *this;
	}
	ErrorCode get_error() const {
		if (flags & PARSE_ERROR) {
			return ErrorCode(-radix);
		} else {
			return NO_ERROR;
		}
	}
};

IntLit parse_intlit(const char *cstr_data, std::size_t cstr_size);

template <typename CONTAINER>
inline IntLit parse_intlit(CONTAINER const &c) {
	return parse_intlit(c.data(), c.size());
}

}

#endif