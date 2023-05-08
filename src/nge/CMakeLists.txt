add_library(
  nge3 
  ./App.cpp 
  
  ./Timer.cpp 
  ./Graphics.cpp
  ./Input.cpp
  ./Scene.cpp
  ./SceneFactory.cpp 
  
  ./Components/Component.cpp 
  ./Components/SimpleComponent.cpp 
  ./Components/Sprite.cpp 
  ./Components/Text.cpp 
  ./Components/Drawable.cpp 
  ./Components/Rotatable.cpp 
  ./Components/Translatable.cpp
)

target_compile_features(
  nge3 
  PRIVATE cxx_std_20
)

target_compile_options(
  nge3
  PRIVATE $<$<CXX_COMPILER_ID:MSVC>:
    /W4
    /WX
    /external:anglebrackets 
    /external:W0
  >
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:

    -lstdc++

    -Wall 
    -Wextra 
    -Wshadow 
    -Wnon-virtual-dtor 
    -pedantic
    -Werror

    -Wno-unknown-pragmas
>)

target_include_directories(
  nge3
  PUBLIC ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
  nge3 
  ngsdl
)
