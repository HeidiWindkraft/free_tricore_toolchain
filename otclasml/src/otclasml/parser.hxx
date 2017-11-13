/* $Id$
 * (L)
*/
#ifndef OTCLASM_PARSER_HXX
#define OTCLASM_PARSER_HXX 1

#include "tokens.hxx"

namespace otclasm { namespace {

class Parser {
private:
	istream_t &mIstream;
	
public:
	explicit Parser(istream_t &istream) : mIstream(istream) {}


};

} }

#endif /* _HXX */

