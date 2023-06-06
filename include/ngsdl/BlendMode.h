#ifndef NGSDL_BLENDMODEFLAGS_H
#define NGSDL_BLENDMODEFLAGS_H

#include <cstdint>
#include <ostream>

#include <SDL2/SDL.h>

namespace nge::sdl {
enum class BlendMode : uint8_t {
  NONE = SDL_BLENDMODE_NONE,
  BLEND = SDL_BLENDMODE_BLEND,
  ADD = SDL_BLENDMODE_ADD,
  MOD = SDL_BLENDMODE_MOD
};
std::ostream &operator<<(std::ostream &os, BlendMode blend);
} // namespace nge::sdl

#endif