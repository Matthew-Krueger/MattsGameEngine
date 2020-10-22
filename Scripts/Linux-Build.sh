#!/bin/bash

# Setup
echo "Ensuring Submodules are cloned."
git submodule update --init --recursive || exit

# CMake
echo "Configuring CMake."
mkdir -p Build
cd Build || exit
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../_install .. || exit
echo "Configuring CMake done."

# C Compiling
echo "Compiling the engine and example meta package"
make Matts_Game_Engine-Examples
echo "Engine and example meta package compiled"
mkdir -p bin || exit
cp Sources/*/lib* bin/ || exit
cp Sources/Examples/*/Example* bin/ || exit


# Doxygen
echo "Cleaning Old Doxygen"
rm -rf ../Docs || exit
echo "Making Doxygen"
make Matts_Game_Engine-Doxygen

# Archive Doxygen
echo "Archive Doxygen"
tar cvzf bin/Docs.tgz ../Docs