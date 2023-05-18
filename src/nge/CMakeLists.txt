add_library(
  nge3 
  ./App.cpp 
  
  ./Timer.cpp 
  ./Graphics.cpp
  ./Input.cpp
  ./Scene.cpp
  ./SceneManager.cpp 
  ./SceneFactory.cpp 
  
  ./Components/Drawing/Component.cpp 
  ./Components/Drawing/Drawable.cpp 
  ./Components/Drawing/Rotatable.cpp 
  ./Components/Drawing/Translatable.cpp
  
  ./Components/Animation/AnimationController.cpp
  ./Components/Animation/FrameAnimationController.cpp
  
  ./Components/Mouse/ClickController.cpp
  ./Components/Mouse/HoverController.cpp
  ./Components/Mouse/Clickable.cpp
  ./Components/Mouse/BasicMouseUser.cpp

  ./Components/Sprite.cpp 
  ./Components/Text.cpp
  ./Components/AtlasAnimation.cpp
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

    -stdlib=libc++

    -Wall 
    -Wextra 
    -Wshadow 
    -Wnon-virtual-dtor 
    -pedantic
    -Werror

    -DLIBCXX_ENABLE_INCOMPLETE_FEATURES=ON

    -Wno-unknown-pragmas
    -Wno-unused-command-line-argument
>)

target_include_directories(
  nge3
  PUBLIC ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
  nge3 
  ngsdl
)
