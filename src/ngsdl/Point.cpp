#include "ngsdl/Point.h"

#include <cstdint>

namespace nge::sdl {
Point::Point() { point_ = {0, 0}; }
Point::Point(int x, int y) { point_ = {x, y}; }
int32_t Point::GetX() const { return point_.x; }
int32_t Point::GetY() const { return point_.y; }
void Point::SetX(int x) { point_.x = x; }
void Point::SetY(int y) { point_.y = y; }

Point Point::operator+(const Point &rhs) {
  return {point_.x + rhs.GetX(), point_.y + rhs.GetY()};
}
Point &Point::operator+=(const Point &rhs) {
  point_.x += rhs.GetX();
  point_.y += rhs.GetY();
  return *this;
}
Point Point::operator-(const Point &rhs) {
  return {point_.x - rhs.GetX(), point_.y - rhs.GetY()};
}
Point &Point::operator-=(const Point &rhs) {
  point_.x -= rhs.GetX();
  point_.y -= rhs.GetY();
  return *this;
}
Point Point::operator*(const Point &rhs) {
  return {point_.x * rhs.GetX(), point_.y * rhs.GetY()};
}
Point &Point::operator*=(const Point &rhs) {
  point_.x *= rhs.GetX();
  point_.y *= rhs.GetY();
  return *this;
}
Point Point::operator/(const Point &rhs) {
  return {point_.x / rhs.GetX(), point_.y / rhs.GetY()};
}
Point &Point::operator/=(const Point &rhs) {
  point_.x /= rhs.GetX();
  point_.y /= rhs.GetY();
  return *this;
}

bool operator==(const Point &lhs, const Point &rhs) {
  return (lhs.GetX() == rhs.GetX()) && (lhs.GetY() == lhs.GetY());
}
bool operator==(Point &lhs, Point &rhs) {
  return (lhs.GetX() == rhs.GetX()) && (lhs.GetY() == lhs.GetY());
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
  os << "x: " << point.GetX() << " y: " << point.GetY();
  return os;
}
} // namespace nge::sdl