#include "Window.h"

#include "SdlException.h"

namespace nge::sdl {
Window::Window() : window_(nullptr, SDL_DestroyWindow) {
  // temporary pending a Display object
  SDL_DisplayMode dm;
  if (SDL_GetDesktopDisplayMode(0, &dm) == 0) {
    throw SDLException("Desktop display mode couldn't be created");
  }

  SDL_Window *window = SDL_CreateWindow("NGSDL Window", 0, 0, dm.w, dm.h, 0);
  if (window == nullptr) {
    throw SDLException("Window couldn't be created");
  } else {
    window_.reset(window);
  }
}
} // namespace nge::sdl