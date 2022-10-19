#include "Rectangle.h"

namespace nge::sdl {
Rectangle::Rectangle() { rect_ = {0, 0, 0, 0}; }
Rectangle::Rectangle(int x, int y, int w, int h) { rect_ = {x, y, w, h}; }

bool Rectangle::Intersects(const Rectangle &r) const {
  return SDL_HasIntersection(&rect_, &r.rect_);
}

int Rectangle::GetX() const { return rect_.x; }

int Rectangle::GetY() const { return rect_.y; }

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