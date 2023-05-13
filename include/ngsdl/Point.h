#ifndef NGSDL_POINT_H
#define NGSDL_POINT_H

#include <ostream>

#include <SDL2/SDL.h>

namespace nge::sdl {
class Renderer;
class Rectangle;
class Point {
  friend class Renderer;
  friend class Rectangle;

public:
  Point();
  Point(int32_t x, int32_t y);

  [[nodiscard]] int32_t GetX() const;
  [[nodiscard]] int32_t GetY() const;
  void SetX(int32_t x);
  void SetY(int32_t y);

  [[nodiscard]] bool Within(const Rectangle &r) const;

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