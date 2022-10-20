#include "Renderer.h"

#include "SDLException.h"

namespace nge::sdl {
Renderer::Renderer(const Window &window)
    : renderer_(nullptr, SDL_DestroyRenderer) {
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window.window_.get(), -1,
                         SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
  if (renderer == nullptr) {
    throw SDLException("Renderer couldn't be constructed");
  } else {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    renderer_.reset(renderer);
  }
}
void Renderer::Clear() { SDL_RenderClear(renderer_.get()); }
void Renderer::Present() { SDL_RenderPresent(renderer_.get()); }
} // namespace nge::sdl