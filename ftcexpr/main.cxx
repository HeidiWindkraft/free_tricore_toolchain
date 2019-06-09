/* Main function offtcexpr demo.
 *
 * License: GNU GPL 3, see LICENSE file.
*/
#include "ftcexpr_demo_driver.hxx"
#include "ftcexpr_parse_intlit.hxx"
#include <iostream>

int main(int argc, char **argv) {
	using namespace ftcexpr_demo;
	using namespace std;

	/*std::string intlits[] = {
		"0",
		"1",
		"0x10",
		"0b10",
		"42"
	};
	cout << "# IntLit test" << endl;
	for (std::string const &s : intlits) {
		ftcexpr::IntLit ilv = ftcexpr::parse_intlit(s);
		cout << s << ":"
			<< "\n\t" << "value: " << ilv.value
			<< "\n\t" << "radix: " << ilv.radix
			<< "\n\t" << "flags: " << ilv.radix
			<< endl;
	}

	cout << "# Parser test" << endl;*/
	Driver drv;
	for (int i = 1; i < argc; ++i) {
		cout << "$> " << argv[i] << endl;
		int64_t res = drv.parse_cstring(argv[i]);
		cout << " = " << dec << res << " = 0x" << hex << res << endl;
	}
	return 0;
}
