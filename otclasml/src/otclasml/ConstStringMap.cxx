/* $Id$
 * (L)
*/
#include <otclasml/ConstStringMap.hxx>

namespace otclasml { namespace ConstStringMap {

namespace {
	StringView sv(String const &s) {
		return StringView(s.data, s.size);
	}
	bool compare(String const &a, String const &b) {
		return sv(a).compare(sv(b));
	}
	struct Less {
		bool operator() (String const &a, String const &b) const {
			return compare(a,b) < 0;
		}
	};
}

uintptr_t fromString(StringView key, String const *map, uintptr_t nValidEntries)
{
	String k = { key.data(), key.size() };
	String const *mapend = map + nValidEntries;
	String const *found = std::lower_bound(map, mapend, k, Less());
	if (compare(k, *found) == 0) return (uintptr_t)(found - map);
	return nValidEntries;
}
StringView toString(uintptr_t index, String const *map, uintptr_t nValidEntries)
{
	String const *f;
	if (index > nValidEntries) {
		f = &map[nValidEntries];
	} else {
		f = &map[index];
	}
	return StringView(f->data, f->size);
}

}}

