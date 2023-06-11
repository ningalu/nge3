mkdir build
cd ./build
mkdir Debug
mkdir Release
cd ..

conan install . ^
 --output-folder=./build/Debug ^
 --build=missing ^
 -pr:b=default ^
 --update ^
 -c tools.system.package_manager:mode=install ^
 -c tools.system.package_manager:sudo=True ^
 -c build_type=Debug ^
 -s build_type=Debug 
@REM  -c tools.cmake.cmaketoolchain:generator=Ninja

cmake ^
 -S . ^
 -B ./build/Debug ^
 -DCMAKE_BUILD_TYPE=Debug ^
 -DCMAKE_TOOLCHAIN_FILE="./build/Debug/conan_toolchain.cmake" ^
 -DCMAKE_EXPORT_COMPILE_COMMANDS=ON . 
@REM  -G Ninja



conan install . ^
 --output-folder=./build/Release ^
 --build=missing ^
 -pr:b=default ^
 --update ^
 -c tools.system.package_manager:mode=install ^
 -c tools.system.package_manager:sudo=True ^
 -c build_type=Release ^
 -s build_type=Release 
@REM  -c tools.cmake.cmaketoolchain:generator=Ninja

cmake ^
 -S . ^
 -B ./build/Release ^
 -DCMAKE_BUILD_TYPE=Release ^
 -DCMAKE_TOOLCHAIN_FILE="./build/Release/conan_toolchain.cmake" ^
 -DCMAKE_EXPORT_COMPILE_COMMANDS=ON . 
@REM  -G Ninja
