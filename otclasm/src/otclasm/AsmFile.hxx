/* $Id$
 * (L)
*/
#ifndef OTCLASM_ASMFILE_HXX
#define OTCLASM_ASMFILE_HXX 1

#include <otclasm/idtable.hxx>

namespace otclasm { namespace {

class AsmFile {
	token_t mFilename;
	IdTable<Label> mExtern;
	IdTable<Label> mIntern;
	IdTable<LabelWithSection> mGlobal;
	
};

