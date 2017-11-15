/* $Id$
 * (L)
*/

#include <otclasml/cmaps/opcf.hxx>
#include <otclasml/StringView.hxx>
#include <otclasml/inttypes.hxx>
#include <otclasml/ConstStringMap.hxx>

namespace otclasml { namespace opcf {

static const ConstStringMap::String opcf_strings[NENTRIES + 1] = {
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
	{ "abs", 3 }, // 11: ABS
	{ "absb", 4 }, // 12: ABSB
	{ "b", 1 }, // 13: B
	{ "bit", 3 }, // 14: BIT
	{ "bo", 2 }, // 15: BO
	{ "bol", 3 }, // 16: BOL
	{ "brc", 3 }, // 17: BRC
	{ "brn", 3 }, // 18: BRN
	{ "brr", 3 }, // 19: BRR
	{ "rc", 2 }, // 20: RC
	{ "rcpw", 4 }, // 21: RCPW
	{ "rcr", 3 }, // 22: RCR
	{ "rcrr", 4 }, // 23: RCRR
	{ "rcrw", 4 }, // 24: RCRW
	{ "rlc", 3 }, // 25: RLC
	{ "rr", 2 }, // 26: RR
	{ "rr1", 3 }, // 27: RR1
	{ "rr2", 3 }, // 28: RR2
	{ "rrpw", 4 }, // 29: RRPW
	{ "rrr", 3 }, // 30: RRR
	{ "rrr1", 4 }, // 31: RRR1
	{ "rrr2", 4 }, // 32: RRR2
	{ "rrrr", 4 }, // 33: RRRR
	{ "rrrw", 4 }, // 34: RRRW
	{ "sb", 2 }, // 35: SB
	{ "sbc", 3 }, // 36: SBC
	{ "sbr", 3 }, // 37: SBR
	{ "sbrn", 4 }, // 38: SBRN
	{ "sc", 2 }, // 39: SC
	{ "slr", 3 }, // 40: SLR
	{ "slro", 4 }, // 41: SLRO
	{ "sr", 2 }, // 42: SR
	{ "src", 3 }, // 43: SRC
	{ "sro", 3 }, // 44: SRO
	{ "srr", 3 }, // 45: SRR
	{ "srrs", 4 }, // 46: SRRS
	{ "ssr", 3 }, // 47: SSR
	{ "ssro", 4 }, // 48: SSRO
	{ "sys", 3 }, // 49: SYS
	{ "~[invalid~entry~opcf]~", 22 }
}; /* strings */

opcfs_e toOpcf(StringView s) {
	return (opcfs_e) ConstStringMap::fromString(s, opcf_strings, (uintn_t) NENTRIES);
}
StringView opcfToString(uintn_t val) {
	return ConstStringMap::toString(val, opcf_strings, (uintn_t) NENTRIES);
}

} } /* namespaces */

