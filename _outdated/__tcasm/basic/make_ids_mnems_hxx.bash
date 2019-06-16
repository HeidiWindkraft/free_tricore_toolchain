#! /usr/bin/perl

print <<EOF;
#ifndef TCLASM_IDS_MNEMS_HXX
#define TCLASM_IDS_MNEMS_HXX 1

/* THIS FILE IS GENERATED. */

#include <tclasm/ints.h>

namespace tclasm {

	enum mnem_e : uint8_t {
EOF
;

while (my $line = <STDIN>) {
	next if $line =~ m/^\s*$/;
	chomp $line;
	$line =~ s/\./_/g;
	print "\t\t$line,\n";
}

print <<EOF;
		END_OF_MNEM_E
	};
	typedef enum mnem_e mnem_t;

	mnem_t getMnemFromCstr(const char *cstr);
	const char *getCstrFromMnem(mnem_t mnem);
}
EOF
;

