#include <iostream>

#include "nge3/ngsdl/Rectangle.h"
#include "nge3/ngsdl/SDLException.h"
#include "nge3/ngsdl/Window.h"

int main(int argc, char **argv) {

  using namespace nge;

  sdl::Rect r(1, 2, 3, 4);

  std::cout << r;

  SDL_Init(SDL_INIT_EVERYTHING);

  try {
    sdl::Window w();
  } catch (sdl::SDLException &e) {
    std::cout << e.what() << "\n";
  }

  SDL_Quit();

  return 0;
}