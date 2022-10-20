add_library(
    ngsdl
    ./Rectangle.cpp
    ./SDLException.cpp
    ./Window.cpp
    ./Renderer.cpp
    ./Point.cpp
    ./WindowFlag.cpp
    ./Texture.cpp
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
    sdl_image::sdl_image
    SDL2_ttf::SDL2_ttf
)