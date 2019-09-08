#!/usr/bin/env bash

scriptdir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

makenode=$1
codir=$2
giturl=$3
gittag=$4
submod=$5

if [ $# != 5 ]; then
  echo "ERROR: $0: Invalid arguments count: $#" 1>&2
  cat <<EOH 1>&2
USAGE
  $0 makenode codir giturl gittag submod
ARGUMENTS
  makenode
    The makenode file can be used as make dependency.
  codir
    The directory to which the given giturl shall be cloned.
  giturl
    The URI of the git repository which shall be cloned.
  gittag
    The tag which shall be checked out.
  submod
    Submodule specifier:
      none     : if there are no git submodules
      recursive: to initialize submodules recursively
DESCRIPTION
  If neither 'logfile' nor 'codir' already exist,
  this script checksout to given tag 'gittag' of the git repository
  specified by 'giturl' to 'codir'.
EOH
  exit 1;
fi

# makenode codir
#      x     x  | checkout and write makenode
#      x     E  | write makenode
#      E     x  | checkout and write makenode
#      E     E  | update makenode if necessary


if [ -e "${codir}" ]; then
  echo "INFO: $0: Skipping checkout of ${giturl} / ${gittag}, because \"${codir}\" already exists." 1>&2
else
  mkdir -p "${codir}"
  git clone "${giturl}" "${codir}"
  pushd "${codir}"
  git checkout "${gittag}"
  if [ "${submod}" == "recursive" ]; then
    git submodule init
    git submodule update --recursive
  fi
  popd
  #date --iso-8601=ns >> "${logfile}"
fi

echo "INFO: $0: Checking whether make-node \"${makenode}\" needs an update" 1>&2
"${scriptdir}/copy_if_different.bash" <("${scriptdir}/get_checkout_description.bash" "${codir}") "${makenode}"
