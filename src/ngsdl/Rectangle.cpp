#include "ngsdl/Rectangle.h"

#include <bit>
#include <cstdint>

#include "ngsdl/Point.h"

namespace nge::sdl {
Rectangle::Rectangle() : ngl::Rectangle<int32_t>(0, 0, 0, 0) {}
Rectangle::Rectangle(int32_t x, int32_t y, int32_t w, int32_t h)
    : ngl::Rectangle<int32_t>(x, y, w, h) {}
Rectangle::Rectangle(const Point &p, int32_t w, int32_t h)
    : ngl::Rectangle<int32_t>(p.GetX(), p.GetY(), w, h) {}
Rectangle::Rectangle(SDL_Rect r)
    : ngl::Rectangle<int32_t>(r.x, r.y, r.w, r.h) {}

Rectangle::Rectangle(int32_t x, int32_t y, std::tuple<int32_t, int32_t> size)
    : ngl::Rectangle<int32_t>(x, y, std::get<0>(size), std::get<1>(size)) {}

Rectangle::Rectangle(const Point &p, const std::tuple<int32_t, int32_t> &size)
    : ngl::Rectangle<int32_t>(
      p.GetX(), p.GetY(), std::get<0>(size), std::get<1>(size)
    ) {}

[[nodiscard]] SDL_Rect *Rectangle::bit_cast() {
  return std::bit_cast<SDL_Rect *>(this);
}

[[nodiscard]] SDL_Rect *Rectangle::bit_cast() const {
  return std::bit_cast<SDL_Rect *>(this);
}

[[nodiscard]] bool Rectangle::Encloses(const Point &p) const noexcept {
  return SDL_PointInRect(&(p.point_), bit_cast());
}

[[nodiscard]] std::optional<Rectangle> Rectangle::GetIntersection(
  const Rectangle &r
) const noexcept {
  SDL_Rect out;
  return SDL_IntersectRect(bit_cast(), r.bit_cast(), &out) ?
           std::optional(Rectangle{out}) :
           std::nullopt;
}
[[nodiscard]] Point Rectangle::GetPos() const noexcept { return Point{x_, y_}; }
void Rectangle::SetPos(const Point p) noexcept {
  x_ = p.GetX();
  y_ = p.GetY();
}

std::ostream &operator<<(std::ostream &os, const Rectangle &rect) {
  os << "x: " << rect.X() << " y: " << rect.Y() << " w: " << rect.W()
     << " h: " << rect.H();
  return os;
}
} // namespace nge::sdl