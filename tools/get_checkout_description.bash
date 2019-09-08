#!/usr/bin/env bash

codir=$1

if [ $# != 1 ]; then
  echo "ERROR: $0: Invalid arguments count: $#" 1>&2
  cat <<EOH 1>&2
USAGE
  $0 codir
ARGUMENTS
  codir
    A git working copy / checkout directory.
DESCRIPTION
  Emits a description of the working copy / checkout directory.
EOH
  exit 1;
fi

cd "${codir}"
echo "# COMMIT HASH"
git rev-parse HEAD
echo "# HASH OF STAGED COMMITS"
git diff --staged | sha1sum
echo "# HASH OF UNSTAGED COMMITS"
git diff | sha1sum
echo "# STATUS"
git status --short
echo "# SUBMODULE STATUS"
git submodule status
echo "# HASH OF STAGED SUBMODULE COMMITS"
git submodule foreach --recursive git diff --staged | sha1sum
echo "# HASH OF UNSTAGED SUBMODULE COMMITS"
git submodule foreach --recursive git diff | sha1sum
echo "# END"
