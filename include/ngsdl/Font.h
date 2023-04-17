#ifndef NGE3_NGSDL_FONT_H
#define NGE3_NGSDL_FONT_H

#include <iostream>
#include <memory>
#include <string>

#include <SDL2/SDL_ttf.h>

#include "Color.h"
#include "Texture.h"

namespace nge::sdl {
class Renderer;
class Font {
  friend class Texture;

public:
  // Font() = delete;
  // Font(const Font &) = delete;
  // Font &operator=(const Font &) = delete;
  Font(const std::string &filename, int point_size);

  // TTF_RenderText_Blended
  // TTF_RenderText_Blended_Wrapped
  Texture CreateBlendedTexture(
    const Renderer &renderer,
    const std::string &text,
    Color color,
    std::optional<uint32_t> wrap_length = std::nullopt
  );

  // TTF_RenderText_LCD
  // TTF_RenderText_LCD_Wrapped

  // TTF_RenderText_Shaded
  // TTF_RenderText_Shaded_Wrapped
  Texture CreateShadedTexture(
    const Renderer &renderer,
    const std::string &text,
    Color foreground,
    Color background,
    std::optional<uint32_t> wrap_length = std::nullopt
  );

  // TTF_RenderText_Solid
  // TTF_RenderText_Solid_Wrapped
  Texture CreateSolidTexture(
    const Renderer &renderer,
    const std::string &text,
    Color color,
    std::optional<uint32_t> wrap_length = std::nullopt
  );

  // IMG_SetFontSize
  void SetFontSize(int point_size);

  // IMG_SizeText
  std::tuple<int, int> CalcTextSize(const std::string &text) const;

  ~Font();

protected:
  std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> font_;

  SDL_Texture *TextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surf);
};
} // namespace nge::sdl

#endif