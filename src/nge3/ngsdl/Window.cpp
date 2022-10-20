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

Window::Window(std::string title, int x, int y, int w, int h, WindowFlag flags)
    : window_(nullptr, SDL_DestroyWindow) {
  // temporary pending a Display object

  SDL_Window *window =
      SDL_CreateWindow(title.c_str(), x, y, w, h, static_cast<int>(flags));
  if (window == nullptr) {
    throw SDLException("Window couldn't be created");
  } else {
    window_.reset(window);
  }
}

std::tuple<int, int> Window::GetMaxSize() const {
  int w, h;
  SDL_GetWindowMaximumSize(window_.get(), &w, &h);
  return {w, h};
}
void Window::SetMaxSize(int w, int h) {
  SDL_SetWindowMaximumSize(window_.get(), w, h);
}

void Window::SetPosition(Point point) {
  SDL_SetWindowPosition(window_.get(), point.GetX(), point.GetY());
}

Point Window::GetPosition() const {
  int x, y;
  SDL_GetWindowPosition(window_.get(), &x, &y);
  return {x, y};
}
std::tuple<int, int> Window::GetSize() const {
  int w, h;
  SDL_GetWindowSize(window_.get(), &w, &h);
  return {w, h};
}
void Window::SetSize(int w, int h) { SDL_SetWindowSize(window_.get(), w, h); }

std::string_view Window::GetTitle() const {
  return SDL_GetWindowTitle(window_.get());
}

void Window::SetTitle(const std::string &title) {
  SDL_SetWindowTitle(window_.get(), title.c_str());
}

} // namespace nge::sdl