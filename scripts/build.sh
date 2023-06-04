#!/bin/sh

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

cmake --build ./build/Debug --config Debug
cmake --build ./build/Release --config Release