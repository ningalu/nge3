#include "Window.h"

#include "SdlException.h"
#include "WindowFlags.h"

namespace nge::sdl {
Window::Window() : window_(nullptr, SDL_DestroyWindow) {
  // temporary pending a Display object
  SDL_DisplayMode dm;
  if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
    throw SDLException("Desktop display mode couldn't be created");
  }

  SDL_Window *window = SDL_CreateWindow(
      "NGSDL Window", WINDOWPOS_CENTERED, WINDOWPOS_CENTERED, dm.w, dm.h,
      WINDOW_OPENGL | WINDOW_RESIZABLE | WINDOW_MAXIMIZED);
  if (window == nullptr) {
    throw SDLException("Window couldn't be created");
  } else {
    window_.reset(window);
  }
}
} // namespace nge::sdl