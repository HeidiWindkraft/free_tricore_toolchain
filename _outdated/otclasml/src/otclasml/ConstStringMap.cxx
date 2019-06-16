/* $Id$
 * (L)
*/
#include <otclasml/ConstStringMap.hxx>
#include <otclasml/ConstStringMapCmp.hxx>

#include <iostream> // TODO DEBUG

namespace otclasml { namespace ConstStringMap {

uintptr_t fromString(StringView key, String const *map, uintptr_t nValidEntries)
{
	String k = { key.data(), key.size() };
	String const *mapend = map + nValidEntries;
	String const *found = std::lower_bound(map, mapend, k, Greater()); //Less());
	std::cerr << "\t\t" << "FOUND \"" << sv(*found) << "\"" << std::endl; // TODO DEBUG
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

