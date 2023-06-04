#include "ngsdl/Point.h"

#include <cstdint>

#include "ngsdl/Rectangle.h"

namespace nge::sdl {
// Point::Point() : ngl::Point<int32_t>(0, 0) {}
// Point::Point(int x, int y) : ngl::Point<int32_t>(x, y) {}

Point Point::operator+(const Point &rhs) {
  return Point{x_ + rhs.X(), y_ + rhs.Y()};
}
Point &Point::operator+=(const Point &rhs) {
  x_ += rhs.X();
  y_ += rhs.Y();
  return *this;
}
Point Point::operator-(const Point &rhs) {
  return {x_ - rhs.X(), y_ - rhs.Y()};
}
Point &Point::operator-=(const Point &rhs) {
  x_ -= rhs.X();
  y_ -= rhs.Y();
  return *this;
}
Point Point::operator*(const Point &rhs) {
  return {x_ * rhs.X(), y_ * rhs.Y()};
}
Point &Point::operator*=(const Point &rhs) {
  x_ *= rhs.X();
  y_ *= rhs.Y();
  return *this;
}
Point Point::operator/(const Point &rhs) {
  return {x_ / rhs.X(), y_ / rhs.Y()};
}
Point &Point::operator/=(const Point &rhs) {
  x_ /= rhs.X();
  y_ /= rhs.Y();
  return *this;
}

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