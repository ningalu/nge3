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
  ./Events/Event.cpp
  ./Events/EventQueue.cpp
  ./Events/KeySym.cpp
  ./Events/KeyMod.cpp
  ./Events/MouseButton.cpp
  ./EventTypes/DefaultEvent.cpp
  ./EventTypes/QuitEvent.cpp
  ./EventTypes/KeyUpEvent.cpp
  ./EventTypes/KeyDownEvent.cpp
  ./EventTypes/MouseButtonUpEvent.cpp
  ./EventTypes/MouseButtonDownEvent.cpp)

target_compile_features(ngsdl PRIVATE cxx_std_20)

target_include_directories(ngsdl PUBLIC ${CMAKE_SOURCE_DIR}/include/nge3/ngsdl)

target_link_libraries(ngsdl SDL2::SDL2main SDL2_image::SDL2_image
                      SDL2_ttf::SDL2_ttf)
