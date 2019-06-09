/* Integer literal parsing function.
 *
 * GPL v3
*/

#include "ftcexpr_parse_intlit.hxx"
#include <cctype>
#include <algorithm>

namespace ftcexpr {

IntLit parse_intlit(const char *cstr_data, std::size_t cstr_size) {
	using namespace std;

	IntLit res;
	res.radix = -IntLit::UNKNOWN_ERROR;
	res.value = ~(uint64_t)0;
	res.flags = IntLit::NO_FLAGS;

	const char *it = cstr_data;
	const char *end = cstr_data + cstr_size;
	const char *suf;

	suf = end;
	// Get the start of the suffix.
	for (;;) {
		if (suf == it) {
			// Apparently the string only consists of suffixes or is empty.
			return res.set_error(IntLit::NO_DIGITS);
		}
		char c = tolower(*(suf - 1));
		if ((c == 'u') || (c == 'l')) {
			--suf;
		} else {
			break;
		}
	}
	// Search for suffixes.
	const char *ll = "ll";
	if (search(suf,end,ll,ll+2, [](char a, char b) { return tolower(a) == b; } ) != end) {
		res.add_flag(IntLit::LL);
	} else if (find_if(suf,end, [](char c) { return tolower(c) == 'l'; }) != end) {
		res.add_flag(IntLit::L);
	} else {
		// There's neither an LL- nor L-suffix.
	}
	if (find_if(suf,end, [](char c) { return tolower(c) == 'u'; }) != end) {
		res.add_flag(IntLit::U);
	}

	// Get the radix.
	if (it[0] == '0') {
		// Only "0", "0[xX]...", "0[oO]..." and "0[bB]..." are allowed.
		if ((it + 1) == suf) {
			res.radix = 8;
			res.value = 0;
			res.add_flag(IntLit::INITIALIZED);
			return res;
		} else {
			char second = tolower(it[1]);
			switch (second) {
				case 'x': res.radix = 0x10; break;
				case 'o': res.radix = 010; break;
				case 'b': res.radix = 0b10; break;
				default:
					return res.set_error(IntLit::INVALID_RADIX);
			}
			it += 2;
		}
	} else {
		res.radix = 10;
	}
	unsigned radix = (unsigned) res.radix;

	// Convert the digits.
	res.value = 0;
	for (; it != suf; ++it) {
		char c = *it;
		if ((c == '\'') || (c == '_')) {
			continue;
		}
		unsigned toadd = 0;
		if (('0' <= c) && (c <= '9')) {
			toadd = c - '0';
		} else {
			c = tolower(c);
			if (('a' <= c) && (c <= 'f')) {
				toadd = 10 + (c - 'a');
			} else {
				return res.set_error(IntLit::INVALID_DIGIT);
			}
		}
		if (toadd >= radix) {
			return res.set_error(IntLit::DIGIT_OUT_OF_RANGE);
		}
		uint64_t oldval = res.value;
		res.value *= radix;
		if (res.value < oldval) {
			return res.set_error(IntLit::OVERFLOW_ERROR);
		}
		res.value += toadd;
	}

	res.add_flag(IntLit::INITIALIZED);
	return res;
}

}
