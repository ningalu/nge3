#include "ngsdl/Rectangle.h"

#include <cstdint>

#include "ngsdl/Point.h"

namespace nge::sdl {
Rectangle::Rectangle() { rect_ = {0, 0, 0, 0}; }
Rectangle::Rectangle(int32_t x, int32_t y, int32_t w, int32_t h) {
  rect_ = {x, y, w, h};
}
Rectangle::Rectangle(const Point &p, int32_t w, int32_t h) {
  rect_ = {p.GetX(), p.GetY(), w, h};
}
Rectangle::Rectangle(SDL_Rect r) { rect_ = r; }

Rectangle::Rectangle(int32_t x, int32_t y, std::tuple<int32_t, int32_t> size) {
  rect_ = {x, y, std::get<0>(size), std::get<1>(size)};
}

Rectangle::Rectangle(const Point &p, const std::tuple<int32_t, int32_t> &size) {
  rect_ = {p.GetX(), p.GetY(), std::get<0>(size), std::get<1>(size)};
}

[[nodiscard]] bool Rectangle::Intersects(const Rectangle &r) const noexcept {
  return static_cast<bool>(SDL_HasIntersection(&rect_, &r.rect_));
}

[[nodiscard]] std::optional<Rectangle>
Rectangle::GetIntersection(const Rectangle &r) const noexcept {
  SDL_Rect out;
  return SDL_IntersectRect(&rect_, &r.rect_, &out) ?
           std::optional(Rectangle{out}) :
           std::nullopt;
}

[[nodiscard]] int32_t Rectangle::GetX() const noexcept { return rect_.x; }
[[nodiscard]] int32_t Rectangle::GetY() const noexcept { return rect_.y; }
[[nodiscard]] Point Rectangle::GetPos() const noexcept {
  return {rect_.x, rect_.y};
}
void Rectangle::SetPos(const Point p) noexcept {
  rect_.x = p.GetX();
  rect_.y = p.GetY();
}
void Rectangle::MoveX(int32_t dx) noexcept { rect_.x += dx; }
void Rectangle::MoveY(int32_t dy) noexcept { rect_.y += dy; }

[[nodiscard]] int32_t Rectangle::GetW() const noexcept { return rect_.w; }

[[nodiscard]] int32_t Rectangle::GetH() const noexcept { return rect_.h; }

void Rectangle::SetX(int32_t x) noexcept { rect_.x = x; }

void Rectangle::SetY(int32_t y) noexcept { rect_.y = y; }

void Rectangle::SetW(int32_t w) noexcept { rect_.w = w; }

void Rectangle::SetH(int32_t h) noexcept { rect_.h = h; }

std::ostream &operator<<(std::ostream &os, const Rectangle &rect) {
  os << "x: " << rect.GetX() << " y: " << rect.GetY() << " w: " << rect.GetW()
     << " h: " << rect.GetH();
  return os;
}
} // namespace nge::sdl