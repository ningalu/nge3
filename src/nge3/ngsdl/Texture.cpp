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

Uint8 Texture::GetAlphaMod() const {
  Uint8 mod;
  if (SDL_GetTextureAlphaMod(texture_.get(), &mod) != 0) {
    throw SDLException("Alpha Modulation couldn't be retrieved");
  }
  return mod;
}

void Texture::SetAlphaMod(Uint8 mod) {
  if (SDL_SetTextureAlphaMod(texture_.get(), mod) != 0) {
    throw SDLException("Alpha Modulation couldn't be set");
  }
}

BlendMode Texture::GetBlendMode() const {
  SDL_BlendMode b;
  if (SDL_GetTextureBlendMode(texture_.get(), &b) != 0) {
    throw SDLException("Blend Mode couldn't be retrieved");
  }
  return BlendMode{b};
}

void Texture::SetBlendMode(BlendMode mode) {
  if (SDL_SetTextureBlendMode(texture_.get(),
                              static_cast<SDL_BlendMode>(mode)) != 0) {
    throw SDLException("Blend Mode couldn't be set");
  }
}

std::tuple<Uint8, Uint8, Uint8> Texture::GetColorMod() const {
  Uint8 r, g, b;
  if (SDL_GetTextureColorMod(texture_.get(), &r, &g, &b) != 0) {
    throw SDLException("Colour Modulation couldn't be retrieved");
  }
  return {r, g, b};
}
void Texture::SetColorMod(Uint8 r, Uint8 g, Uint8 b) {
  if (SDL_SetTextureColorMod(texture_.get(), r, g, b) != 0) {
    throw SDLException("Colour Modulation couldn't be set");
  }
}
std::tuple<Uint8, Uint8, Uint8> Texture::GetColourMod() const {
  Uint8 r, g, b;
  if (SDL_GetTextureColorMod(texture_.get(), &r, &g, &b) != 0) {
    throw SDLException("Colour Modulation couldn't be retrieved");
  }
  return {r, g, b};
}
void Texture::SetColourMod(Uint8 r, Uint8 g, Uint8 b) {
  if (SDL_SetTextureColorMod(texture_.get(), r, g, b) != 0) {
    throw SDLException("Colour Modulation couldn't be set");
  }
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