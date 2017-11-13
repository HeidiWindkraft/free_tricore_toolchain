/* $Id$
 * (L)
*/
#ifndef OTCLASM_TOKENS_HXX
#define OTCLASM_TOKENS_HXX 1

#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <sstream>

namespace otclasm { namespace {

typedef std::string			token_t, line_t;
typedef std::istream		istream_t;
typedef std::stringstream	line_stream_t;

typedef token_t const &token_in;
typedef line_t const &line_in;

void nextLine(istream_t &i, line_t &line) {
	std::getline(i, line);
}
void getStreamFromLine(line_t &line, line_stream_t &stream) {
	stream = std::stringstream(line);
}
void nextToken(istream_t &i, token_t &tok) {
	i >> tok;
}

namespace getIntRadixErrors {
	enum values {
		NAN = -1,	// Not a number.
		NOT_ENOUGH_DIGITS = -2,
		ILLEGAL_CHARACTER_LE10 = -3,
		ILLEGAL_CHARACTER_GT10 = -4,
		UNKNOWN_RADIX = -5
		
	};
}

// Returns the integer base of a token.
// Returns a negative number if the token isn't an integer.
int getIntRadix(token_in tok) {
	if (tok.size() == 0) {
		return getIntRadixErrors::NAN; // Not a number.
	}
	char f = tok[0];
	if (('0' > f) || (f > '9')) {
		return getIntRadixErrors::NAN; // Not a number.
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
	token_t::const_iterator begin, end;
	begin = tok.begin();
	end = tok.end();
	if (radix != 10) {
		begin += 2;
	}
	if (radix <= 10) {
		for (token_t::const_iterator it = begin; it < end; ++it) {
			char c = *it;
			unsigned val = c - '0';
			if ((val >= (unsigned)radix) && (c != '_')) {
				return getIntRadixErrors::ILLEGAL_CHARACTER_LE10;
			}
		}
	} else {
		for (token_t::const_iterator it = begin; it < end; ++it) {
			char c = std::tolower(*it);
			bool valid = std::isdigit(c) || (('a' <= c) && (c <= 'f')) || (c == '_');
			if (!valid) {
				return getIntRadixErrors::ILLEGAL_CHARACTER_GT10;
			}
		}
	}
	return radix;
}

// Here we actually just call strtoull ...
// This function assumes that tok was already checked for validity by getIntRadix.
uint64_t getInt(token_in tok, int radix) {
	uint64_t res;
	std::size_t pos;
	pos = 0;
	if ((tok.size() > 2) && (radix != 10)) {
		pos = 2;
	}
	std::string localCopy;
	const char *cstr = tok.c_str();
	const char *cstrEnd = cstr + tok.size();
	if (tok.find('_') == token_t::npos) {
		// TODO: Actually we can limit the size and allocate a char array on stack.
		localCopy.reserve(tok.size());
		for (char c : tok) {
			if (c != '_') {
				localCopy.push_back(c);
			}
		}
		cstr = localCopy.c_str();
		cstrEnd = cstr + localCopy.size();
	}
	const char *cstrBegin = cstr + pos;
	char *cstrEndRes = nullptr;
	res = std::strtoull(cstrBegin, &cstrEndRes, radix);
	if (cstrEndRes != cstrEnd) {
		throw std::invalid_argument("Couldn't parse entire token.");
	}
	return res;
}


}}

#endif /* _HXX */

