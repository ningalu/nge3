#include "ngsdl/Point.h"

#include <cstdint>

#include "ngsdl/Rectangle.h"

namespace nge::sdl {
Point::Point(const ngl::Point<int32_t> &p) : ngl::Point<int32_t>(p) {}
bool operator==(const Point &lhs, const Point &rhs) {
  return (lhs.X() == rhs.X()) && (lhs.Y() == lhs.Y());
}
bool operator==(Point &lhs, Point &rhs) {
  return (lhs.X() == rhs.X()) && (lhs.Y() == lhs.Y());
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
  os << "x: " << point.X() << " y: " << point.Y();
  return os;
}
} // namespace nge::sdl