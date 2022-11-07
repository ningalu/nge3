add_library(demo ./IntroView.cpp)

target_compile_features(demo PRIVATE cxx_std_20)
target_compile_options(
  demo
  PRIVATE $<$<CXX_COMPILER_ID:MSVC>:
    /W4
    /Wall
    /WX

    # Padding added to class
    /wd4820

    # Qspectre thing
    /wd5045

    # Function not inlined
    /wd4710

    # Selected for automatic inline expansion
    /wd4711

    /external:anglebrackets 
    /external:W0
  >
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:
    -Wall 
    -Wextra 
    -Wshadow 
    -Wnon-virtual-dtor 
    -pedantic
    # -Werror

    # Clashes with an MSVC pragma
    -Wno-unknown-pragmas
  >)
target_include_directories(
  demo
  PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(demo nge3)