#!/usr/bin/env bash
#/-------------------------
# Meant to be ran from the main directory
#-------------------------/

sudo -k
set -eou pipefail
declare -a sharedf;

locate_shared_objects() {
    cd lib/;
    for dir in `find ./ -type f -iname "*.so.*"`; do
        echo -e "Linking $dir";
        ln -s $dir "${dir%.*}";
    done
    cd -;
}

locate_shared_objects;
