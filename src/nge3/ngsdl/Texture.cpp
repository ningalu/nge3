#include "Texture.h"

#include "Renderer.h"
#include "SDLException.h"
#include "TextureLoader.h"

namespace nge::sdl {
Texture::Texture(Renderer &renderer, Uint32 format, int access, int w, int h)
    : texture_(nullptr, SDL_DestroyTexture) {
  texture_.reset(TextureLoader::CreateTexture(renderer, format, access, w, h));
  // auto texture = SDL_CreateTexture(renderer, format, access, w, h);
  // if (texture == nullptr) {
  //   throw SDLException("Unable to create texture");
  // } else {
  //   texture_.reset(texture);
  // }
}

} // namespace nge::sdl