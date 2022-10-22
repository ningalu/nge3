mkdir build
cd ./build
conan install .. --build=missing -pr:b=default --update --generator markdown -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
cd ..
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE="build/conan_toolchain.cmake"