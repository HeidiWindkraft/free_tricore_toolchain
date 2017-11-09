/* $Id$
 * (L)
*/

#include <opcf_test.hxx>
#include <otctlasml/StringView.hxx>
#include <otctlasml/inttypes.hxx>
#include <otctlasml/ConstStringMap.hxx>

namespace otctlasml { namespace opcf {

static ConstStringMap::String opcf_strings[NENTRIES] = {
	{ ".aligne", 7 }, // 0: ALIGNE
	{ ".alignv", 7 }, // 1: ALIGNV
	{ ".bytes", 6 }, // 2: BYTES
	{ ".dwarf", 6 }, // 3: DWARF
	{ ".i16", 4 }, // 4: I16
	{ ".i32", 4 }, // 5: I32
	{ ".i64", 4 }, // 6: I64
	{ ".i8", 3 }, // 7: I8
	{ ".iaddr", 6 }, // 8: IADDR
	{ ".reloc", 6 }, // 9: RELOC
	{ ":", 1 }, // 10: LABEL
	{ "ABS", 3 }, // 11: ABS
	{ "ABSB", 4 }, // 12: ABSB
	{ "B", 1 }, // 13: B
	{ "BIT", 3 }, // 14: BIT
	{ "BO", 2 }, // 15: BO
	{ "BOL", 3 }, // 16: BOL
	{ "BRC", 3 }, // 17: BRC
	{ "BRN", 3 }, // 18: BRN
	{ "BRR", 3 }, // 19: BRR
	{ "RC", 2 }, // 20: RC
	{ "RCPW", 4 }, // 21: RCPW
	{ "RCR", 3 }, // 22: RCR
	{ "RCRR", 4 }, // 23: RCRR
	{ "RCRW", 4 }, // 24: RCRW
	{ "RLC", 3 }, // 25: RLC
	{ "RR", 2 }, // 26: RR
	{ "RR1", 3 }, // 27: RR1
	{ "RR2", 3 }, // 28: RR2
	{ "RRPW", 4 }, // 29: RRPW
	{ "RRR", 3 }, // 30: RRR
	{ "RRR1", 4 }, // 31: RRR1
	{ "RRR2", 4 }, // 32: RRR2
	{ "RRRR", 4 }, // 33: RRRR
	{ "RRRW", 4 }, // 34: RRRW
	{ "SB", 2 }, // 35: SB
	{ "SBC", 3 }, // 36: SBC
	{ "SBR", 3 }, // 37: SBR
	{ "SBRN", 4 }, // 38: SBRN
	{ "SC", 2 }, // 39: SC
	{ "SLR", 3 }, // 40: SLR
	{ "SLRO", 4 }, // 41: SLRO
	{ "SR", 2 }, // 42: SR
	{ "SRC", 3 }, // 43: SRC
	{ "SRO", 3 }, // 44: SRO
	{ "SRR", 3 }, // 45: SRR
	{ "SRRS", 4 }, // 46: SRRS
	{ "SSR", 3 }, // 47: SSR
	{ "SSRO", 4 }, // 48: SSRO
	{ "SYS", 3 }, // 49: SYS
	{ "~[invalid~entry~opcf]~", 22 }
}; /* strings */

opcf_e opcfFromString(StringView s) {
	return (opcf_e) ConstStringMap::fromString(s, opcf_strings, (uintn_t) NENTRIES);
}
extern StringView opcfToString(uintn_t val) {
	return ConstStringMap::toString(val, opcf_strings, (uintn_t) NENTRIES);
}

} } /* namespaces */

