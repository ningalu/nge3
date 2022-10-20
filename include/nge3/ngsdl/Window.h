#ifndef NGE3_NGSDL_WINDOW_H
#define NGE3_NGSDL_WINDOW_H

#include <memory>
#include <string>

#include "SDL2/SDL.h"

#include "Point.h"
#include "WindowFlag.h"

namespace nge {
namespace sdl {
class Renderer;
class Window {
public:
  friend class Renderer;
  Window();
  Window(std::string name, int x, int y, int w, int h, WindowFlag flags);

  Window &SetPos(Point point);
  Point GetPos();

protected:
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_;

private:
};
} // namespace sdl
} // namespace nge

#endif