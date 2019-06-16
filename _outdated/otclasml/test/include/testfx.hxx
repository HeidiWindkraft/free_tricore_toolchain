/* $Id$
 * (L)
*/
#ifndef TESTFX_HXX
#define TESTFX_HXX

#include <iostream>
#include <typeinfo>

#include <otclasml/StringView.hxx>

namespace tests {
	template <class A, class B>
	bool eq(A const &a, B const &b) {
		return a == b;
	}
}

struct Tests {

	std::ostream &o;
	uintptr_t nGrpFails,
	          nGrpTests,
	          nTotalFails,
	          nTotalTests;
	const char *curGrp;

	explicit Tests(std::ostream &o_) : o(o_), nTotalFails(0), nTotalTests(0), curGrp("~") {}

	void startGroup(const char *gn) {
		o << gn << " {" << std::endl;
		nGrpFails = 0;
		nGrpTests = 0;
		curGrp = gn;
	}
	void start(const char *tsn) {
		o << G() << tsn << " {" << std::endl;
	}
	template <class A, class B>
	void eq(A const &a, B const &b, const char *tn) {
		++nGrpTests;
		++nTotalTests;
		o << T() << tn << ": ";
		if (tests::eq(a,b)) {
			o << "ok." << std::endl;
			return;
		}
		// FAIL
		++nGrpFails;
		++nTotalFails;
		o << "FAIL! \n"
			<< F() << '\"' << a << "\"(" << typeid(A).name() << ")\n"
			<< F() << '\"' << b << "\"(" << typeid(B).name() << ")" << std::endl;
	}
	void stop() {
		o << G() << '}' << std::endl;
	}
	void stopGroup() {
		o << "} results " << curGrp << " {\n"
		  << "  " << nGrpFails << " failures in this group;\n"
		  << "  " << nGrpTests << " tests in this group;\n"
		  << "}" << std::endl;
	}
	void summarize() {
		o << "\nsummary {\n"
		  << "  " << nTotalFails << " failures in total;\n"
		  << "  " << nTotalTests << " tests in total;\n"
		  << "}" << std::endl;
	}

private:
	static const char *G() { return "  "; }
	static const char *T() { return "    "; }
	static const char *F() { return "      "; }
};

#endif // _HXX

