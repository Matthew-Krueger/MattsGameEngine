#!/bin/bash
echo "Ensuring Submodules are cloned."
git submodule update --init --recursive || exit
echo "Configuring CMake."
mkdir -p Build
cd Build || exit
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../_install .. || exit
echo "Configuring CMake done."
make Matts_Game_Engine-Examples
cp Sources/*/lib* bin/ || exit
cp Sources/Examples/*/Example* bin/ || exit
