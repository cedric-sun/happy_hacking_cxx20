#!/bin/bash

CMAKE_BIN_DIR='cmake-build-debug'

for file in *; do
    if [[ -d $file && $file != $CMAKE_BIN_DIR ]]; then
        pushd $file > /dev/null
        ls -1 *.cc | awk -F'.' '{print "add_executable(" $1 " " $0 ")"}' > CMakeLists.txt
        popd > /dev/null
    fi
done
