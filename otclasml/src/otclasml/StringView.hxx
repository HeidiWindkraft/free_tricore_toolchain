/* $Id$
 * (L)
*/
#ifndef OTCLASML_STRINGVIEW_HXX
#define OTCLASML_STRINGVIEW_HXX 1

//#include <cinttypes>
//#include <array>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <boost/utility/string_view.hpp>

#define OTCLASML_STRINGVIEW_DETAIL_GETSTRTONUM(INT, FUNC) \
	template <> struct GetStrToNum<INT> { static inline INT conv(const char *str, char **endptr, int base) { return FUNC(str, endptr, base); } }
	

namespace otclasml { namespace {

typedef boost::string_view StringView;

const char *ccbegin(StringView sv) { return &*sv.cbegin(); }
const char *ccend(StringView sv) { return &*sv.cend(); }


namespace detail {
	template <typename T> struct GetStrToNum;
	OTCLASML_STRINGVIEW_DETAIL_GETSTRTONUM(long, strtol);
	OTCLASML_STRINGVIEW_DETAIL_GETSTRTONUM(long long, strtoll);
	OTCLASML_STRINGVIEW_DETAIL_GETSTRTONUM(unsigned long, strtoul);
	OTCLASML_STRINGVIEW_DETAIL_GETSTRTONUM(unsigned long long, strtoull);
	
}

enum StringView_toInt_error_e {
	StringView_toInt_UNKNOWN_ERROR = -1000,
	StringView_toInt_EMPTY_STRING  = -1001,
	StringView_toInt_LIMIT         = -1002,
};

StringView::const_iterator getFirstNonSpaceConstIter(StringView str) {
	StringView::const_iterator it  = str.begin(),
	                           end = str.end();
	for (; it != end; ++it) {
		if (!std::isspace(*it)) {
			break;
		}
	}
	return it;
}

/* Converts a StringView to an integer.
 * A non-zero return value indicates that this function couldn't process the whole string.
 *   - If the result value is negative, an error occured before actually parsing the string.
 *   - If the result value is positive, it is the number of characters which couldn't be
 *     parsed (counting from the end of the string).
*/
template <typename INT>
int tryToInt(StringView str, int radix, INT &out) {
	/* Maximum literal/buffer size:
	 *  -: skip whitespace
	 *  1: sign +/-
	 *  2: prefix
	 * 64: digits, std::numeric_limits<INT>::digits
	 *  1: '\0' delimiter
	*/
	enum constants_e {
		BUFSIZE = 1 + 2 + std::numeric_limits<INT>::digits + 1
	};
	char buf[BUFSIZE];
	if (str.empty()) {
		return StringView_toInt_EMPTY_STRING;
	}
	StringView::const_iterator it  = getFirstNonSpaceConstIter(str.begin()),
	                           end = str.end();
	if ((end - it) >= (BUFSIZE-1)) {
		// TODO count the actual number of digits - underscores don't count.
		return StringView_toInt_LIMIT;
	}
	// TODO don't copy underscores.
	char *bufend = std::copy(it, end, &buf[0]);
	*bufend = '\0';
	if (bufend == buf) {
		return StringView_toInt_EMPTY_STRING;
	}
	char *endptr = bufend;
	out = detail::GetStrToNum<INT>::conv(buf, &endptr, radix);
	return bufend - endptr;
}

class StringViewToIntException : std::invalid_argument {
	int mReturnValue;
public:
	StringViewToIntException(int returnValue) : std::invalid_argument("StringViewToIntException"), mReturnValue(returnValue) {}
	int getReturnValue() const { return mReturnValue; }
};

template <typename INT>
INT toInt(StringView str, int radix = 0) {
	INT out = 0;
	int ret = tryToInt(str, radix, out);
	if (ret != 0) {
		throw StringViewToIntException(ret);
	}
	return out;
}

uint64_t toUInt64(StringView str, int radix = 0) {
	return toInt<uint64_t>(str, radix);
}

namespace getIntRadixErrors {
	enum values {
		NOT_A_NUMBER = -1,
		NOT_ENOUGH_DIGITS = -2,
		ILLEGAL_CHARACTER_LE10 = -3,
		ILLEGAL_CHARACTER_GT10 = -4,
		UNKNOWN_RADIX = -5
	};
}

// Returns the integer base of a token.
// Returns a negative number if the token isn't an integer.
int getIntRadix(StringView tok) {
	if (tok.size() == 0) {
		return getIntRadixErrors::NOT_A_NUMBER;
	}
	char f = tok[0];
	if (('0' > f) || (f > '9')) {
		return getIntRadixErrors::NOT_A_NUMBER;
	}
	if (tok.size() < 2) {
		return 10; // This is a decimal number (0 here also is a decimal number).
	}
	char s = std::tolower(tok[1]);
	int radix = -1;
	if (f == '0') {
		switch (s) {
		case 'b': radix =  2; break;
		case 'o': radix =  8; break;
		case 'x': radix = 16; break;
		}
	}
	if ((radix == -1) && std::isdigit(s)) {
		radix = 10;
	}
	if (radix == -1) {
		return getIntRadixErrors::UNKNOWN_RADIX;
	}
	if ((radix != 10) && (tok.size() < 3)) {
		return getIntRadixErrors::NOT_ENOUGH_DIGITS;
	}
	StringView::const_iterator begin, end;
	begin = tok.begin();
	end = tok.end();
	if (radix != 10) {
		begin += 2;
	}
	if (radix <= 10) {
		for (StringView::const_iterator it = begin; it < end; ++it) {
			char c = *it;
			unsigned val = c - '0';
			if ((val >= (unsigned)radix) && (c != '_')) {
				return getIntRadixErrors::ILLEGAL_CHARACTER_LE10;
			}
		}
	} else {
		for (StringView::const_iterator it = begin; it < end; ++it) {
			char c = std::tolower(*it);
			bool valid = std::isdigit(c) || (('a' <= c) && (c <= 'f')) || (c == '_');
			if (!valid) {
				return getIntRadixErrors::ILLEGAL_CHARACTER_GT10;
			}
		}
	}
	return radix;
}

#if 0
template <class TA, class TB>
int compareTransformed(StringView sva, StringView svb, TA ta, TB tb) {
	uintptr_t n = std::min(sva.size(), svb.size());
	const char *da = sva.data();
	const char *db = svb.data();
	for (uintptr_t i = 0; i < n; ++i) {
		uintptr_t ca = (uintptr_t) ta(da[i]),
		          cb = (uintptr_t) tb(db[i]);
		if (ca < cb) return -1;
		if (ca > cb) return 1;
	}
	if (sva.size() == svb.size()) return 0;
	if (sva.size() < svb.size()) return -1;
	return 1;
}

int compareI(StringView a, StringView b) {
	auto lc = [](char c) { return std::tolower(c); };
	return compareTransformed(a, b, lc, lc);
}
#endif


} }

#endif /* _HXX */

