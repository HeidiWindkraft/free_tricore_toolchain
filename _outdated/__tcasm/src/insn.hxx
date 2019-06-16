#ifndef TCLASM_INSN_HXX
#define TCLASM_INSN_HXX

#include <tclasm/ids_mnems.hxx>
#include <tclasm/ids_opcfs.hxx>

namespace tclasm {

	struct insn_t {
		
		struct imm_t {
			enum type_t : uint8_t {
				IMM,    // Just an immediate.
				CABS,   // Label value for call absolute.
				CREL,   // Label value for call relative.
				CDIST,  // Distance between two values for calls.
				ABS,    // Absolute label value.
				REL,    // Relative label value.
				DIST,   // Difference between two labels.
				HIS,    // High part of a label (sign-adjusted).
				LOS,    // Low part of a label (sign-adjusted).
				HIU,    // High part of a label (unsigned).
				LOU,    // Low part of a label (unsigned).
			};

			uint32_t type_bits  :  8;
			uint32_t value_bits : 24;

			type_t type() const { return type_t(type_bits); }
			void type(type_t v) { type_bits = v; }
			uint32_t value() const { return value_bits; }
			void value(uint32_t v) { value_bits = v & 0x00ffffffu; }

			uint32_t label() const { return value(); }
			void label(uint32_t v) {
				if (v > 0x00ffffffu) {
					throw "Label index exceeds range.";
				}
				value(v);
			}
			uint16_t labelop0() const { return value() & 0xfffu; }
			uint16_t labelop1() const { return (value() >> 12) & 0xfffu; }
			void labelop0(uint16_t v) {
				if (v > 0xfffu) {
					throw "Label operand 0 index exceeds range.";
				}
				value( (value() & ~0xfff) | v );
			}
			void labelop1(uint16_t v) {
				if (v > 0xfffu) {
					throw "Label operand 1 index exceeds range.";
				}
				value( (value() & ~0x00fff000) | (v << 12) );
			}
		};

