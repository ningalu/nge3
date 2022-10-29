#ifndef NGE3_NGSDL_BLENDMODEFLAGS_H
#define NGE3_NGSDL_BLENDMODEFLAGS_H

#include <ostream>

#pragma warning(push, 0)
#include "SDL2/SDL.h"
#pragma warning(pop)

namespace nge::sdl {
enum class BlendMode {
  NONE = SDL_BLENDMODE_NONE,
  BLEND = SDL_BLENDMODE_BLEND,
  ADD = SDL_BLENDMODE_ADD,
  MOD = SDL_BLENDMODE_MOD
};
std::ostream &operator<<(std::ostream &os, const BlendMode blend);
} // namespace nge::sdl

#endif