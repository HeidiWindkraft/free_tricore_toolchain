/* $Id$
 * (L)
*/
#ifndef OTCTLASML_OPCF_HXX
#define OTCTLASML_OPCF_HXX 1

#include <otctlasml/StringView.hxx>
#include <otctlasml/inttypes.hxx>

namespace otctlasml { namespace opcf {

// There are 50 entries.
enum opcf_e : uint8_t {
	ALIGNE,
	ALIGNV,
	BYTES,
	DWARF,
	I16,
	I32,
	I64,
	I8,
	IADDR,
	RELOC,
	LABEL,
	ABS,
	ABSB,
	B,
	BIT,
	BO,
	BOL,
	BRC,
	BRN,
	BRR,
	RC,
	RCPW,
	RCR,
	RCRR,
	RCRW,
	RLC,
	RR,
	RR1,
	RR2,
	RRPW,
	RRR,
	RRR1,
	RRR2,
	RRRR,
	RRRW,
	SB,
	SBC,
	SBR,
	SBRN,
	SC,
	SLR,
	SLRO,
	SR,
	SRC,
	SRO,
	SRR,
	SRRS,
	SSR,
	SSRO,
	SYS,
	NENTRIES
}; /* enum */

extern opcf_e opcfFromString(StringView s);
extern StringView opcfToString(uintn_t val);
inline StringView toString(opcf_e val) { return opcfToString((uint8_t) val); }

} } /* namespaces */
#endif /* _HXX */

