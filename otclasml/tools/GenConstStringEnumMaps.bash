#! /bin/bash


TOOL_BASE=.
IN_BASE=$TOOL_BASE/ConstMaps
HO_BASE=../src/otclasml/cmaps
CO_BASE=../src/otclasml/cmaps

if [ ! -e $TOOL_BASE ]; then
	echo "Called in wrong working directory! Doesn't exist: $TOOL_BASE"
	exit 1
fi
if [ ! -e $IN_BASE ]; then
	echo "Called in wrong working directory! Doesn't exist: $IN_BASE"
	exit 1
fi
if [ ! -e $HO_BASE ]; then
	echo "Called in wrong working directory! Doesn't exist: $HO_BASE"
	exit 1
fi
if [ ! -e $CO_BASE ]; then
	echo "Called in wrong working directory! Doesn't exist: $CO_BASE"
	exit 1
fi

GEN=$TOOL_BASE/GenConstStringEnumMap.pl

ID=opcf
$GEN otclasml $ID $HO_BASE/$ID.hxx $CO_BASE/$ID.cxx.hxx otclasml/cmaps/$ID.hxx lc < $IN_BASE/$ID.txt

ID=mnem
$GEN otclasml $ID $HO_BASE/$ID.hxx $CO_BASE/$ID.cxx.hxx otclasml/cmaps/$ID.hxx lc < $IN_BASE/mnems.txt


