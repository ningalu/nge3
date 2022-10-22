cmake_minimum_required(VERSION 3.15)
project(nge3 CXX)

# SDL >2.0.20 doesn't export an SDL2main in MinGW/gcc?
find_package(SDL2)
find_package(SDL2_image)
find_package(SDL2_ttf)
find_package(nlohmann_json)
find_package(GTest)

add_executable(
    nge3_test_app 
    src/main.cpp
)
target_compile_features(
    nge3_test_app 
    PRIVATE cxx_std_17
)
target_include_directories(
    nge3_test_app
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(
    nge3_test_app
    PUBLIC ngsdl
)
add_custom_command(
    TARGET nge3_test_app
    POST_BUILD
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy_directory ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:nge3_test_app>/resources
)

enable_testing()
add_subdirectory(${CMAKE_SOURCE_DIR}/src/nge3/ngsdl)