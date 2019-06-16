#! /usr/bin/perl

print <<EOF;
#ifndef TCLASM_IDS_MNEMS_HXX
#define TCLASM_IDS_MNEMS_HXX 1

/* THIS FILE IS GENERATED. */

#include <tclasm/ints.h>

namespace tclasm {

	enum opcf_e : uint8_t {
EOF
;

while (my $line = <STDIN>) {
	next if $line =~ m/^\s*$/;
	chomp $line;
	$line =~ s/\./_/g;
	print "\t\t$line,\n";
}

print <<EOF;
		END_OF_OPCF_E
	};
	typedef enum opcf_e opcf_t;

	opcf_t getOpcfFromCstr(const char *cstr);
}
EOF
;

