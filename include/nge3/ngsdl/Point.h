#ifndef NGE3_SDL_POINT_H
#define NGE3_SDL_POINT_H

#include <ostream>

#include "SDL2/SDL.h"

namespace nge::sdl {
class Point {
public:
  Point(int x, int y);

  int GetX() const;
  int GetY() const;
  void SetX(int x);
  void SetY(int y);

protected:
  SDL_Point point_;

private:
};

std::ostream &operator<<(std::ostream &os, const Point &point);

} // namespace nge::sdl

#endif