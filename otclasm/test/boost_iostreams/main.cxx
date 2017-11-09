
#include <boost/iostreams/device/mapped_file.hpp>
#include <iostream>

using namespace std;
using namespace boost::iostreams;

int main(void) {
	mapped_file_source i;
	i.open("./Hello.txt");

	const char *it = i.data();
	const char *end = it + i.size();

	for (; it != end; ++it) {
		cout << *it;
	}
	cout << endl;

	return 0;
}

