#! /usr/bin/perl

print <<EOF;
/* THIS FILE IS GENERATED. */
#include <tclasm/ids_opcf.hxx>
#include <tclasm/ztstring.hxx>
#include <algorithm>


namespace tclasm {

	static const ztstring opcfIdTable[] = {
EOF
;

while (my $line = <STDIN>) {
	next if $line =~ m/^\s*$/;
	chomp $line;
	print "\t\tztstring(\"$line\"),\n";
}

print <<EOF;
		ztstring("_Z_END_OF_OPCF_E")
	};

	opcf_t getOpcfFromCstr(const char *cstr) {
		mnem_t res = END_OF_OPCF_E;
		ztstring zstr = ztstring(cstr);
		const unsigned tableSize = (sizeof(opcfIdTable) / sizeof(ztstring)) - 1;
		const ztstring
			*begin = &opcfIdTable[0],
			*end = begin + tableSize,
			*it = NULL;
		it = std::lower_bound(begin, end, zstr);
		//Note that also *end references a valid ztstring instance.
		if (it->cmp(zstr) == 0) {
			res = opcf_t(it - begin);
		}
		return res;
	}
	const char *getCstrFromOpcf(opcf_t opcf) {
		const char *res = 0;
		unsigned idx = (unsigned) opcf;
		const unsigned tableSize = (sizeof(opcfIdTable) / sizeof(ztstring)) - 1;
		if (idx > tableSize) {
			res = opcfIdTable[tableSize].data;
		} else {
			res = opcfIdTable[idx].data;
		}
		return res;
	}
}
EOF
;

