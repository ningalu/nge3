add_library(
  nge3 
  App.cpp 
  View.cpp 
  Timer.cpp 
  Graphics.cpp

  Components/Component.cpp 
  Components/SimpleComponent.cpp 
  Components/Sprite.cpp 
  Components/Text.cpp 
  Components/Drawable.cpp 
  Components/Rotatable.cpp 
  Components/Translatable.cpp 
)

target_compile_features(nge3 PRIVATE cxx_std_20)
target_compile_options(
  nge3
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
  nge3
  PUBLIC ${CMAKE_SOURCE_DIR}/include
  PUBLIC ${CMAKE_SOURCE_DIR}/include/nge3
  PUBLIC ${CMAKE_SOURCE_DIR}/include/nge3/nge)

target_link_libraries(nge3 ngsdl)
