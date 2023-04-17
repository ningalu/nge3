#ifndef NGSDL_RENDERERFLAGS_H
#define NGSDL_RENDERERFLAGS_H

#include <cstdint>

#include <SDL2/SDL.h>

namespace nge::sdl {
enum class RendererFlags : uint8_t {
  SOFTWARE = SDL_RENDERER_SOFTWARE,
  ACCELERATED = SDL_RENDERER_ACCELERATED,
  PRESENTVSYNC = SDL_RENDERER_PRESENTVSYNC,
  TARGETTEXTURE = SDL_RENDERER_TARGETTEXTURE,
};
RendererFlags operator|(RendererFlags lhs, RendererFlags rhs);

} // namespace nge::sdl

#endif