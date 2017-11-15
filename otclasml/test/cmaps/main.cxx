#include <iostream>

#include "gen/opcf.hxx"
#include "gen/mnem.hxx"

int main(int argc, const char *argv[]) {

	Tests t(std::cout);
	testConstStringMapOpcf(t);
	testConstStringMapMnem(t);
	t.summarize();

	return 0;
}

