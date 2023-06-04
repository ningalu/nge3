#include "ngsdl/Rectangle.h"

#include <cstdint>

#include "ngsdl/Point.h"

namespace nge::sdl {

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