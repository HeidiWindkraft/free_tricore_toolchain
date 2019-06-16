/* $Id$
 * (L)
*/
#ifndef OTCLASML_ASMFILE_HXX
#define OTCLASML_ASMFILE_HXX 1

#include <otclasml/idtable.hxx>

namespace otclasml { namespace {

class AsmFile {
	token_t mFilename;
	IdTable<Label> mExtern;
	IdTable<Label> mIntern;
	IdTable<LabelWithSection> mGlobal;
	
};

