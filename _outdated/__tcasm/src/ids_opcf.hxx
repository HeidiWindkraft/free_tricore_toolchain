#ifndef TCLASM_IDS_MNEMS_HXX
#define TCLASM_IDS_MNEMS_HXX 1

/* THIS FILE IS GENERATED. */

#include <tclasm/ints.h>

namespace tclasm {

	enum opcf_e : uint8_t {
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
		END_OF_OPCF_E
	};
	typedef enum opcf_e opcf_t;

	opcf_t getOpcfFromCstr(const char *cstr);
}
