#ifndef NGSDL_COLOR_H
#define NGSDL_COLOR_H

#include <cstdint>
#include <tuple>

#include <SDL2/SDL.h>

namespace nge::sdl {
class Texture;
class Font;
class Color {
  friend class Texture;
  friend class Font;

public:
  Color();
  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
  [[nodiscard]] uint8_t GetR() const noexcept;
  [[nodiscard]] uint8_t GetG() const noexcept;
  [[nodiscard]] uint8_t GetB() const noexcept;
  [[nodiscard]] uint8_t GetA() const noexcept;
  [[nodiscard]] std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> GetColors(
  ) const noexcept;

protected:
  SDL_Color color_;
};
using Colour = Color;
} // namespace nge::sdl

#endif