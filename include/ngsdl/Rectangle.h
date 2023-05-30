#ifndef NGSDL_RECTANGLE_H
#define NGSDL_RECTANGLE_H

#include <cstdint>
#include <optional>
#include <ostream>
#include <tuple>

#include <SDL2/SDL.h>

#include "Point.h"

namespace nge::sdl {
class Texture;
class Renderer;
class Point;
class Rectangle {
  friend class Texture;
  friend class Renderer;
  friend class Point;

public:
  Rectangle();
  Rectangle(int32_t x, int32_t y, int32_t w, int32_t h);
  Rectangle(const Point &p, int32_t w, int32_t h);
  Rectangle(int32_t x, int32_t y, std::tuple<int32_t, int32_t> size);
  Rectangle(const Point &p, const std::tuple<int32_t, int32_t> &size);

  [[nodiscard]] int32_t GetX() const noexcept;
  [[nodiscard]] int32_t GetY() const noexcept;
  [[nodiscard]] Point GetPos() const noexcept;
  void SetPos(const Point pos) noexcept;
  void MoveX(int32_t dx) noexcept;
  void MoveY(int32_t dy) noexcept;

  [[nodiscard]] int32_t GetW() const noexcept;
  [[nodiscard]] int32_t GetH() const noexcept;
  void SetX(int32_t x) noexcept;
  void SetY(int32_t y) noexcept;
  void SetW(int32_t w) noexcept;
  void SetH(int32_t h) noexcept;

  [[nodiscard]] bool Intersects(const Rectangle &r) const noexcept;
  [[nodiscard]] bool Encloses(const Point &p) const noexcept;
  [[nodiscard]] std::optional<Rectangle> GetIntersection(const Rectangle &r
  ) const noexcept;

protected:
  Rectangle(SDL_Rect r);
  SDL_Rect rect_;
};

std::ostream &operator<<(std::ostream &os, const Rectangle &rect);
} // namespace nge::sdl

#endif