#!/bin/sh
mkdir build
cd ./build
export CONAN_SYSREQUIRES_MODE=enabled
conan install .. --build=missing -pr:b=default --update --generator markdown -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
cd ..
cmake -S . -B ./build