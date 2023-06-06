#ifndef NGSDL_FONT_H
#define NGSDL_FONT_H

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
  Font() = delete;
  Font(const Font &) = default;
  // Font &operator=(const Font &) = delete;
  Font(const std::string &filename, int point_size);

  // TTF_RenderText_Blended
  [[nodiscard]] Texture CreateBlendedTexture(
    const Renderer &renderer, const std::string &text, Colour colour
  );

  // TTF_RenderText_Blended_Wrapped
  [[nodiscard]] Texture CreateBlendedTexture(
    const Renderer &renderer,
    const std::string &text,
    Colour colour,
    uint32_t wrap_length
  );

  // TTF_RenderText_LCD
  // TTF_RenderText_LCD_Wrapped

  // TTF_RenderText_Shaded
  [[nodiscard]] Texture CreateShadedTexture(
    const Renderer &renderer,
    const std::string &text,
    Colour foreground,
    Colour background
  );
  // TTF_RenderText_Shaded_Wrapped
  [[nodiscard]] Texture CreateShadedTexture(
    const Renderer &renderer,
    const std::string &text,
    Colour foreground,
    Colour background,
    uint32_t wrap_length
  );

  // TTF_RenderText_Solid
  [[nodiscard]] Texture CreateSolidTexture(
    const Renderer &renderer, const std::string &text, Colour colour
  );
  // TTF_RenderText_Solid_Wrapped
  [[nodiscard]] Texture CreateSolidTexture(
    const Renderer &renderer,
    const std::string &text,
    Colour colour,
    uint32_t wrap_length
  );

  // IMG_SetFontSize
  void SetFontSize(int point_size);

  // IMG_SizeText
  std::tuple<int, int> CalcTextSize(const std::string &text) const;

  ~Font();

  std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> font_;

protected:
};
} // namespace nge::sdl

#endif