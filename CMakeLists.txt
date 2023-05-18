cmake_minimum_required(VERSION 3.15)
project(nge3 CXX)

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

add_subdirectory(${CMAKE_SOURCE_DIR}/src/ngsdl)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/ngsdl_demo)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/nge)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/demo)

# # Set up unit tests
enable_testing()
add_subdirectory(${CMAKE_SOURCE_DIR}/tests/ngsdl)
