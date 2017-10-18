/* $Id$
 * (L)
*/
#ifndef OTCLASM_LABELDECLS_HXX
#define OTCLASM_LABELDECLS_HXX 1

#include <otclasm/labeldecl.hxx>
#include <algorithm>

namespace otclasm { namespace {

/*
 *
 * Only MutableLabelDeclAccess may inherit from this class.
*/
class LabelDeclAccess {
protected:
	LabelDecl *plabdecl;

public:
	LabelDeclAccess() = default;
	LabelDeclAccess(LabelDeclAccess const &) = default;
	LabelDeclAccess(LabelDeclAccess const &&) = default;

protected:
	explicit LabelDeclAccess(AbstractLabelDecl &labdecl) : plabdecl(&labdecl) {}

public:
	bool less(LabelDeclAccess const &r) const {
		if (plabdecl->section < 
		return plabdecl->id < r.plabdecl->id;
	}

public:
	token_t const &getId() const { return plabdecl->id; }
	uint32_t const &accFlags() const { return plabdecl->flags; }
	uint32_t const &accAddress() const { return plabdecl->address; }

public:
	static bool operator< (LabelDeclAccess const &a, LabelDeclAccess const &b) {
		return a.less(b);
	}
};

class MutableLabelDeclAccess : public LabelDeclAccess {
public:
	MutableLabelDeclAccess() : LabelDeclAccess() {}
	MutableLabelDeclAccess(LabelDeclAccess const &r) : LabelDeclAccess(r) {}
	MutableLabelDeclAccess(LabelDeclAccess const &&r) : LabelDeclAccess(r) {}
	explicit MutableLabelDeclAccess(LabelDecl &labdecl) : plabdecl(&labdecl) {}

public:
	uint32_t &accFlags() const { return plabdecl->flags; }
	uint32_t &accAddress() const { return plabdecl->address; }
};



class LabelDeclTable {
	typedef std::vector<LabelDecl>              declcont_t;
	typedef std::vector<MutableLabelDeclAccess> acccont_t;
private:
	declcont_t mDecls;
	acccont_t mAccessors;
private:
	void checkAccEmpty() const {
		if (!mAccessors.empty()) {
			throw std::runtime_exception("Label decls or accessors must not be modified after accessors were built.");
		}
	}
public:
	void reserve(declcont_t::size_type cap) {
		checkAccEmpty();
		mDecls.reserve(cap);
	}
	void push_back(LabelDecl const &r) {
		checkAccEmpty();
		mDecls.push_back(r);
	}
	void push_back(LabelDecl const &&r) {
		checkAccEmpty();
		mDecls.push_back(r);
	}

public:
	declcont_t const &decls() const { return mDecls; }

public:
	void buildAccessors() {
		checkAccEmpty();
		mAccessors.reserve(ldec.size());
		for (LabelDecl &ldec : mDecls) {
			mAccessors.push_back(MutableLabelDeclAccess(ldec));
		}
		std::sort(mAccessors.begin(), mAccessors.end());
	}

public:
	LabelDeclAccess const *find(token_in tok) const {
		acccont_t::const_iterator found = std::lower_bound(mAccessors.begin(), mAccessors.end(), tok);
		if (found == mAccessors.end()) {
			return nullptr;
		} else {
			return &*found;
		}
	}
	MutableLabelDeclAccess const *find(token_in tok) {
		acccont_t::const_iterator found = std::lower_bound(mAccessors.begin(), mAccessors.end(), tok);
		if (found == mAccessors.end()) {
			return nullptr;
		} else {
			return &*found;
		}
	}
};

}}

#endif /* _HXX */

