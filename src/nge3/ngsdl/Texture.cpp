#include "Texture.h"
#include "Renderer.h"

#include "SDLException.h"

namespace nge::sdl {
Texture::Texture(Renderer &renderer, Uint32 format, int access, int w, int h)
    : texture_(nullptr, SDL_DestroyTexture) {
  texture_.reset(CreateTexture(renderer, format, access, w, h));
  // auto texture = SDL_CreateTexture(renderer, format, access, w, h);
  // if (texture == nullptr) {
  //   throw SDLException("Unable to create texture");
  // } else {
  //   texture_.reset(texture);
  // }
}

SDL_Texture *CreateTexture(Renderer &renderer, Uint32 format, int access, int w,
                           int h) {
  SDL_Texture *t =
      SDL_CreateTexture(renderer.renderer_.get(), format, access, w, h);
  if (t == nullptr) {
    throw SDLException("Texture couldn't be created");
  } else {
    return t;
  }
}
} // namespace nge::sdl