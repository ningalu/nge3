#ifndef NGSDL_RECT_H
#define NGSDL_RECT_H

#include <cstdint>

#include "SDL2/SDL.h"

#include "misc/Rectangle.hpp"

namespace nge::sdl {
class Rect : public ngl::Rectangle<int32_t> {
  [[nodiscard]] SDL_Rect &bitcast();
};
} // namespace nge::sdl

#endif