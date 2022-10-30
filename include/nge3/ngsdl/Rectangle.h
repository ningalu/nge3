#ifndef NGE3_NGSDL_RECTANGLE_H
#define NGE3_NGSDL_RECTANGLE_H

#include <optional>
#include <ostream>
#include <tuple>

#include <SDL2/SDL.h>

namespace nge::sdl {
class Texture;
class Renderer;
class Point;
class Rectangle {
  friend class Texture;
  friend class Renderer;

public:
  Rectangle();
  Rectangle(int x, int y, int w, int h);
  Rectangle(const Point &p, int w, int h);
  Rectangle(int x, int y, std::tuple<int, int> size);
  Rectangle(const Point &p, const std::tuple<int, int> &size);

  int GetX() const;
  int GetY() const;
  int GetW() const;
  int GetH() const;
  void SetX(int x);
  void SetY(int y);
  void SetW(int w);
  void SetH(int h);

  bool Intersects(const Rectangle &r) const;
  std::optional<Rectangle> GetIntersection(const Rectangle &r) const;

protected:
  Rectangle(SDL_Rect r);
  SDL_Rect rect_;
};

using Rect = Rectangle;
std::ostream &operator<<(std::ostream &os, const Rectangle &rect);
} // namespace nge::sdl

#endif