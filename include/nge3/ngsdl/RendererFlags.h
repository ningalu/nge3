#ifndef NGE3_NGSDL_RENDERERFLAGS_H
#define NGE3_NGSDL_RENDERERFLAGS_H

#include "SDL2/SDL.h"

namespace nge::sdl {
enum class RendererFlags {
  SOFTWARE = SDL_RENDERER_SOFTWARE,
  ACCELERATED = SDL_RENDERER_ACCELERATED,
  PRESENTVSYNC = SDL_RENDERER_PRESENTVSYNC,
  TARGETTEXTURE = SDL_RENDERER_TARGETTEXTURE,
};
RendererFlags operator|(const RendererFlags &lhs, const RendererFlags &rhs);

} // namespace nge::sdl

#endif