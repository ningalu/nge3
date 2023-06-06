add_library(
  ngsdl
  ./SDLException.cpp
  ./TTFException.cpp
  ./Point.cpp
  ./Rectangle.cpp
  ./Color.cpp
  ./Window.cpp
  ./WindowFlags.cpp
  ./Renderer.cpp
  ./RendererFlags.cpp
  ./RendererFlip.cpp
  ./Texture.cpp
  ./BlendMode.cpp
  ./Timer.cpp
  ./Font.cpp
  ./Init.cpp
  ./InitFlags.cpp
  ./Surface.cpp

  ./Events/Event.cpp
  ./Events/EventQueue.cpp
  ./Events/KeySym.cpp
  ./Events/KeyMod.cpp
  ./Events/MouseButton.cpp
  ./Events/MouseButtonMask.cpp

  ./EventTypes/DefaultEvent.cpp
  ./EventTypes/QuitEvent.cpp
  ./EventTypes/KeyUpEvent.cpp
  ./EventTypes/KeyDownEvent.cpp
  ./EventTypes/MouseButtonUpEvent.cpp
  ./EventTypes/MouseButtonDownEvent.cpp
)

target_compile_features(ngsdl PRIVATE cxx_std_20)

target_compile_options(
  ngsdl
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
  ngsdl 
  PUBLIC ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
  ngsdl 
  SDL2::SDL2main 
  SDL2_image::SDL2_image       
  sdl_ttf::sdl_ttf
  ngl-misc-lib
)
