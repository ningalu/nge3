#ifndef NGE3_NGSDL_RECTANGLE_H
#define NGE3_NGSDL_RECTANGLE_H

#include <ostream>

#include "SDL2/SDL.h"

namespace nge::sdl {
class Rectangle {
public:
  Rectangle();
  Rectangle(int x, int y, int w, int h);

  int GetX() const;
  int GetY() const;
  int GetW() const;
  int GetH() const;
  void SetX(int x);
  void SetY(int y);
  void SetW(int w);
  void SetH(int h);

  bool Intersects(const Rectangle &r) const;

protected:
  SDL_Rect rect_;
};

using Rect = Rectangle;
std::ostream &operator<<(std::ostream &os, const Rectangle &rect);
} // namespace nge::sdl

#endif