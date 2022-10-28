#include "Window.h"

#include "SDLException.h"
#include "WindowFlags.h"

namespace nge::sdl {
Window::Window() : window_(nullptr, SDL_DestroyWindow) {
  SDL_DisplayMode dm;
  if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
    throw SDLException("Desktop display mode couldn't be created");
  }
  SDL_Window *window = SDL_CreateWindow(
    "NGSDL Window",
    static_cast<int>(WindowFlags::POS_CENTERED),
    static_cast<int>(WindowFlags::POS_CENTERED),
    dm.w,
    dm.h,
    static_cast<Uint32>(
      WindowFlags::OPENGL | WindowFlags::RESIZABLE | WindowFlags::MAXIMIZED
    )
  );
  if (window == nullptr) {
    throw SDLException("Window couldn't be created");
  } else {
    window_.reset(window);
  }
}

Window::Window(std::string title, int x, int y, int w, int h, WindowFlags flags)
    : window_(nullptr, SDL_DestroyWindow) {
  // temporary pending a Display object

  SDL_Window *window
    = SDL_CreateWindow(title.c_str(), x, y, w, h, static_cast<int>(flags));
  if (window == nullptr) {
    throw SDLException("Window couldn't be created");
  } else {
    window_.reset(window);
  }
}

const Uint32 Window::GetID() const { return SDL_GetWindowID(window_.get()); }

std::tuple<int, int> Window::GetMaxSize() const {
  int w, h;
  SDL_GetWindowMaximumSize(window_.get(), &w, &h);
  return {w, h};
}

void Window::SetMaxSize(int w, int h) {
  SDL_SetWindowMaximumSize(window_.get(), w, h);
}

int Window::GetMaxW() const {
  int w;
  SDL_GetWindowMaximumSize(window_.get(), &w, nullptr);
  return w;
}

int Window::GetMaxH() const {
  int h;
  SDL_GetWindowMaximumSize(window_.get(), nullptr, &h);
  return h;
}

std::tuple<int, int> Window::GetMinSize() const {
  int w, h;
  SDL_GetWindowMinimumSize(window_.get(), &w, &h);
  return {w, h};
}

void Window::SetMinSize(int w, int h) {
  SDL_SetWindowMinimumSize(window_.get(), w, h);
}

int Window::GetMinW() const {
  int w;
  SDL_GetWindowMinimumSize(window_.get(), &w, nullptr);
  return w;
}

int Window::GetMinH() const {
  int h;
  SDL_GetWindowMinimumSize(window_.get(), nullptr, &h);
  return h;
}

float Window::GetOpacity() const {
  float o;
  SDL_GetWindowOpacity(window_.get(), &o);
  return o;
}

void Window::SetOpacity(float opacity) {
  SDL_SetWindowOpacity(window_.get(), opacity);
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
int Window::GetW() const { return std::get<0>(GetSize()); }
int Window::GetH() const { return std::get<1>(GetSize()); }

void Window::SetSize(int w, int h) { SDL_SetWindowSize(window_.get(), w, h); }

std::string_view Window::GetTitle() const {
  return SDL_GetWindowTitle(window_.get());
}

void Window::SetTitle(const std::string &title) {
  SDL_SetWindowTitle(window_.get(), title.c_str());
}

std::tuple<MouseButton, Point> Window::GetMouseState() const {
  int x, y;
  auto button_flags = SDL_GetMouseState(&x, &y);
  MouseButton b = static_cast<MouseButton>(button_flags);
  return {b, {x, y}};
}

MouseButton Window::GetMouseButtons() const {
  return std::get<0>(GetMouseState());
}

Point Window::GetMousePos() const { return std::get<1>(GetMouseState()); }
int Window::GetMouseX() const { return GetMousePos().GetX(); }
int Window::GetMouseY() const { return GetMousePos().GetY(); }

const std::span<const Uint8> Window::GetKeyboardState() const {
  SDL_PumpEvents();
  int l;
  const Uint8 *kb = SDL_GetKeyboardState(&l);
  std::span s{kb, static_cast<size_t>(l)};
  return s;
}

} // namespace nge::sdl