#ifndef NGE3_NGSDL_WINDOW_H
#define NGE3_NGSDL_WINDOW_H

#include <memory>
#include <string>
#include <string_view>
#include <tuple>

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
  Window(std::string title, int x, int y, int w, int h, WindowFlag flags);

  Point GetPos() const;
  void SetPos(Point point);
  std::tuple<int, int> GetSize() const;
  void SetSize(int w, int h);
  std::string_view GetTitle() const;
  void SetTitle(const std::string &title);

protected:
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window_;

private:
};
} // namespace sdl
} // namespace nge

#endif