#! /usr/bin/perl

print <<EOF;
/* THIS FILE IS GENERATED. */
#include <tclasm/ids_mnems.hxx>
#include <tclasm/ztstring.hxx>
#include <algorithm>


namespace tclasm {

	static const ztstring mnemIdTable[] = {
EOF
;

while (my $line = <STDIN>) {
	next if $line =~ m/^\s*$/;
	chomp $line;
	print "\t\tztstring(\"$line\"),\n";
}

print <<EOF;
		ztstring("_Z_END_OF_MNEM_E")
	};

	mnem_t getMnemFromCstr(const char *cstr) {
		mnem_t res = END_OF_MNEM_E;
		ztstring zstr = ztstring(cstr);
		const unsigned tableSize = (sizeof(mnemIdTable) / sizeof(ztstring)) - 1;
		const ztstring
			*begin = &mnemIdTable[0],
			*end = begin + tableSize,
			*it = NULL;
		it = std::lower_bound(begin, end, zstr);
		//Note that also *end references a valid ztstring instance.
		if (it->cmp(zstr) == 0) {
			res = mnem_t(it - begin);
		}
		return res;
	}
	const char *getCstrFromMnem(mnem_t mnem) {
		const char *res = 0;
		unsigned idx = (unsigned) mnem;
		const unsigned tableSize = (sizeof(mnemIdTable) / sizeof(ztstring)) - 1;
		if (idx > tableSize) {
			res = mnemIdTable[tableSize].data;
		} else {
			res = mnemIdTable[idx].data;
		}
		return res;
	}
}
EOF
;

