/* $Id$
 * (L)
*/
#ifndef OTCLASML_SECTION_HXX
#define OTCLASML_SECTION_HXX 1

#include <otclasml/idtable.hxx>
#include <otclasml/labeldecl.hxx>

namespace otclasml { namespace {

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

