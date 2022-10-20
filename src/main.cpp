#include <iostream>

#include "nge3/ngsdl/Point.h"
#include "nge3/ngsdl/Rectangle.h"
#include "nge3/ngsdl/Renderer.h"
#include "nge3/ngsdl/SDLException.h"
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
    sdl::Renderer r(w);
    // for (int i = 0; i < 10000; i++) {
    //   r.Present();
    // }
  } catch (sdl::SDLException &e) {
    std::cout << e.what() << "\n";
  }

  SDL_Quit();

  return 0;
}