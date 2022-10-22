#include <iostream>

#include "nge3/ngsdl/Point.h"
#include "nge3/ngsdl/Rectangle.h"
#include "nge3/ngsdl/Renderer.h"
#include "nge3/ngsdl/RendererFlags.h"
#include "nge3/ngsdl/SDLException.h"
#include "nge3/ngsdl/Texture.h"
#include "nge3/ngsdl/Window.h"
#include "nge3/ngsdl/WindowFlags.h"

int main(int argc, char **argv) {

  using namespace nge;

  sdl::Rect r(1, 2, 3, 4);
  std::cout << r << "\n";
  sdl::Point p(5, 6);
  std::cout << p << "\n";

  SDL_Init(SDL_INIT_EVERYTHING);
  try {
    sdl::Window w;
    auto r = sdl::Renderer{w, -1,
                           sdl::RendererFlags::ACCELERATED |
                               sdl::RendererFlags::TARGETTEXTURE};

    sdl::Texture t = {r, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,
                      500, 500};
    SDL_Event buf;
    bool running = true;
    while (running) {
      r.Clear();
      r.Copy(t, {0, 0, 500, 500}, {50, 50, 550, 550});
      r.Present();
      while (SDL_PollEvent(&buf)) {
        switch (buf.type) {
        case SDL_QUIT:
          goto end;
        }
      }
    }
  } catch (sdl::SDLException &e) {
    std::cout << e.what() << "\n";
  }
end:

  SDL_Quit();

  return 0;
}