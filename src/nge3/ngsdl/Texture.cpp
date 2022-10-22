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

std::tuple<Uint32, int, int, int> Texture::Query() const {
  Uint32 format;
  int access, w, h;
  SDL_QueryTexture(texture_.get(), &format, &access, &w, &h);
  return {format, access, w, h};
}
Uint32 Texture::GetFormat() const {
  Uint32 format;
  SDL_QueryTexture(texture_.get(), &format, nullptr, nullptr, nullptr);
  return format;
}
int Texture::GetAccess() const {
  int access;
  SDL_QueryTexture(texture_.get(), nullptr, &access, nullptr, nullptr);
  return access;
}
int Texture::GetW() const {
  int w;
  SDL_QueryTexture(texture_.get(), nullptr, nullptr, &w, nullptr);
  return w;
}
int Texture::GetH() const {
  int h;
  SDL_QueryTexture(texture_.get(), nullptr, nullptr, nullptr, &h);
  return h;
}
std::tuple<int, int> Texture::GetSize() const {
  int w, h;
  SDL_QueryTexture(texture_.get(), nullptr, nullptr, &w, &h);
  return {w, h};
}
} // namespace nge::sdl