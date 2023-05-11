#!/bin/zsh

# why is this literally the easiest solution
# alias gcc="gcc-10"
# alias g++="g++-10"
# export CC=gcc-10
# export CXX=g++-10

cmake --build ./build/Debug --config Debug
cmake --build ./build/Release --config Release