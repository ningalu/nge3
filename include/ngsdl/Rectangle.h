#ifndef NGSDL_RECTANGLE_H
#define NGSDL_RECTANGLE_H

#include <cstdint>
#include <optional>
#include <ostream>
#include <tuple>

#include <SDL2/SDL.h>

#include "Point.h"

#include "misc/Rectangle.hpp"

namespace nge::sdl {
class Rectangle : public ngl::Rectangle<int32_t> {

public:
  Rectangle();
  Rectangle(int32_t x, int32_t y, int32_t w, int32_t h);
  Rectangle(const Point &p, int32_t w, int32_t h);
  Rectangle(int32_t x, int32_t y, std::tuple<int32_t, int32_t> size);
  Rectangle(const Point &p, const std::tuple<int32_t, int32_t> &size);

  [[nodiscard]] SDL_Rect *bit_cast();
  [[nodiscard]] SDL_Rect *bit_cast() const;

  [[nodiscard]] Point GetPos() const noexcept;
  void SetPos(const Point pos) noexcept;

  [[nodiscard]] bool Encloses(const Point &p) const noexcept;
  [[nodiscard]] std::optional<Rectangle> GetIntersection(const Rectangle &r
  ) const noexcept;

protected:
  Rectangle(SDL_Rect r);
};

std::ostream &operator<<(std::ostream &os, const Rectangle &rect);
} // namespace nge::sdl

#endif