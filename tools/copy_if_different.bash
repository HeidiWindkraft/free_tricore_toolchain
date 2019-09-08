#!/usr/bin/env bash

fileA=$1
fileB=$2

if [ $# != 2 ]; then
  echo "ERROR: $0: Invalid arguments count: $#" 1>&2
  cat <<EOH 1>&2
USAGE
  $0 fileA fileB
DESCRIPTION
  Compares fileA and fileB.
  If they differ, fileA is copied to overwrite fileB.
  Otherwise the files aren't touched.
EOH
  exit 1;
fi

if [ -e "${fileB}" ]; then
  cmp --silent "${fileA}" "${fileB}" || (echo "INFO: $0: Overwriting file \"${fileB}\"" 1>&2; cat "${fileA}" > "${fileB}")
else
  echo "INFO: $0: Overwriting inexistent file \"${fileB}\"" 1>&2;
  cp "${fileA}" "${fileB}"
fi
