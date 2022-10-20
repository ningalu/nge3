#include "Point.h"

namespace nge::sdl {
Point::Point(int x, int y) { point_ = {x, y}; }
int Point::GetX() const { return point_.x; }
int Point::GetY() const { return point_.y; }
void Point::SetX(int x) { point_.x = x; }
void Point::SetY(int y) { point_.y = y; }

std::ostream &operator<<(std::ostream &os, const Point &point) {
  os << "x: " << point.GetX() << " y: " << point.GetY();
  return os;
}
} // namespace nge::sdl