#include "Renderer.h"

#include "RendererFlags.h"
#include "SDLException.h"

namespace nge::sdl {
Renderer::Renderer(const Window &window)
    : renderer_(nullptr, SDL_DestroyRenderer) {
  SDL_Renderer *renderer = SDL_CreateRenderer(
    window.window_.get(),
    -1,
    static_cast<int>(RendererFlags::ACCELERATED)
      | static_cast<int>(RendererFlags::TARGETTEXTURE)
  );

  if (renderer == nullptr) {
    throw SDLException("Renderer couldn't be constructed");
  } else {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    renderer_.reset(renderer);
  }
}

Renderer::Renderer(const Window &window, int index, RendererFlags flags)
    : renderer_(nullptr, SDL_DestroyRenderer) {
  SDL_Renderer *renderer
    = SDL_CreateRenderer(window.window_.get(), index, static_cast<int>(flags));

  if (renderer == nullptr) {
    throw SDLException("Renderer couldn't be constructed");
  } else {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    renderer_.reset(renderer);
  }
}

void Renderer::Clear() { SDL_RenderClear(renderer_.get()); }

void Renderer::Present() { SDL_RenderPresent(renderer_.get()); }

void Renderer::Copy(
  const Texture &texture,
  const std::optional<Rectangle> &src,
  const Rectangle &dst
) {
  src.has_value() ?
    SDL_RenderCopy(
      renderer_.get(), texture.texture_.get(), &src->rect_, &dst.rect_
    ) :
    SDL_RenderCopy(
      renderer_.get(), texture.texture_.get(), nullptr, &dst.rect_
    );
}
void Renderer::CopyEx(
  const Texture &texture,
  const std::optional<Rectangle> &src,
  const Rectangle &dst,
  const double angle,
  const std::optional<Point> &center,
  const RendererFlip flip
) {
  SDL_RenderCopyEx(
    renderer_.get(),
    texture.texture_.get(),
    src == std::nullopt ? nullptr : &src->rect_,
    &dst.rect_,
    angle,
    center == std::nullopt ? nullptr : &center->point_,
    static_cast<SDL_RendererFlip>(flip)
  );
}
} // namespace nge::sdl