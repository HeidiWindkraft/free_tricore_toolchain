/* $Id$
 * (L)
*/
#ifndef OTCLASM_TOKENS_HXX
#define OTCLASM_TOKENS_HXX 1

#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

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
		ENAN = -2	// Looks like a number but isn't.
	};
}

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
	switch (x) {
	case 'b': radix =  2; break;
	case 'o': radix =  8; break;
	case 'x': radix = 16; break;
	}
	if ((radix == -1) && std::isdigit(s)) {
		radix = 10;
	}
	if (radix == -1) {
		return getIntRadixErrors::NAN;
	}
	if ((radix != 10) && (tok.size() < 3)) {
		return getIntRadixErrors::ENAN;
	}
	if (radix <= 10) {
		for (char c : tok) {
			if (!std::isdigit(c)) {
				return getIntRadixErrors::ENAN;
			}
		}
	} else {
		token_t::const_iterator it, end;
		end = tok.end();
		for (it = tok.begin() + 1; it < end; ++it) {
			char c = std::tolower(*it);
			bool valid = std::isdigit(c) || (('a' <= c) && (c <= 'f'));
			if (!valid) {
				return getIntRadixErrors::ENAN;
			}
		}
	}
	return radix;
}

uint64_t getInt(token_in tok, int radix) {
	uint64_t res;
	std::size_t pos;
	pos = 0;
	if ((tok.size() > 2) && (radix != 10)) {
		pos = 2;
	}
	res = std::stoull(tok, &pos, radix);
	if (pos != tok.size()) {
		throw std::invalid_argument("Couldn't parse entire token.");
	}
	return res;
}


}}

#endif /* _HXX */

