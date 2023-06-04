#!/bin/sh

mkdir build
cd ./build
mkdir Debug
mkdir Release

export CONAN_SYSREQUIRES_MODE=enabled
# std::bit_cast only starts being supported in gcc>11.1
# its literally not on the gcc website
# why is finding out how to change the default version of a program in linux so fucking obscure
# sudo apt install gcc-11
# sudo update-alternatives --remove-all gcc 
# sudo update-alternatives --remove-all g++
# sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 10
# sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 10
# sudo update-alternatives --install /usr/bin/cc cc /usr/bin/gcc 30
# sudo update-alternatives --set cc /usr/bin/gcc
# sudo update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++ 30
# sudo update-alternatives --set c++ /usr/bin/g++

cd Debug
conan install ../.. --output-folder=. --build=missing -pr:b=default --update -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True -s build_type=Debug
cd ../..
cmake -S . -B ./build/Debug -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE="./build/Debug/conan_toolchain.cmake"

cd ./build/Release
conan install ../.. --output-folder=. --build=missing -pr:b=default --update -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True -s build_type=Release
cd ../..
cmake -S . -B ./build/Release -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE="./build/Release/conan_toolchain.cmake"
