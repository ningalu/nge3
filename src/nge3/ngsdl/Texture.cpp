#include "Texture.h"

#include "Renderer.h"
#include "SDLException.h"
#include "TextureLoader.h"

namespace nge::sdl {
Texture::Texture(const Renderer &renderer, Uint32 format, int access, int w,
                 int h)
    : texture_(nullptr, SDL_DestroyTexture) {
  texture_.reset(TextureLoader::CreateTexture(renderer, format, access, w, h));
}

Texture::Texture(const Renderer &renderer, std::string filename)
    : texture_(nullptr, SDL_DestroyTexture) {
  texture_.reset(TextureLoader::LoadTexture(renderer, filename));
}
} // namespace nge::sdl