/* $Id$
 * (L)
*/
#ifndef OTCLASM_LABELDECL_HXX
#define OTCLASM_LABELDECL_HXX 1

#include <otclasm/tokens.hxx>

namespace otclasm { namespace {

struct LabelDecl {
	token_t id; // id contains section, if the section flag is set. -- this means that the whole section name has to be given as one token.
	uint32_t flags;
	uint32_t address; // only valid if the absolute-address or relative-address flag is set.
};

}}

#endif /* _HXX */

