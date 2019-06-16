#! /usr/bin/perl

use warnings;
use strict;

my $USAGE = <<EOF;
Usage:
	GenConstStringEnumMap namespace id path/to/header.hxx path/to/cxxfile.cxx path/to/header/from/includepaths (lc|id) path/to/test.hxx [include_util_prefix] < ids.txt
EOF
;

my ($aNamespace, $aId, $aHeader, $aCxxFile, $aHeaderInclude, $aLc, $aTest, $aInclude) = @ARGV;

die $USAGE unless (defined $aNamespace && defined $aId && defined $aHeader && defined $aCxxFile && defined $aHeaderInclude && defined $aLc && defined $aTest);

$aInclude ||= "otclasml";

my $fnLc = sub {
	my ($a) = @_;
	return lc $a;
};
my $fnId = sub {
	my ($a) = @_;
	return $a;
};

my $aUId = uc $aId;
my $aLId = lc $aId;
my $aUcId = (substr $aUId, 0, 1).(substr $aLId, 1);
my $aUNamespace = uc $aNamespace;
my $aKeyFn = ($aLc eq 'lc') ? $fnLc : $fnId;

my %map = ( );


while (my $line = <STDIN>) {
	next if $line =~ /^\s*$/;
	next if $line =~ /^#/;
	my $str = undef;
	my $enum = undef;
	if ($line =~ m/^\s*([^\s]+)\s*$/) {
		$str = $1;
		$enum = $str;
		$enum =~ s/[^a-zA-Z0-9_]/_/g;
	} elsif ($line =~ m/^\s*([^\s]+)\s*([^\s]+)\s*$/) {
		$str = $1;
		$enum = $2;
	}
	$str = $aKeyFn->($str);
	my $cur = $map{$str};
	if ((defined $cur) && ($cur ne $enum)) {
		die "ERROR: Conflicting mappings for \"$str\": \"$cur\" and \"$enum\".";
	}
	$map{$str} = $enum;
}

# TODO care about the right locale...
my @keys = sort keys %map;
my $nkeys = @keys;
my $inttype;
if ($nkeys >= 0x10000) {
	$inttype = "uint32_t";
} elsif ($nkeys >= 0x100) {
	$inttype = "uint16_t";
} else {
	$inttype = "uint8_t";
}

# #### ####
# HEADER
# ### ####
my $fHeader;
open ($fHeader, '>', $aHeader) or die "Could not open \"$aHeader\" for writing: $!";
print $fHeader <<EOF;
/* \$Id\$
 * (L)
*/
#ifndef ${aUNamespace}_${aUId}_HXX
#define ${aUNamespace}_${aUId}_HXX 1

#include <$aInclude/StringView.hxx>
#include <$aInclude/inttypes.hxx>
#include <$aInclude/ConstStringMap.hxx>

namespace $aNamespace { namespace $aId {

// There are $nkeys entries.
enum ${aLId}s_e : $inttype {
EOF
;

for my $key (@keys) {
	my $val = $map{$key};
	print $fHeader "\t$val,\n";
}

print $fHeader <<EOF;
	NENTRIES
}; /* enum */

namespace ${aId}_detail {
	extern const ConstStringMap::String ${aLId}_strings[NENTRIES + 1];
}

inline ${aLId}s_e to$aUcId(StringView s) {
	return (${aLId}s_e) ConstStringMap::fromString(s, ${aId}_detail::${aLId}_strings, (uintn_t) NENTRIES);
}
inline StringView ${aLId}ToString(uintn_t val) {
	return ConstStringMap::toString(val, ${aId}_detail::${aLId}_strings, (uintn_t) NENTRIES);
}
inline StringView toString(${aLId}s_e val) { return ${aLId}ToString(($inttype) val); }

} } /* namespaces */
#endif /* _HXX */

EOF
;

close ($fHeader);
$fHeader = undef;
# #### ####
# END of HEADER
# ### ####


# #### ####
# CXX_FILE
# ### ####
my $fCxxFile;
open ($fCxxFile, '>', $aCxxFile) or die "Could not open \"$aCxxFile\" for writing: $!";
print $fCxxFile <<EOF;
/* \$Id\$
 * (L)
*/

#include <$aHeaderInclude>
#include <$aInclude/StringView.hxx>
#include <$aInclude/inttypes.hxx>
#include <$aInclude/ConstStringMap.hxx>

namespace $aNamespace { namespace $aId { namespace ${aId}_detail {

const ConstStringMap::String ${aLId}_strings[NENTRIES + 1] = {
EOF
;

my $i = 0;
for my $key (@keys) {
	my $len = length $key;
	my $val = $map{$key};
	print $fCxxFile "\t{ \"$key\", $len }, // $i: $val\n";
	++$i;
}

my $endString = "~[invalid~entry~$aId]~";
my $lenEnd = length $endString;
print $fCxxFile <<EOF;
	{ \"$endString\", $lenEnd }
}; /* strings */

} } } /* namespaces */

EOF
;

close ($fCxxFile);
$fCxxFile = undef;
# #### ####
# END of CXX_FILE
# ### ####

# #### ####
# TEST_FILE
# ### ####
my $fTestFile;
open ($fTestFile, '>', $aTest) or die "Could not open \"$aTest\" for writing: $!";
print $fTestFile <<EOF;
/* \$Id\$
 * (L)
*/
#ifndef TEST_${aUNamespace}_${aUId}_HXX
#define TEST_${aUNamespace}_${aUId}_HXX

#include <$aHeaderInclude>
#include <testfx.hxx>
#include <$aInclude/ConstStringMapCmp.hxx>
#include <algorithm>
#include <vector>

void testConstStringMap${aUcId}(Tests &t) {
	using namespace $aNamespace::$aId;
	using namespace $aNamespace;

	t.startGroup("testConstStringMap${aUcId}");

	t.start("${aLId}_strings");
	bool issorted = std::is_sorted(${aId}_detail::${aLId}_strings, ${aId}_detail::${aLId}_strings + NENTRIES, ConstStringMap::Less());
	t.eq(true, issorted, "is_sorted");
	if (!issorted) {
		std::cout << "      IS NOT SORTED (" << NENTRIES << ")" << std::endl;
		std::vector<ConstStringMap::String> vec;
		vec.reserve(NENTRIES);
		for (uintn_t i = 0; i < NENTRIES; ++i) {
			vec.push_back( ${aId}_detail::${aLId}_strings[i] );
		}
		std::sort(vec.begin(), vec.end(), ConstStringMap::Less());
		for (uintn_t i = 0; i < NENTRIES; ++i) {
			const char *a = ${aId}_detail::${aLId}_strings[i].data;
			const char *b = vec[i].data;
			std::cout << "        " << (a == b) << " " << a << " " << b << std::endl;
		}
	}
	t.stop();

	t.start("to$aUcId");
EOF
;

for my $key (@keys) {
	my $len = length $key;
	my $val = $map{$key};
	print $fTestFile "\tt.eq($val, to$aUcId(\"$key\"), \"$key\");\n";
}

print $fTestFile <<EOF;
	t.eq(NENTRIES, to$aUcId("//"), "invalid entry");
	t.stop();

	t.start("toString");
EOF
;

for my $key (@keys) {
	my $len = length $key;
	my $val = $map{$key};
	print $fTestFile "\tt.eq(StringView(\"$key\", $len), toString($val), \"$key\");\n";
}

print $fTestFile <<EOF;
	t.stop();
	t.stopGroup();
} // testConstStringMap${aUcId}

#endif // _HXX

EOF
;

close ($fTestFile);
$fTestFile = undef;
# #### ####
# END of TEST_FILE
# ### ####

