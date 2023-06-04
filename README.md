# NGE3

[![CMake](https://github.com/ningalu/nge3/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/ningalu/nge3/actions/workflows/cmake.yml)

A toy GUI framework based on SDL2 and its supporting libraries  
Building on Windows 10/MSVC 19, WSL Ubuntu 20.04/GCC 11.1, macOS Ventura 13 x86_64/apple clang 14  
Something appears to be profoundly broken in the MSYS2 toolchain that Conan uses so MinGW unfortunately does not work

## Build

- Install dependencies using Conan (>=2.0)  
  `mkdir build`
  `cd build`
  `conan install .. --output-folder=. --build=missing -pr:b=default --update -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True -s build_type=Debug`
- Configure the CMake (>=3.15) project  
  `cd ..`  
  `cmake -S . -B ./build/Debug -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE="./build/conan_toolchain.cmake"`
- Build the project  
  `cmake --build ./build`

Or however that looks on your system, making sure your build types are consistent  
Otherwise `/scripts/clean` -> `/scripts/configure` -> `/scripts/build`

## WSL Ubuntu 20.04 / GCC 11

As of current moment libunwind/1.6.2 has a dependency on xz_utils/5.4.0 which might have to be manually overridden or maybe not but I can't find any documentation about it because Conan 2.0 is still pretty new so change it in `~/.conan2/libun.../e/conanfile.py` around line 56

You will also need to use >=GCC 11.1; set this in your Conan profile

```
[buildenv]
CC=gcc-11
CXX=g++-11
```

and make sure that you do something like

```
sudo apt install gcc-11
sudo update-alternatives --remove-all gcc
sudo update-alternatives --remove-all g++
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 10
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 10
sudo update-alternatives --install /usr/bin/cc cc /usr/bin/gcc 30
sudo update-alternatives --set cc /usr/bin/gcc
sudo update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++ 30
sudo update-alternatives --set c++ /usr/bin/g++
```

to force everything to use GCC 11

## macOS Ventura 13 x86_64/apple clang 14

This is why fmtlib is still a dependency
