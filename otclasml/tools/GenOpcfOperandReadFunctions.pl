#! /usr/bin/perl

use warnings;
use strict;

print <<EOF;
/* \$Id\$
 * (L)
*/
#ifndef OTCLASML_OPERAND_READERS_HXX
#define OTCLASML_OPERAND_READERS_HXX 1

#include <otclasml/insnir.hxx>
#include <otclasml/tokensx.hxx>


namespace otclasml { namespace {

EOF
;

my %cTypeMap = (
	'regIdx' => 'RegIdx',
	'lab'    => 'Label',
	'imm'    => 'Imm',
	'uint8'  => 'UInt8',
);

while (my $line = <STDIN>) {
	next if $line =~ /^\s*$/;
	next if $line =~ /^\s*#.*$/;

	#print STDERR "LINE: \"$line\"\n";
	chomp $line;
	#print STDERR "LINE: \"$line\"\n";
	$line = $1 if $line =~ m/^\s+(.*)$/;
	#print STDERR "LINE: \"$line\"\n";


	my $commentindex = index $line, '#';
	$line = (substr $line, 0, $commentindex) if $commentindex != -1;

	my @comps = split /\s+/, $line;
	my $opcf = $comps[0];
	my $lopcf = lc $opcf;
	#print STDERR "COMPS: ".(join ',', @comps)."\n";


	print "void readOperands$opcf(symboltable_in syms, insnir_t &insn, line_stream_t &stream) {\n";
	for (my $i = 1; $i < @comps; ++$i) {
		my ($name, $type) = split /:/, $comps[$i];
		my $ltype = $cTypeMap{$type};
		die "In $opcf: Unknown type \"$type\" for \"$name\"." if not defined $ltype;
		print "\tinsn.a.$lopcf.$name = next$ltype(syms, stream);\n";
	}
	print "}\n";
	print "\n";
}

print <<EOF;

}}

#endif /* OTCLASML_OPERAND_READERS_HXX */

EOF
;

