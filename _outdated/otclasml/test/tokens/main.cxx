#include <iostream>

#include <otclasml/tokens.hxx>


using namespace otclasml;
using namespace std;


int main(void) {

	line_t line;
	line_stream_t linestream;
	token_t tok;

	while (!cin.eof()) {
		line.clear();
		nextLine(cin, line);
		cout << "LINE: \"" << line << "\"" << endl;
		getStreamFromLine(line, linestream);
		while (!linestream.eof()) {
			tok.clear();
			nextToken(linestream, tok);
			int radix = getIntRadix(tok);
			uint64_t val = 0;
			if (radix > 0) {
				val = getInt(tok, radix);
			}
			cout << "\tTOKEN: \"" << tok << "\" : " << radix << ", " << val << endl;
		}
	}

	return 0;
}

