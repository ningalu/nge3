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

target_compile_options(
  ngsdl
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
    -Werror

    # Clashes with an MSVC pragma
    -Wno-unknown-pragmas
  >)

target_include_directories(ngsdl PUBLIC ${CMAKE_SOURCE_DIR}/include/nge3/ngsdl)

target_link_libraries(ngsdl SDL2::SDL2main SDL2_image::SDL2_image
                      SDL2_ttf::SDL2_ttf)
