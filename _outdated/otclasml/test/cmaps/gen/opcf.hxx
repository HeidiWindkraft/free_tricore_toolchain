/* $Id$
 * (L)
*/
#ifndef TEST_OTCLASML_OPCF_HXX
#define TEST_OTCLASML_OPCF_HXX

#include <otclasml/cmaps/opcf.hxx>
#include <testfx.hxx>
#include <otclasml/ConstStringMapCmp.hxx>
#include <algorithm>
#include <vector>

void testConstStringMapOpcf(Tests &t) {
	using namespace otclasml::opcf;
	using namespace otclasml;

	t.startGroup("testConstStringMapOpcf");

	t.start("opcf_strings");
	bool issorted = std::is_sorted(opcf_detail::opcf_strings, opcf_detail::opcf_strings + NENTRIES, ConstStringMap::Less());
	t.eq(true, issorted, "is_sorted");
	if (!issorted) {
		std::cout << "      IS NOT SORTED (" << NENTRIES << ")" << std::endl;
		std::vector<ConstStringMap::String> vec;
		vec.reserve(NENTRIES);
		for (uintn_t i = 0; i < NENTRIES; ++i) {
			vec.push_back( opcf_detail::opcf_strings[i] );
		}
		std::sort(vec.begin(), vec.end(), ConstStringMap::Less());
		for (uintn_t i = 0; i < NENTRIES; ++i) {
			const char *a = opcf_detail::opcf_strings[i].data;
			const char *b = vec[i].data;
			std::cout << "        " << (a == b) << " " << a << " " << b << std::endl;
		}
	}
	t.stop();

	t.start("toOpcf");
	t.eq(ALIGNE, toOpcf(".aligne"), ".aligne");
	t.eq(ALIGNV, toOpcf(".alignv"), ".alignv");
	t.eq(BYTES, toOpcf(".bytes"), ".bytes");
	t.eq(DWARF, toOpcf(".dwarf"), ".dwarf");
	t.eq(I16, toOpcf(".i16"), ".i16");
	t.eq(I32, toOpcf(".i32"), ".i32");
	t.eq(I64, toOpcf(".i64"), ".i64");
	t.eq(I8, toOpcf(".i8"), ".i8");
	t.eq(IADDR, toOpcf(".iaddr"), ".iaddr");
	t.eq(RELOC, toOpcf(".reloc"), ".reloc");
	t.eq(LABEL, toOpcf(":"), ":");
	t.eq(ABS, toOpcf("abs"), "abs");
	t.eq(ABSB, toOpcf("absb"), "absb");
	t.eq(B, toOpcf("b"), "b");
	t.eq(BIT, toOpcf("bit"), "bit");
	t.eq(BO, toOpcf("bo"), "bo");
	t.eq(BOL, toOpcf("bol"), "bol");
	t.eq(BRC, toOpcf("brc"), "brc");
	t.eq(BRN, toOpcf("brn"), "brn");
	t.eq(BRR, toOpcf("brr"), "brr");
	t.eq(RC, toOpcf("rc"), "rc");
	t.eq(RCPW, toOpcf("rcpw"), "rcpw");
	t.eq(RCR, toOpcf("rcr"), "rcr");
	t.eq(RCRR, toOpcf("rcrr"), "rcrr");
	t.eq(RCRW, toOpcf("rcrw"), "rcrw");
	t.eq(RLC, toOpcf("rlc"), "rlc");
	t.eq(RR, toOpcf("rr"), "rr");
	t.eq(RR1, toOpcf("rr1"), "rr1");
	t.eq(RR2, toOpcf("rr2"), "rr2");
	t.eq(RRPW, toOpcf("rrpw"), "rrpw");
	t.eq(RRR, toOpcf("rrr"), "rrr");
	t.eq(RRR1, toOpcf("rrr1"), "rrr1");
	t.eq(RRR2, toOpcf("rrr2"), "rrr2");
	t.eq(RRRR, toOpcf("rrrr"), "rrrr");
	t.eq(RRRW, toOpcf("rrrw"), "rrrw");
	t.eq(SB, toOpcf("sb"), "sb");
	t.eq(SBC, toOpcf("sbc"), "sbc");
	t.eq(SBR, toOpcf("sbr"), "sbr");
	t.eq(SBRN, toOpcf("sbrn"), "sbrn");
	t.eq(SC, toOpcf("sc"), "sc");
	t.eq(SLR, toOpcf("slr"), "slr");
	t.eq(SLRO, toOpcf("slro"), "slro");
	t.eq(SR, toOpcf("sr"), "sr");
	t.eq(SRC, toOpcf("src"), "src");
	t.eq(SRO, toOpcf("sro"), "sro");
	t.eq(SRR, toOpcf("srr"), "srr");
	t.eq(SRRS, toOpcf("srrs"), "srrs");
	t.eq(SSR, toOpcf("ssr"), "ssr");
	t.eq(SSRO, toOpcf("ssro"), "ssro");
	t.eq(SYS, toOpcf("sys"), "sys");
	t.eq(NENTRIES, toOpcf("//"), "invalid entry");
	t.stop();

	t.start("toString");
	t.eq(StringView(".aligne", 7), toString(ALIGNE), ".aligne");
	t.eq(StringView(".alignv", 7), toString(ALIGNV), ".alignv");
	t.eq(StringView(".bytes", 6), toString(BYTES), ".bytes");
	t.eq(StringView(".dwarf", 6), toString(DWARF), ".dwarf");
	t.eq(StringView(".i16", 4), toString(I16), ".i16");
	t.eq(StringView(".i32", 4), toString(I32), ".i32");
	t.eq(StringView(".i64", 4), toString(I64), ".i64");
	t.eq(StringView(".i8", 3), toString(I8), ".i8");
	t.eq(StringView(".iaddr", 6), toString(IADDR), ".iaddr");
	t.eq(StringView(".reloc", 6), toString(RELOC), ".reloc");
	t.eq(StringView(":", 1), toString(LABEL), ":");
	t.eq(StringView("abs", 3), toString(ABS), "abs");
	t.eq(StringView("absb", 4), toString(ABSB), "absb");
	t.eq(StringView("b", 1), toString(B), "b");
	t.eq(StringView("bit", 3), toString(BIT), "bit");
	t.eq(StringView("bo", 2), toString(BO), "bo");
	t.eq(StringView("bol", 3), toString(BOL), "bol");
	t.eq(StringView("brc", 3), toString(BRC), "brc");
	t.eq(StringView("brn", 3), toString(BRN), "brn");
	t.eq(StringView("brr", 3), toString(BRR), "brr");
	t.eq(StringView("rc", 2), toString(RC), "rc");
	t.eq(StringView("rcpw", 4), toString(RCPW), "rcpw");
	t.eq(StringView("rcr", 3), toString(RCR), "rcr");
	t.eq(StringView("rcrr", 4), toString(RCRR), "rcrr");
	t.eq(StringView("rcrw", 4), toString(RCRW), "rcrw");
	t.eq(StringView("rlc", 3), toString(RLC), "rlc");
	t.eq(StringView("rr", 2), toString(RR), "rr");
	t.eq(StringView("rr1", 3), toString(RR1), "rr1");
	t.eq(StringView("rr2", 3), toString(RR2), "rr2");
	t.eq(StringView("rrpw", 4), toString(RRPW), "rrpw");
	t.eq(StringView("rrr", 3), toString(RRR), "rrr");
	t.eq(StringView("rrr1", 4), toString(RRR1), "rrr1");
	t.eq(StringView("rrr2", 4), toString(RRR2), "rrr2");
	t.eq(StringView("rrrr", 4), toString(RRRR), "rrrr");
	t.eq(StringView("rrrw", 4), toString(RRRW), "rrrw");
	t.eq(StringView("sb", 2), toString(SB), "sb");
	t.eq(StringView("sbc", 3), toString(SBC), "sbc");
	t.eq(StringView("sbr", 3), toString(SBR), "sbr");
	t.eq(StringView("sbrn", 4), toString(SBRN), "sbrn");
	t.eq(StringView("sc", 2), toString(SC), "sc");
	t.eq(StringView("slr", 3), toString(SLR), "slr");
	t.eq(StringView("slro", 4), toString(SLRO), "slro");
	t.eq(StringView("sr", 2), toString(SR), "sr");
	t.eq(StringView("src", 3), toString(SRC), "src");
	t.eq(StringView("sro", 3), toString(SRO), "sro");
	t.eq(StringView("srr", 3), toString(SRR), "srr");
	t.eq(StringView("srrs", 4), toString(SRRS), "srrs");
	t.eq(StringView("ssr", 3), toString(SSR), "ssr");
	t.eq(StringView("ssro", 4), toString(SSRO), "ssro");
	t.eq(StringView("sys", 3), toString(SYS), "sys");
	t.stop();
	t.stopGroup();
} // testConstStringMapOpcf

#endif // _HXX

