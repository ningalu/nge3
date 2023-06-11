#ifndef NGSDL_COLOR_H
#define NGSDL_COLOR_H

#include <cstdint>
#include <ostream>
#include <tuple>

#include <SDL2/SDL.h>

namespace nge::sdl {
struct Color {

  Color();
  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
  inline constexpr Color(uint32_t hex) {
    r = static_cast<uint8_t>((hex & 0xFF000000) >> 24);
    g = static_cast<uint8_t>((hex & 0x00FF0000) >> 16);
    b = static_cast<uint8_t>((hex & 0x0000FF00) >> 8);
    a = static_cast<uint8_t>((hex & 0x000000FF) >> 0);
  }
  [[nodiscard]] std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> GetColors(
  ) const noexcept;

  uint8_t r, g, b, a;
};
using Colour = Color;
} // namespace nge::sdl

std::ostream &operator<<(std::ostream &os, const nge::sdl::Color c);

#endif