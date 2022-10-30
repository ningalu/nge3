#ifndef NGE3_SDL_POINT_H
#define NGE3_SDL_POINT_H

#include <ostream>

#include <SDL2/SDL.h>

namespace nge::sdl {
class Renderer;
class Point {
  friend class Renderer;

public:
  Point();
  Point(int x, int y);

  int GetX() const;
  int GetY() const;
  void SetX(int x);
  void SetY(int y);

  Point operator+(const Point &rhs);
  Point &operator+=(const Point &rhs);
  Point operator-(const Point &rhs);
  Point &operator-=(const Point &rhs);
  Point operator*(const Point &rhs);
  Point &operator*=(const Point &rhs);
  Point operator/(const Point &rhs);
  Point &operator/=(const Point &rhs);

protected:
  SDL_Point point_;
};

// finnicky about const
bool operator==(const Point &lhs, const Point &rhs);
bool operator==(Point &lhs, Point &rhs);
std::ostream &operator<<(std::ostream &os, const Point &point);

} // namespace nge::sdl

#endif