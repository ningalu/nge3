#ifndef NGSDL_COLOR_H
#define NGSDL_COLOR_H

#include <cstdint>
#include <tuple>

#include <SDL2/SDL.h>

namespace nge::sdl {
struct Color {

  Color();
  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
  [[nodiscard]] std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> GetColors(
  ) const noexcept;

  uint8_t r, g, b, a;
};
using Colour = Color;
} // namespace nge::sdl

#endif