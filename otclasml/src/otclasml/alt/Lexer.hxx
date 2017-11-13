/* $Id$
 * (L)
*/
#ifndef OTCLASM_LEXER_HXX
#define OTCLASM_LEXER_HXX 1

#include "StringView.hxx"

/* Lexer for a simple line-based white-space-separated language.
*/
namespace otclasm { namespace {

namespace Lexing {
	typedef const char *ccharit;

	ccharit findEndOfStringLiteral(ccharit begin, ccharit end) {
		for (ccharit it = begin; it != end; ++it) {
			if (*it != '"') continue;
			// found a '"', check whether it is escaped...
			unsigned backslashCount = 0;
			for (charit jt = it - 1; jt >= begin; --jt) {
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

	bool isComment(charit it, charit begin, charit end) {
		// This could be a comment.
		// Check that this '/' isn't part of a token, since this language is whitespace-separated.
		charit next = it + 1, before = it - 1;
		return (*it == '/') && (
			((it == begin) || (std::isspace(*before)))
				&& ((next != end) && (*next == '/'))
		);
	}

	void findEndOfLine(ccharit begin, ccharit end, ccharit &eol, charit &next) {
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
					for (ccharit jt = it + 2; jt != end; ++jt) {
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
		for (; mCur != mAll.cend(); ++mCur) {
			if (!std::isspace(*mCur)) {
				if (isComment(mCur, mCur, mAll.cend())) {
					mCur = mAll.cend();
				}
				break;
			}
		}
	}
	void adjustAfterReset() {
		// Skip leading whitespace.
		mCur = mAll.cbegin();
		skipSpaceAndComment();
	}
	void munchNonSpace() {
		for (; mCur != mAll.cend(); ++mCur) {
			if (std::isspace(*mCur)) {
				break;
			}
		}
	}

public:
	bool hasNext() const {
		return mCur != mAll.cend();
	}
	bool getNext(Token &tok) {
		if (!hasNext()) {
			tok = StringView(nullptr, 0);
			return false;
		}
		ccharit begin = mCur;
		char c = *mCur;
		switch (c) {
		case '"': {
			mCur = findEndOfStringLiteral(mCur, mAll.cend());
			// continue parsing the suffix...
			break;
		}
		default:
			// nothing special to do...
		}
		// Advance iterator until there's whitespace.
		munchNonSpace();
		tok = StringView(begin, (mCur - begin));
		// Find begin of next token.
		skipSpaceAndComment();
		return true;
	}
};

class Lexer {
public:
	typedef Lexing::Token Token;

public:
	class MemMng {
		virtual ~MemMng() {
		};
	};

private:
	typedef Lexing::ccharit ccharit;
	StringView mAll;
	ccharit    mCur;
	MemMng     *mMem; // TODO this needs to be placed into the File class! This file class must live until everything is processed...

public:
	Lexer() : mAll(nullptr, 0), mCur(nullptr), mMem(nullptr) {}
	Lexer(Lexer const &r) = delete;
	Lexer(Lexer &&r) : mAll(r.mAll), mCur(r.mCur), mMem(r.mMem) {
		r.mMem = nullptr;
	}

public:
	~Lexer() {
		destroy();
	}

private:
	void destroy() {
		if (mMem != nullptr) {
			delete mMem;
			mMem = nullptr;
		}
	}

public:
	bool eof() const {
		return mCur == mAll.cend();
	}
	bool nextLine(LineLexer &ll) {
		if (eof()) {
			return false;
		}
		charit eol, next;
		findEndOfLine(mCur, mAll.cend(), eol, next);
		StringView sw(mCur, (eol - mCur));
		mCur = next;
		ll.resetView(sw);
		return true;
	}

public:
	// Create a memory mapped file source.
	struct MemMngViaMemap : MemMng {
		boost::iostreams::mapped_file_source mMmf;	
	};
	void openFile(std::string const &path) {
		destroy();

		MemMngViaMemap &mm = *(new MemMngViaMemap());
		mm.mMmf.open(path);

		mAll = StringView(mm.mMmf.data(), mm.mMmf.size());
		mCur = mAll.cbegin();
	}

public:
	// Read a whole stream to memory, see also
	// https://stackoverflow.com/questions/116038/what-is-the-best-way-to-read-an-entire-file-into-a-stdstring-in-c
	struct MemMngViaString : MemMng {
		std::string mStr;
	};
	void openStream(std::istream &in) {
		destroy();

		MemMngViaString &mm = *(new MemMngViaString());
		stringstream sstr;
		sstr << in.rdbuf();
		mm.mStr = sstr.str();

		mAll = StringView(mm.mStr.data(), mm.mStr.size());
		mCur = mAll.cbegin();	
	}
};

} }

#endif /* _HXX */

