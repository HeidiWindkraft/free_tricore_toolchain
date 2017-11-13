/* $Id$
 * (L)
*/
#ifndef OTCLASML_PARSER_HXX
#define OTCLASML_PARSER_HXX 1

#include "tokens.hxx"

namespace otclasml { namespace {

class Parser {
private:
	istream_t &mIstream;
	
public:
	explicit Parser(istream_t &istream) : mIstream(istream) {}


};

} }

#endif /* _HXX */

