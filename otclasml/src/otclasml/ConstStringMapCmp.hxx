/* $Id$
 * (L)
*/
#ifndef OTCLASML_CONST_STRING_MAP_CMP_HXX
#define OTCLASML_CONST_STRING_MAP_CMP_HXX 1

#include <otclasml/ConstStringMap.hxx>

#include <iostream> // TODO DEBUG

namespace otclasml { namespace ConstStringMap {

namespace {
	StringView sv(String const &s) {
		return StringView(s.data, s.size);
	}
	bool compare(String const &a, String const &b) {
		std::cerr << "\t\t" << "COMPARE \"" << sv(a) << "\" \"" << sv(b) << "\" " << sv(a).compare(sv(b)) << std::endl; // TODO DEBUG
		return sv(a).compare(sv(b));
	}
	struct Less {
		bool operator() (String const &a, String const &b) const {
			return compare(a,b) < 0; //> 0; //< 0;
		}
	};
	struct Greater {
		bool operator() (String const &a, String const &b) const {
			return compare(a,b) > 0;
		}
	};
	struct GreaterEq {
		bool operator() (String const &a, String const &b) const {
			return compare(a,b) >= 0;
		}
	};
}

}}

#endif // _HXX

