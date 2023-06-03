set(subproject ngl-misc)

add_library(
  ${subproject}-lib
  ./Rectangle.cpp
)

target_compile_features(${subproject}-lib PRIVATE cxx_std_20)

target_compile_options(
  ${subproject}-lib
  PRIVATE $<$<CXX_COMPILER_ID:MSVC>:
    /W4
    /WX
    /external:anglebrackets 
    /external:W0
  >
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:


    -Wall 
    -Wextra 
    -Wshadow 
    -Wnon-virtual-dtor 
    -pedantic
    -Werror
    -std=c++20

    -Wno-unknown-pragmas
    -Wno-unused-command-line-argument
>)

target_include_directories(
  ${subproject}-lib 
  PUBLIC ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
  ${subproject}-lib 
  fmt::fmt
)
