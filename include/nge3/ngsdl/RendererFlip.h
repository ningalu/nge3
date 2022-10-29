#ifndef NGE3_NGSDL_RENDERERFLIP_H
#define NGE3_NGSDL_RENDERERFLIP_H

#pragma warning(push, 0)
#include "SDL2/SDL.h"
#pragma warning(pop)

namespace nge::sdl {
enum class RendererFlip {
  NONE = SDL_FLIP_NONE,
  HORIZONTAL = SDL_FLIP_HORIZONTAL,
  VERTICAL = SDL_FLIP_VERTICAL

};
RendererFlip operator|(const RendererFlip &lhs, const RendererFlip &rhs);
} // namespace nge::sdl

#endif