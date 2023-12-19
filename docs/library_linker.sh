#!/usr/bin/env bash
#/-------------------------
# Meant to be ran from the docs directory
#-------------------------/

sudo -k
set -eou pipefail

PWD=$(pwd)

#/ Find and Link Compiled Libraries against shared objects
link_shared_objects() {
    cd ./lib;
    for dir in `find ../ -type f -iname "*.so.*"`; do
        lnk="${dir##*/}";            # Strip Leading Path
        echo -e "Linking ${lnk%.*}"; # Debug line
        ln -s $dir "${lnk%.*}";      # Do Linking
    done
    ls -lah .;
    cd -;
}

link_shared_objects;
