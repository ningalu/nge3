#ifndef NGSDL_RENDERERFLIP_H
#define NGSDL_RENDERERFLIP_H

#include <cstdint>

#include <SDL2/SDL.h>

namespace nge::sdl {
enum class RendererFlip : uint8_t {
  NONE = SDL_FLIP_NONE,
  HORIZONTAL = SDL_FLIP_HORIZONTAL,
  VERTICAL = SDL_FLIP_VERTICAL

};
RendererFlip operator|(RendererFlip lhs, RendererFlip rhs);
} // namespace nge::sdl

#endif