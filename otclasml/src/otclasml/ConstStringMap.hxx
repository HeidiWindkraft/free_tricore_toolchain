/* $Id$
 * (L)
*/
#ifndef OTCLASML_CONST_STRING_MAP_HXX
#define OTCLASML_CONST_STRING_MAP_HXX 1

#include <otclasml/StringView.hxx>

/* Const maps are arrays of string slice structures.
 * The string slices must be sorted in ascending lexicographic order.
 * Beyond the last valid element there must be a dummy element (which shouldn't equal one of the valid elements).
*/
namespace otclasml { namespace ConstStringMap {

	struct String {
		const char *data;
		uintptr_t   size;
	};

	/* fromString - Get the index of a given key string in the given map.
	 *
	 * Parameters:
	 *	key             - The key to search.
	 *  map             - The map in which the key shall be searched - an array of sorted Strings.
	 *  nValidEntries   - Number of searchable entries in the map. The actual array has to have one element more.
	*/
	uintptr_t fromString(StringView key, String const *map, uintptr_t nValidEntries);

	/* toString - Converts the given index to a string.
	*/
	StringView toString(uintptr_t index, String const *map, uintptr_t nValidEntries)

#if 0
	/* fromStringI - Get the index of a given key string in the given map (case insensitive)
	 *
	 * Parameters:
	 *	key             - The key to search.
	 *  map             - The map in which the key shall be searched - an array of sorted Strings.
	 *  nValidEntries   - Number of searchable entries in the map. The actual array has to have one element more.
	*/
	uintptr_t fromStringI(StringView key, String const *map, uintptr_t nValidEntries);
#endif
}}

#endif /* _HXX */

