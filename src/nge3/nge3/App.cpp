#include "App.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include "ngsdl/Renderer.h"
#include "ngsdl/SDLException.h"
#include "ngsdl/TTFException.h"
#include "ngsdl/Window.h"

#include <iostream>

namespace nge {
App::App() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    throw sdl::SDLException("SDL couldn't be initialised");
  }
  // IMG_Init is cringe and uses 0 as a failure code
  if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0) {
    throw sdl::SDLException("SDL_image couldn't be initialised");
  }
  if (TTF_Init() != 0) {
    throw sdl::TTFException("SDL_ttf couldn't be initialised");
  }
  window_ = std::make_shared<sdl::Window>();
  renderer_ = std::make_shared<sdl::Renderer>(*window_);
}

App::~App() {
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}
} // namespace nge