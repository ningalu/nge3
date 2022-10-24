add_library(
    ngsdl
    ./Rectangle.cpp
    ./SDLException.cpp
    ./Window.cpp
    ./Renderer.cpp
    ./Point.cpp
    ./WindowFlags.cpp
    ./Texture.cpp
    ./RendererFlags.cpp
    ./BlendMode.cpp
    ./Events/Event.cpp
    ./Events/EventQueue.cpp
    ./Events/QuitEvent.cpp
    ./Events/KeyUpEvent.cpp
)

target_compile_features(
    ngsdl 
    PRIVATE cxx_std_17
)

target_include_directories(
    ngsdl
    PUBLIC ${CMAKE_SOURCE_DIR}/include/nge3/ngsdl
)

target_link_libraries(
    ngsdl
    SDL2::SDL2main
    SDL2_image::SDL2_image
    SDL2_ttf::SDL2_ttf
)