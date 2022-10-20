#include "Texture.h"

#include "SDLException.h"

namespace nge::sdl {
Texture::Texture(std::shared_ptr<Renderer> renderer, Uint32 format, int access,
                 int w, int h)
    : texture_(nullptr, SDL_DestroyTexture), renderer_(renderer) {
  auto texture =
      SDL_CreateTexture(renderer->renderer_.get(), format, access, w, h);
  if (texture == nullptr) {
    throw SDLException("Unable to create texture");
  } else {
    texture_.reset(texture);
  }
}
void Texture::Draw(const Rectangle &src, const Rectangle &dst) {
  SDL_RenderCopy(renderer_->renderer_.get(), texture_.get(), &src.rect_,
                 &dst.rect_);
}
} // namespace nge::sdl