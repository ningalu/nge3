add_library(nge3 App.cpp View.cpp Component.cpp Timer.cpp Graphics.cpp)

target_compile_features(nge3 PRIVATE cxx_std_20)
target_compile_options(
  nge3
  PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/W4
          /Wall
          /WX
          /wd4820
          /wd5045>
          $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall
          -Wextra
          -Wpedantic
          -Werror>)
target_include_directories(
  nge3
  PUBLIC ${CMAKE_SOURCE_DIR}/include
  PUBLIC ${CMAKE_SOURCE_DIR}/include/nge3
  PUBLIC ${CMAKE_SOURCE_DIR}/include/nge3/nge)

target_link_libraries(nge3 ngsdl)