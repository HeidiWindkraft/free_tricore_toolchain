#ifndef TCLASM_HRPARSER_HXX
#define TCLASM_HRPARSER_HXX

#include <tclasm/insn.hxx>

namespace tclasm { namespace hrparser {	

class OpcfParser {
public:
	virtual ~OpcfParser() {};
	virtual void parse(insn_t &insn, line_istream_t &lis) = nullptr;
};

namespace OpcfParsers {
	class ABS : public OpcfParser {
		void parse(insn_t &insn, line_istream_t &lis) override {
			parseMnem(insn, lis);
			insn.a.abs.s1d = nextRegIdx(lis);
			insn.a.abs.offs18 = nextOffs(lis);
		}
	};
	class ABSB : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {
			parseMnem(insn, lis);
			insn.a.absb.bpos = nextInt(lis);
			insn.a.absb.b = nextInt(lis);
			insn.a.absb.offs18 = nextImm(lis);
		}
	};
	class B : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {
			parseMnem(insn, lis);
			insn.a.b.disp24 = nextImm(lis);
		}
	};
	class BIT : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {
			parseMnem(insn, lis);
			insn.a.bit.s1 = nextRegIdx(lis);
			insn.a.bit.s2 = nextRegIdx(lis);
			insn.a.bit.pos1 = nextInt(lis);
			insn.a.bit.pos2 = nextInt(lis);
			insn.a.bit.d = nextRegIdx(lis);
		}
	};
	class BO : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {
			parseOpcxBo(insn, lis);
			parseMnem(insn, lis);
			insn.a.bo.s1d = nextRegIdx(lis);
			insn.a.bo.s2 = nextRegIdx(lis);
			insn.a.bo.offs10 = nextImm(lis);
		}
	};
	class BOL : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {
			parseMnem(insn, lis);
			insn.a.bo.s1d = nextRegIdx(lis);
			insn.a.bo.s2 = nextRegIdx(lis);
			insn.a.bo.offs16 = nextImm(lis);
		}
	};
	class BRC : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {
			parseMnem(insn, lis);
			insn.a.brc.s1 = nextRegIdx(lis);
			insn.a.brc.const4 = nextImm(lis);
			insn.a.brc.disp15 = nextImm(lis);
		}
	};
	class BRN : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {
			parseMnem(insn, lis);
			insn.a.brn.s1 = nextRegIdx(lis);
			insn.a.brn.n = nextInt(lis);
			insn.a.brn.disp15 = nextImm(lis);
		}
	};
	class BRR : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {
			parseMnem(insn, lis);
			insn.a.brr.s1 = nextRegIdx(lis);
			insn.a.brr.s2 = nextRegIdx(lis);
			insn.a.brr.disp15 = nextImm(lis);
		}
	};
	class RC : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {
			parseMnem(insn, lis);
			insn.a.rc.s1 = nextRegIdx(lis);
			insn.a.rc.const9 = nextImm(lis);
			insn.a.rc.d = nextRegIdx(lis);
		}
	};
	class RCPW : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class RCR : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class RCRR : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class RCRW : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class RLC : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class RR : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class RR1 : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class RR2 : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class RRPW : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class RRR : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class RRR1 : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class RRR2 : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class RRRR : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class RRRW : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SB : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SBC : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SBR : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SBRN : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SC : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SLR : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SLRO : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SR : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SRC : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SRO : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SRR : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SRRS : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SSR : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SSRO : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
	class SYS : public OpcfParser {
		void  parse(insn_t &insn, line_istream_t &lis) override {

		}
	};
}

}}

#endif /* _HXX */

