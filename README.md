# NGE3

[![CMake](https://github.com/ningalu/nge3/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/ningalu/nge3/actions/workflows/cmake.yml)

A toy GUI framework based on SDL2 and its supporting libraries  
Building on Windows 10/MSVC 19, Ubuntu 20.04/GCC 10.3, macOS Ventura 13 x86_64/clang 14

## Build

- Install dependencies using Conan (>=1.53)  
  `mkdir build && cd build`
  `conan install .. --build=missing -pr:b=default -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True`
- Configure the CMake (>=3.15) project  
  `cd ..`  
  `cmake -S . -B ./build -DCMAKE_TOOLCHAIN_FILE="./build/conan_toolchain.cmake"`
- Build the project  
  `cmake --build ./build`

Be careful about having a consistent build type, see the `configure` scripts in the `buildscripts` folder for examples on specifying build types in Conan and CMake
