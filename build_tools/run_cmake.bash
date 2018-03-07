#!/bin/bash
#
# 1) Copy this file to your build directory  (say, ~/skeleton_builds/build_dev)
# 2) Set MY_CMAKE_DIR to the root path of your project tree (the directory where you have "CMakeLists.txt")
# 3) Edit the location of your statically compiled libraries you want to encapsulate into this library
# 4) Being in the build directory, run this script
#

# define the location of the statically compiled library:
demo_lib_path="-Ddemo_root="$HOME"/C/skeleton/demo_dep"

options="-Dverbose=OFF "$demo_lib_path

# # Choose the distro type:
build_type="Debug"
# build_type="Release"

# give absolute path to your CMakeLists.txt
MY_CMAKE_DIR=/home/sampsa/C/skeleton

echo
echo $MY_CMAKE_DIR
echo
cmake $options -DCMAKE_BUILD_TYPE=$build_type $MY_CMAKE_DIR
echo
echo Run \"make\" or \"make VERBOSE=1\" to compile
echo Run \"make package\" to generate the .deb package
echo
