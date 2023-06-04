#ifndef NGSDL_POINT_H
#define NGSDL_POINT_H

#include <cstdint>
#include <ostream>

#include <SDL2/SDL.h>

#include "misc/Point.hpp"

namespace nge::sdl {
class Point : public ngl::Point<int32_t> {

public:
  using ngl::Point<int32_t>::Point;

  Point operator+(const Point &rhs);
  Point &operator+=(const Point &rhs);
  Point operator-(const Point &rhs);
  Point &operator-=(const Point &rhs);
  Point operator*(const Point &rhs);
  Point &operator*=(const Point &rhs);
  Point operator/(const Point &rhs);
  Point &operator/=(const Point &rhs);
};

// finnicky about const
bool operator==(const Point &lhs, const Point &rhs);
bool operator==(Point &lhs, Point &rhs);
std::ostream &operator<<(std::ostream &os, const Point &point);

} // namespace nge::sdl

#endif