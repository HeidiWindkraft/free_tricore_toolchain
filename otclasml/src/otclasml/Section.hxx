/* $Id$
 * (L)
*/
#ifndef OTCLASM_SECTION_HXX
#define OTCLASM_SECTION_HXX 1

#include <otclasm/idtable.hxx>
#include <otclasm/labeldecl.hxx>

namespace otclasm { namespace {

class SectionLabels {
public:
	IdTable<Label> mExtern;
	IdTable<Label> mIntern;
	IdTable<LabelWithSection> mGlobal;	
};

class Section {
	token_t mSectionName;
	SectionLabels mLabels;
	
};

}

#endif /* _HXX */

