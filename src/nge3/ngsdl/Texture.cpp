#include "Texture.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Font.h"
#include "Renderer.h"
#include "SDLException.h"
#include "TTFException.h"

namespace nge::sdl {
Texture::Texture(
  const Renderer &renderer, Uint32 format, int access, int w, int h
)
    : texture_(nullptr, SDL_DestroyTexture) {
  texture_.reset(
    SDL_CreateTexture(renderer.renderer_.get(), format, access, w, h)
  );
}

Texture::Texture(const Renderer &renderer, std::string filename)
    : texture_(nullptr, SDL_DestroyTexture) {
  texture_.reset(IMG_LoadTexture(renderer.renderer_.get(), filename.c_str()));
}

Texture::Texture(
  const Renderer &renderer,
  const Font &font,
  const std::string &text,
  FontRenderType type,
  Color color,
  Color bg
)
    : texture_(nullptr, SDL_DestroyTexture) {
  // no real reason to use library objects internally
  SDL_Surface *temp_surf = nullptr;
  switch (type) {
  case FontRenderType::SOLID:
    temp_surf
      = TTF_RenderText_Solid(font.font_.get(), text.c_str(), color.color_);
    break;
  case FontRenderType::BLENDED:
    temp_surf
      = TTF_RenderText_Blended(font.font_.get(), text.c_str(), color.color_);
    break;
  case FontRenderType::SHADED:
    temp_surf = TTF_RenderText_Shaded(
      font.font_.get(), text.c_str(), color.color_, bg.color_
    );
    break;
  }
  if (temp_surf == nullptr) {
    throw TTFException("Surface couldn't be created from Font");
  }
  SDL_Texture *temp_tex
    = SDL_CreateTextureFromSurface(renderer.renderer_.get(), temp_surf);
  if (temp_tex == nullptr) {
    throw SDLException("Texture couldn't be created from Surface");
  }
  SDL_FreeSurface(temp_surf);
  texture_.reset(temp_tex);
}

Texture::Texture(
  const Renderer &renderer,
  const Font &font,
  const std::string &text,
  FontRenderType type,
  Color color,
  uint32_t wrap_length,
  Color bg
)
    : texture_(nullptr, SDL_DestroyTexture) {
  SDL_Surface *temp_surf = nullptr;
  switch (type) {
  case FontRenderType::SOLID:
    temp_surf = TTF_RenderText_Solid_Wrapped(
      font.font_.get(), text.c_str(), color.color_, wrap_length
    );
    break;
  case FontRenderType::BLENDED:
    temp_surf = TTF_RenderText_Blended_Wrapped(
      font.font_.get(), text.c_str(), color.color_, wrap_length
    );
    break;
  case FontRenderType::SHADED:
    temp_surf = TTF_RenderText_Shaded_Wrapped(
      font.font_.get(), text.c_str(), color.color_, bg.color_, wrap_length
    );
    break;
  }
  if (temp_surf == nullptr) {
    throw TTFException("Surface couldn't be created from Font");
  }
  SDL_Texture *temp_tex
    = SDL_CreateTextureFromSurface(renderer.renderer_.get(), temp_surf);
  if (temp_tex == nullptr) {
    throw SDLException("Texture couldn't be created from Surface");
  }
  SDL_FreeSurface(temp_surf);
  texture_.reset(temp_tex);
}

Texture::Texture(SDL_Texture *texture)
    : texture_(texture, SDL_DestroyTexture) {}

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
  if (SDL_SetTextureBlendMode(texture_.get(), static_cast<SDL_BlendMode>(mode)) != 0) {
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