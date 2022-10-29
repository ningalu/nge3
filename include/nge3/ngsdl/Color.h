#ifndef NGE3_NGSDL_COLOR_H
#define NGE3_NGSDL_COLOR_H

#include <cstdint>
#include <tuple>

#pragma warning(push, 0)
#include "SDL2/SDL.h"
#pragma warning(pop)

namespace nge::sdl {
class Texture;
class Font;
class Color {
  friend class Texture;
  friend class Font;

public:
  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
  uint8_t GetR() const;
  uint8_t GetG() const;
  uint8_t GetB() const;
  uint8_t GetA() const;
  std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> GetColors() const;

protected:
  SDL_Color color_;
};
using Colour = Color;
} // namespace nge::sdl

#endif