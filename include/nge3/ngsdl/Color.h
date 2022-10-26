#ifndef NGE3_NGSDL_COLOR_H
#define NGE3_NGSDL_COLOR_H

#include <cstdint>
#include <tuple>

#include "SDL2/SDL.h"

namespace nge::sdl {
class Texture;
class Color {
  friend class Texture;

public:
  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

protected:
  SDL_Color color_;
};
using Colour = Color;
} // namespace nge::sdl

#endif