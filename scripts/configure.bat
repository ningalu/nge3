mkdir build
cd ./build
mkdir Debug
mkdir Release

cd Debug
conan install ../.. --output-folder=. --build=missing -pr:b=default --update -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True -s build_type=Debug
cd ../..
cmake -S . -B ./build/Debug -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE="./build/Debug/conan_toolchain.cmake"

cd ./build/Release
conan install ../.. --output-folder=. --build=missing -pr:b=default --update -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True -s build_type=Release
cd ../..
cmake -S . -B ./build/Release -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE="./build/Release/conan_toolchain.cmake"