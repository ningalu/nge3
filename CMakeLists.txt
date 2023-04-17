cmake_minimum_required(VERSION 3.15)
project(nge3 CXX)

find_package(SDL2)
find_package(SDL2_image)
find_package(SDL2_ttf)
find_package(nlohmann_json)
find_package(GTest)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/ngsdl)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/ngsdl_demo)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/nge)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/demo)

# # Set up unit tests
enable_testing()
add_subdirectory(${CMAKE_SOURCE_DIR}/tests/ngsdl)
