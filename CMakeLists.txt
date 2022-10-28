cmake_minimum_required(VERSION 3.15)
project(nge3 CXX)

set(ngsdl_app ngsdl_test_app)
set(nge3_app nge3_test_app)

# SDL >2.0.20 doesn't export an SDL2main in MinGW/gcc?
find_package(SDL2)
find_package(SDL2_image)
find_package(SDL2_ttf)
find_package(nlohmann_json)
find_package(GTest)

# Declare ngsdl and nge3 libs
add_subdirectory(${CMAKE_SOURCE_DIR}/src/nge3/ngsdl)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/nge3/nge3)

# NGSDL test app target setup
add_executable(${ngsdl_app} src/ngsdl_test_app.cpp)
target_compile_features(${ngsdl_app} PRIVATE cxx_std_20)
target_include_directories(${ngsdl_app} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${ngsdl_app} PUBLIC ngsdl)
add_custom_command(
  TARGET ${ngsdl_app}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} ARGS -E copy_directory ${CMAKE_SOURCE_DIR}/resources
          $<TARGET_FILE_DIR:${ngsdl_app}>/resources)

# NGE3 test app target setup
add_executable(${nge3_app} src/nge3_test_app.cpp)
target_compile_features(${nge3_app} PRIVATE cxx_std_20)
target_include_directories(${nge3_app} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${nge3_app} PUBLIC ngsdl nge3)
add_custom_command(
  TARGET ${nge3_app}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} ARGS -E copy_directory ${CMAKE_SOURCE_DIR}/resources
          $<TARGET_FILE_DIR:${nge3_app}>/resources)

# Set up unit tests
enable_testing()
add_subdirectory(${CMAKE_SOURCE_DIR}/tests)
