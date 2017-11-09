/* $Id$
 * (L)
*/
#ifndef OTCLASM_STRINGVIEW_HXX
#define OTCLASM_STRINGVIEW_HXX 1

//#include <cinttypes>
//#include <array>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <boost/utility/string_view.hpp>

#define OTCLASM_STRINGVIEW_DETAIL_GETSTRTONUM(INT, FUNC) \
	template <> struct GetStrToNum<INT> { static inline INT conv(const char *str, char **endptr, int base) { return FUNC(str, endptr, base); } }
	

namespace otclasm { namespace {

typedef boost::string_view StringView;

namespace detail {
	template <typename T> struct GetStrToNum;
	OTCLASM_STRINGVIEW_DETAIL_GETSTRTONUM(long, strtol);
	OTCLASM_STRINGVIEW_DETAIL_GETSTRTONUM(long long, strtoll);
	OTCLASM_STRINGVIEW_DETAIL_GETSTRTONUM(unsigned long, strtoul);
	OTCLASM_STRINGVIEW_DETAIL_GETSTRTONUM(unsigned long long, strtoull);
	
}

enum StringView_toInt_error_e {
	StringView_toInt_UNKNOWN_ERROR = -1000;
	StringView_toInt_EMPTY_STRING  = -1001;
	StringView_toInt_LIMIT         = -1002;
	
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
	StringView::const_iterator it  = getFirstNonSpaceConstIter(it),
	                           end = str.end();
	if ((end - it) >= (BUFSIZE-1)) {
		return StringView_toInt_LIMIT;
	}
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
	StringViewToIntException(int returnValue) : mReturnValue(returnValue) {}
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


} }

#endif /* _HXX */

