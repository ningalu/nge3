# NGE3

[![CMake](https://github.com/ningalu/nge3/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/ningalu/nge3/actions/workflows/cmake.yml)  
`cd ./build`  
`conan install .. -build=missing`  
`cd ..`  
`cmake -S . -B ./build -DCMAKE_TOOLCHAIN_FILE="build/conan_toolchain.cmake"`  
`cmake --build ./build --config Release`
