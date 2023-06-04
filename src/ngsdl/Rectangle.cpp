#include "ngsdl/Rectangle.h"

#include <bit>
#include <cstdint>

#include "ngsdl/Point.h"

namespace nge::sdl {
// Rectangle::Rectangle() : ngl::Rectangle<int32_t>(0, 0, 0, 0) {}
// Rectangle::Rectangle(ngl::Rectangle<int32_t> r) : ngl::Rectangle<int32_t>(r)
// {}

// Rectangle::Rectangle(int32_t x, int32_t y, int32_t w, int32_t h)
//     : ngl::Rectangle<int32_t>(x, y, w, h) {}
// Rectangle::Rectangle(const Point &p, int32_t w, int32_t h)
//     : ngl::Rectangle<int32_t>(p.X(), p.Y(), w, h) {}
// Rectangle::Rectangle(SDL_Rect r)
//     : ngl::Rectangle<int32_t>(r.x, r.y, r.w, r.h) {}

// Rectangle::Rectangle(int32_t x, int32_t y, std::tuple<int32_t, int32_t> size)
//     : ngl::Rectangle<int32_t>(x, y, std::get<0>(size), std::get<1>(size)) {}

// Rectangle::Rectangle(const Point &p, const std::tuple<int32_t, int32_t>
// &size)
//     : ngl::Rectangle<int32_t>(
//       p.X(), p.Y(), std::get<0>(size), std::get<1>(size)
//     ) {}

[[nodiscard]] SDL_Rect *Rectangle::bit_cast() {
  return std::bit_cast<SDL_Rect *>(this);
}

[[nodiscard]] SDL_Rect *Rectangle::bit_cast() const {
  return std::bit_cast<SDL_Rect *>(this);
}

[[nodiscard]] std::optional<Rectangle> Rectangle::GetIntersection(
  const Rectangle &r
) const noexcept {
  Rectangle out;
  return SDL_IntersectRect(
           std::bit_cast<SDL_Rect *>(this),
           std::bit_cast<SDL_Rect *>(&r),
           std::bit_cast<SDL_Rect *>(&out)
         ) ?
           std::optional(out) :
           std::nullopt;
}
[[nodiscard]] Point Rectangle::GetPos() const noexcept { return Point{x_, y_}; }
void Rectangle::SetPos(const Point p) noexcept {
  x_ = p.X();
  y_ = p.Y();
}

} // namespace nge::sdl