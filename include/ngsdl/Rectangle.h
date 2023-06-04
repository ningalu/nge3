#ifndef NGSDL_RECTANGLE_H
#define NGSDL_RECTANGLE_H

#include <cstdint>
#include <optional>
#include <ostream>
#include <tuple>

#include "Point.h"

#include "misc/Rectangle.hpp"

namespace nge::sdl {
class Rectangle : public ngl::Rectangle<int32_t> {

public:
  using ngl::Rectangle<int32_t>::Rectangle;

  [[nodiscard]] Point GetPos() const noexcept;
  void SetPos(const Point pos) noexcept;

  [[nodiscard]] std::optional<Rectangle> GetIntersection(const Rectangle &r
  ) const noexcept;

protected:
  Rectangle(SDL_Rect r);
};

} // namespace nge::sdl

#endif