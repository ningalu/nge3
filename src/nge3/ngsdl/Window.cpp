#include "Window.h"

#include "SdlException.h"
#include "WindowFlag.h"

namespace nge::sdl {
Window::Window() : window_(nullptr, SDL_DestroyWindow) {
  SDL_DisplayMode dm;
  if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
    throw SDLException("Desktop display mode couldn't be created");
  }
  SDL_Window *window = SDL_CreateWindow(
      "NGSDL Window", static_cast<int>(WindowFlag::POS_CENTERED),
      static_cast<int>(WindowFlag::POS_CENTERED), dm.w, dm.h,
      static_cast<Uint32>(WindowFlag::OPENGL | WindowFlag::RESIZABLE |
                          WindowFlag::MAXIMIZED));
  if (window == nullptr) {
    throw SDLException("Window couldn't be created");
  } else {
    window_.reset(window);
  }
}

Window::Window(std::string name, int x, int y, int w, int h, WindowFlag flags)
    : window_(nullptr, SDL_DestroyWindow) {
  // temporary pending a Display object

  SDL_Window *window =
      SDL_CreateWindow(name.c_str(), x, y, w, h, static_cast<int>(flags));
  if (window == nullptr) {
    throw SDLException("Window couldn't be created");
  } else {
    window_.reset(window);
  }
}

Window &Window::SetPos(Point point) {
  SDL_SetWindowPosition(window_.get(), point.GetX(), point.GetY());
  return *this;
}
Point Window::GetPos() {
  int x, y;
  SDL_GetWindowPosition(window_.get(), &x, &y);
  return {x, y};
}
} // namespace nge::sdl