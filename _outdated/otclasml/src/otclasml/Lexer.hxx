/* $Id$
 * (L)
*/
#ifndef OTCLASML_LEXER_HXX
#define OTCLASML_LEXER_HXX 1

#include <otclasml/StringView.hxx>

/* Lexer for a simple line-based white-space-separated language.
*/
namespace otclasml { namespace {

namespace Lexing {
	typedef const char *ccharit;

	ccharit findEndOfStringLiteral(ccharit begin, ccharit end) {
		for (ccharit it = begin; it != end; ++it) {
			if (*it != '"') continue;
			// found a '"', check whether it is escaped...
			unsigned backslashCount = 0;
			for (ccharit jt = it - 1; jt >= begin; --jt) {
				if (*jt == '\\') {
					++backslashCount;
				} else {
					break;
				}
			}
			if ((backslashCount & 1) == 1) {
				return it;
			}
		}
		return end; // found no end of string literal.
	}

	bool isComment(ccharit it, ccharit begin, ccharit end) {
		// This could be a comment.
		// Check that this '/' isn't part of a token, since this language is whitespace-separated.
		ccharit next = it + 1, before = it - 1;
		return (*it == '/') && (
			((it == begin) || (std::isspace(*before)))
				&& ((next != end) && (*next == '/'))
		);
	}

	void findEndOfLine(ccharit begin, ccharit end, ccharit &eol, ccharit &next) {
		for (ccharit it = begin; it != end; ++it) {
			char c = *it;
			switch (c) {
			case '\n':
				// Newlines can't be escaped in this language (without preprocessor).
				// '\r' is not allowed in this language.
				eol = it;
				if (it != end) {
					next = it + 1;
				} else {
					next = end;
				}
				return;
			case '"':
				// Found begin of string.
				// Decrement it by 1, because for loop will increment it again.
				it = findEndOfStringLiteral(it + 1, end) - 1;
				break;
			case '/': {
				// This could be a comment.
				if (isComment(it, begin, end)) {
					eol = it;
					// Now find the actual end of line:
					ccharit jt;
					for (jt = it + 2; jt != end; ++jt) {
						if (*jt == '\n') {
							++jt;
							break;
						}
					}
					next = jt;
					return;
				}
				break;
			}
			default:
				// skip ...
				;
			}
		}
		// EOF is end of line.
		eol = end;
		next = end;
	}

	typedef StringView Token;
}

class LineLexer {
public:
	typedef Lexing::Token Token;

private:
	typedef Lexing::ccharit ccharit;
	StringView mAll;
	ccharit    mCur;

private:
	void skipSpaceAndComment() {
		using namespace Lexing;
		for (; mCur != ccend(mAll); ++mCur) {
			if (!std::isspace(*mCur)) {
				if (isComment(mCur, mCur, ccend(mAll))) {
					mCur = ccend(mAll);
				}
				break;
			}
		}
	}
	void adjustAfterReset() {
		using namespace Lexing;
		// Skip leading whitespace.
		mCur = ccbegin(mAll);
		skipSpaceAndComment();
	}
	void munchNonSpace() {
		using namespace Lexing;
		for (; mCur != ccend(mAll); ++mCur) {
			if (std::isspace(*mCur)) {
				break;
			}
		}
	}

public:
	void resetView(StringView sv) {
		mAll = sv;
		adjustAfterReset();
	}

public:
	bool hasNext() const {
		return mCur != ccend(mAll);
	}
	bool getNext(Token &tok) {
		using namespace Lexing;
		if (!hasNext()) {
			tok = StringView(nullptr, 0);
			return false;
		}
		ccharit begin = mCur;
		char c = *mCur;
		switch (c) {
		case '"': {
			mCur = findEndOfStringLiteral(mCur, ccend(mAll));
			// continue parsing the suffix...
			break;
		}
		default:
			// nothing special to do...
			;
		}
		// Advance iterator until there's whitespace.
		munchNonSpace();
		tok = StringView(begin, (mCur - begin));
		// Find begin of next token.
		skipSpaceAndComment();
		return true;
	}
	StringView getRemaining() const {
		return StringView(mCur, ccend(mAll) - mCur);
	}
	StringView getAll() const {
		return mAll;
	}
};

class Lexer {
public:
	typedef Lexing::Token Token;

private:
	typedef Lexing::ccharit ccharit;
	StringView mAll;
	ccharit    mCur;

public:
	Lexer() : mAll(nullptr, 0), mCur(nullptr) {}
	Lexer(Lexer const &r) = default;
	Lexer(Lexer &&r) : mAll(r.mAll), mCur(r.mCur) {}
	explicit Lexer(StringView strv) {
		resetView(strv);
	}

public:
	bool eof() const {
		return mCur == ccend(mAll);
	}
	bool nextLine(LineLexer &ll) {
		using namespace Lexing;
		if (eof()) {
			return false;
		}
		ccharit eol, next;
		findEndOfLine(mCur, ccend(mAll), eol, next);
		StringView sw(mCur, (eol - mCur));
		mCur = next;
		ll.resetView(sw);
		return true;
	}

public:
	void resetView(StringView strv) {
		mAll = strv;
		mCur = ccbegin(mAll);
	}
};

} }

#endif /* _HXX */

