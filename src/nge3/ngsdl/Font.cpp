#include "Font.h"

#include "SDL2/SDL_ttf.h"

#include "SDLException.h"
#include "TTFException.h"

#include "Renderer.h"

namespace nge::sdl {
Font::Font(const std::string &filename, int point_size)
    : font_(nullptr, TTF_CloseFont) {
  auto f = TTF_OpenFont(filename.c_str(), point_size);
  if (f == nullptr) {
    throw TTFException("Font couldn't be opened");
  }
  font_.reset(f);
}

Texture Font::CreateBlendedTexture(
  const Renderer &renderer,
  const std::string &text,
  Color color,
  std::optional<uint32_t> wrap_length
) {
  SDL_Surface *temp_surf;
  if (wrap_length == std::nullopt) {
    temp_surf = TTF_RenderText_Blended(font_.get(), text.c_str(), color.color_);
  } else {
    temp_surf = TTF_RenderText_Blended_Wrapped(
      font_.get(), text.c_str(), color.color_, *wrap_length
    );
  }
  SDL_Texture *temp_tex
    = TextureFromSurface(renderer.renderer_.get(), temp_surf);
  SDL_FreeSurface(temp_surf);
  return Texture{temp_tex};
}

Texture Font::CreateShadedTexture(
  const Renderer &renderer,
  const std::string &text,
  Color foreground,
  Color background,
  std::optional<uint32_t> wrap_length
) {
  SDL_Surface *temp_surf;
  if (wrap_length == std::nullopt) {
    temp_surf = TTF_RenderText_Shaded(
      font_.get(), text.c_str(), foreground.color_, background.color_
    );
  } else {
    temp_surf = TTF_RenderText_Shaded_Wrapped(
      font_.get(),
      text.c_str(),
      foreground.color_,
      background.color_,
      *wrap_length
    );
  }
  SDL_Texture *temp_tex
    = TextureFromSurface(renderer.renderer_.get(), temp_surf);
  SDL_FreeSurface(temp_surf);
  return Texture{temp_tex};
}

Texture Font::CreateSolidTexture(
  const Renderer &renderer,
  const std::string &text,
  Color color,
  std::optional<uint32_t> wrap_length
) {
  SDL_Surface *temp_surf;
  if (wrap_length == std::nullopt) {
    temp_surf = TTF_RenderText_Solid(font_.get(), text.c_str(), color.color_);
  } else {
    temp_surf = TTF_RenderText_Solid_Wrapped(
      font_.get(), text.c_str(), color.color_, *wrap_length
    );
  }
  SDL_Texture *temp_tex
    = TextureFromSurface(renderer.renderer_.get(), temp_surf);
  SDL_FreeSurface(temp_surf);
  return Texture{temp_tex};
}

SDL_Texture *
Font::TextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surf) {
  if (surf == nullptr) {
    throw TTFException("Surface couldn't be created from Font");
  }
  SDL_Texture *temp_tex = SDL_CreateTextureFromSurface(renderer, surf);
  if (temp_tex == nullptr) {
    throw SDLException("Texture couldn't be created from Surface");
  }
  return temp_tex;
}
} // namespace nge::sdl