		struct abs_t {
			uint8_t rS1D;
			imm_t offs18;
		};
		struct absb_t {
			uint8_t b;
			uint8_t bpos;
			imm_t offs18;
		};
		struct b_t {
			imm_t disp24;
		};
		struct bit_t {
			uint8_t s1;
			uint8_t s2;
			uint8_t pos1;
			uint8_t pos2;
			uint8_t d;
		};
		struct bo_t {
			uint8_t s1d;
			uint8_t s2;
			imm_t off10;
		};
		struct bol_t {
			uint8_t s1d;
			uint8_t s2;
			imm_t off10;
		};
		struct brc_t {
			uint8_t s1;
			imm_t const4;
			imm_t disp15;
		};
		struct brn_t {
			uint8_t s1;
			uint8_t n;
			imm_t disp15;
		};
		struct brr_t {
			uint8_t s1;
			uint8_t s2;
			imm_t disp15;
		};
		struct rc_t {
			uint8_t s1;
			uint8_t d;
			imm_t const9;
		};
		struct rcpw_t {
			uint8_t s1;
			uint8_t width;
			uint8_t pos;
			uint8_t d;
			imm_t const4;
		};
		struct rcr_t {
			uint8_t s1;
			uint8_t s3;
			uint8_t d;
			imm_t const9;
		};
		struct rcrr_t {
			uint8_t s1;
			uint8_t s3;
			uint8_t d;
			imm_t const4;
		};
		struct rcrw_t {
			uint8_t s1;
			uint8_t s3;
			uint8_t d;
			uint8_t width;
			imm_t const4;
		};
		struct rlc_t {
			uint8_t s1;
			uint8_t d;
			imm_t const16;
		};
		struct rr_t {
			uint8_t s1;
			uint8_t s2;
			uint8_t d;
			uint8_t n;
		};
		struct rr1_t {
			uint8_t s1;
			uint8_t s2;
			uint8_t d;
			uint8_t n;
		};
		struct rr2_t {
			uint8_t s1;
			uint8_t s2;
			uint8_t d;
		};
		struct rrpw_t {
			uint8_t s1;
			uint8_t s2;
			uint8_t d;
			uint8_t width;
			uint8_t pos;
		};
		struct rrr_t {
			uint8_t s1;
			uint8_t s2;
			uint8_t d;
			uint8_t n;
			uint8_t s3;
		};
		struct rrr1_t {
			uint8_t s1;
			uint8_t s2;
			uint8_t d;
			uint8_t n;
			uint8_t s3;
		};
		struct rrr2_t {
			uint8_t s1;
			uint8_t s2;
			uint8_t d;
			uint8_t s3;
		};
		struct rrrr_t {
			uint8_t s1;
			uint8_t s2;
			uint8_t d;
			uint8_t s3;
		};
		struct rrrw_t {
			uint8_t s1;
			uint8_t s2;
			uint8_t d;
			uint8_t s3;
			uint8_t width;
		};
		struct sb_t {
			imm_t disp8;
		};
		struct sbc_t {
			imm_t const4;
			imm_t disp4;
		};
		struct sbr_t {
			uint8_t rS2;
			imm_t disp4;
		};
		struct sbrn_t {
			uint8_t n;
			imm_t disp4;
		};
		struct sc_t {
			imm_t const8;
		};
		struct slr_t {
			uint8_t rS2;
			uint8_t rD;
		};
		struct slro_t {
			imm_t offs4;
			uint8_t rD;
		};
		struct sr_t {
			uint8_t r;
		};
		struct src_t {
			imm_t const4;
			uint8_t r;
		};
		struct sro_t {
			uint8_t rS2;
			imm_t off4;
		};
		struct srr_t {
			uint8_t rS2;
			uint8_t rS1D;
		};
		struct srrs_t {
			uint8_t rS2;
			uint8_t rS1D;
			uint8_t n;
		};
		struct ssr_t {
			uint8_t rS2;
			uint8_t rS1;
		};
		struct ssro_t {
			imm_t offs4;
			uint8_t rS1;
		};
		struct sys_t {
			uint8_t s1d;
		};

		struct maxargs_t {
			uint32_t w0, w1, w2;
		};

		union args_t {
			maxargs_t maxargs;
			abs_t abs;
			absb_t absb;
			b_t b;
			bit_t bit;
			bo_t bo;
			bol_t bol;
			brc_t brc;
			brn_t brn;
			brr_t brr;
			rc_t rc;
			rcpw_t rcpw;
			rcr_t rcr;
			rcrr_t rcrr;
			rcrw_t rcrw;
			rlc_t rlc;
			rr_t rr;
			rr1_t rr1;
			rr2_t rr2;
			rrpw_t rrpw;
			rrr_t rrr;
			rrr1_t rrr1;
			rrr2_t rrr2;
			rrrr_t rrrr;
			rrrw_t rrrw;
			sb_t sb;
			sbc_t sbc;
			sbr_t sbr;
			sbrn_t sbrn;
			sc_t sc;
			slr_t slr;
			slro_t slro;
			sr_t sr;
			src_t src;
			sro_t sro;
			srr_t srr;
			srrs_t srrs;
			ssr_t ssr;
			ssro_t ssro;
			sys_t sys;
		};

		enum opcx_bo_t : uint8_t {
			BO_S,       // Short offset     "S"
			BO_R,       // Bit-reverse      "R"
			BO_C,       // Circular         "C"
			BO_SXX,     // Post-increment   "S++"
			BO_XXS      // Pre-increment    "++S"
		};
		enum opcx_srx_t : uint8_t { // for SRC and SRR
			SRX__,      // "-": Nothing special.
			SRX_D15IN,  // "D15IN": D15 is implicit input register.
			SRX_D15OUT  // "D15OUT": D15 is implict output register.
		};
		union opcx_t {
			opcx_bo_t   bo;
			opcx_srx_t  srx;
		};

		opcf_t opcf;
		mnem_t mnem;
		opcx_t opcx;
		args_t a;
	};
	

}

#endif /* _HXX */

