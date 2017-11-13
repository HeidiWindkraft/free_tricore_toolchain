/* $Id$
 * (L)
*/
#ifndef OTCLASML_IDTABLE_HXX
#define OTCLASML_IDTABLE_HXX 1

#include <algorithm>

namespace otclasml { namespace {

/* IdTable
 *
 * Parameter I:
 *  'I' is the type of an "identifyable" object.
 *  'I' must at least offer an id() method which returns a token input (const reference or copy).
 *  'I' should always return the same id() value during its lifetime, otherwise the id loop-up will stop working.
*/
template <class I>
class IdTable {
private:
	struct Ref {
		I *pi;

		Ref() = default;
		Ref(Ref const &) = default;
		Ref(Ref const &&) = default;

		explicit Ref(I *pi_) : pi(pi_) {}

		bool less(Ref const &r) const {
			return plabdecl->id() < r.plabdecl->id();
		}

		static bool operator< (Ref const &a, Ref const &b) {
			return a.less(b);
		}
	};
	typedef std::vector<Ref>    refcont_t;

public:
	typedef std::vector<I>      declcont_t;

private:
	declcont_t mDecls;
	refcont_t mIdLut;

private:
	void checkAccEmpty() const {
		if (!mIdLut.empty()) {
			throw std::runtime_exception("Label decls or id-lookup-table must not be modified after id-lookup-table was built.");
		}
	}

public:
	void reserve(declcont_t::size_type cap) {
		checkAccEmpty();
		mDecls.reserve(cap);
	}
	void push_back(I const &r) {
		checkAccEmpty();
		mDecls.push_back(r);
	}
	void push_back(I const &&r) {
		checkAccEmpty();
		mDecls.push_back(r);
	}

public:
	declcont_t const &decls() const { return mDecls; }
	declcont_t &decls() { return mDecls; }

public:
	void buildAccessors() {
		checkAccEmpty();
		mIdLut.reserve(mDecls.size());
		for (I &ldec : mDecls) {
			mIdLut.push_back(Ref(&ldec));
		}
		std::sort(mIdLut.begin(), mIdLut.end());
	}

public:
	I const *find(token_in tok) const {
		acccont_t::const_iterator found = std::lower_bound(mIdLut.begin(), mIdLut.end(), tok);
		if (found == mIdLut.end()) {
			return nullptr;
		} else {
			return &*found;
		}
	}
	I *find(token_in tok) {
		acccont_t::const_iterator found = std::lower_bound(mIdLut.begin(), mIdLut.end(), tok);
		if (found == mIdLut.end()) {
			return nullptr;
		} else {
			return &*found;
		}
	}
};

}}

#endif /* _HXX */

