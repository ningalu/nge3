cmake_minimum_required(VERSION 3.15)
project(nge3 CXX)

# why does my cmake manage to find versions of gcc other than 11 when its set as 11 everywhere i can find
if (UNIX)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED true)
  set(CMAKE_CXX_COMPILER g++-11)
  set(CMAKE_C_COMPILER gcc-11)
endif(UNIX)

# painful to do per target
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)


find_package(SDL2)
find_package(SDL2_image)
find_package(SDL2_ttf)
find_package(nlohmann_json)
find_package(fmt)
find_package(GTest)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/misc)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/ngsdl)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/ngsdl_demo)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/nge)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/demo)

# # Set up unit tests
enable_testing()
add_subdirectory(${CMAKE_SOURCE_DIR}/tests/ngsdl)
add_subdirectory(${CMAKE_SOURCE_DIR}/tests/misc)
