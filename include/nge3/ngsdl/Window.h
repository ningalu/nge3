#ifndef NGE3_NGSDL_WINDOW_H
#define NGE3_NGSDL_WINDOW_H

#include <memory>

#include "SDL2/SDL.h"

namespace nge {
namespace sdl {
class Renderer;
class Window {
public:
  friend class Renderer;
  Window();

protected:
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_;

private:
};
} // namespace sdl
} // namespace nge

#endif