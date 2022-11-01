#include "Rectangle.h"

#include "Point.h"

namespace nge::sdl {
Rectangle::Rectangle() { rect_ = {0, 0, 0, 0}; }
Rectangle::Rectangle(int x, int y, int w, int h) { rect_ = {x, y, w, h}; }
Rectangle::Rectangle(const Point &p, int w, int h) {
  rect_ = {p.GetX(), p.GetY(), w, h};
}
Rectangle::Rectangle(SDL_Rect r) { rect_ = r; }

Rectangle::Rectangle(int x, int y, std::tuple<int, int> size) {
  rect_ = {x, y, std::get<0>(size), std::get<1>(size)};
}

Rectangle::Rectangle(const Point &p, const std::tuple<int, int> &size) {
  rect_ = {p.GetX(), p.GetY(), std::get<0>(size), std::get<1>(size)};
}

bool Rectangle::Intersects(const Rectangle &r) const {
  return static_cast<bool>(SDL_HasIntersection(&rect_, &r.rect_));
}

std::optional<Rectangle> Rectangle::GetIntersection(const Rectangle &r) const {
  SDL_Rect out;
  return SDL_IntersectRect(&rect_, &r.rect_, &out) ?
           std::optional(Rectangle{out}) :
           std::nullopt;
}

int Rectangle::GetX() const { return rect_.x; }
int Rectangle::GetY() const { return rect_.y; }
Point Rectangle::GetPos() const { return {rect_.x, rect_.y}; }
void Rectangle::SetPos(const Point p) {
  rect_.x = p.GetX();
  rect_.y = p.GetY();
}
void Rectangle::MoveX(int dx) { rect_.x += dx; }
void Rectangle::MoveY(int dy) { rect_.y += dy; }

int Rectangle::GetW() const { return rect_.w; }

int Rectangle::GetH() const { return rect_.h; }

void Rectangle::SetX(int x) { rect_.x = x; }

void Rectangle::SetY(int y) { rect_.y = y; }

void Rectangle::SetW(int w) { rect_.w = w; }

void Rectangle::SetH(int h) { rect_.h = h; }

std::ostream &operator<<(std::ostream &os, const Rectangle &rect) {
  os << "x: " << rect.GetX() << " y: " << rect.GetY() << " w: " << rect.GetW()
     << " h: " << rect.GetH();
  return os;
}
} // namespace nge::sdl