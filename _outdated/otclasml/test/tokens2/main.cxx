#include <iostream>

#include <otclasml/Lexer.hxx>
#include <otclasml/io/InFile.hxx>


using namespace otclasml;
using namespace otclasml::io;
using namespace std;


int main(int argc, const char *argv[]) {

	InFile ifile;
	Lexer lexer;
	LineLexer llex;
	StringView tok;

	if (argc == 1) {
		ifile.openCharStream(std::cin);
	} else {
		ifile.openFile(argv[1]);
	}
	lexer.resetView(ifile.strv());

	while (!lexer.eof()) {
		lexer.nextLine(llex);
		cout << "LINE: \"" << llex.getAll() << "\"" << endl;
		while (llex.hasNext()) {
			llex.getNext(tok);
			int radix = getIntRadix(tok);
			uint64_t val = 0;
			if (radix > 0) {
				val = toUInt64(tok, radix);
			}
			cout << "\tTOKEN: \"" << tok << "\" : " << radix << ", " << val << endl;
		}
	}

	return 0;
}

