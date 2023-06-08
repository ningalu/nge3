#ifndef NGSDL_SURFACE_H
#define NGSDL_SURFACE_H

#include <experimental/mdspan>
#include <memory>
#include <string>

#include "SDL2/SDL.h"

#include "ngsdl/Color.h"

namespace nge::sdl {
class Font;
class Surface : public SDL_Surface {
public:
  Surface() = delete;

  // SDL_CreateRGBSurface
  static [[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> RGB(
    uint32_t w, uint32_t h
  );

  // TTF_RenderText_Blended
  static [[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>
  TextBlended(Font &font, const std::string &text, Colour c);
  static [[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>
  TextBlended(Font *font, const std::string &text, Colour c);

  // TTF_RenderText_Blended_Wrapped
  static [[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>
  TextBlended(Font &font, const std::string &text, Colour c, uint32_t w);
  static [[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>
  TextBlended(Font *font, const std::string &text, Colour c, uint32_t w);

  // TTF_RenderText_Shaded
  static [[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>
  TextShaded(
    Font &font, const std::string &text, Colour text_colour, Colour background
  );
  static [[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>
  TextShaded(
    Font *font, const std::string &text, Colour text_colour, Colour background
  );

  // TTF_RenderText_Shaded_Wrapped
  static [[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>
  TextShaded(
    Font &font,
    const std::string &text,
    Colour text_colour,
    Colour background,
    uint32_t w
  );
  static [[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>
  TextShaded(
    Font *font,
    const std::string &text,
    Colour text_colour,
    Colour background,
    uint32_t w
  );

  // TTF_RenderText_Solid
  static [[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>
  TextSolid(Font &font, const std::string &text, Colour c);
  static [[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>
  TextSolid(Font *font, const std::string &text, Colour c);

  // TTF_RenderText_Solid_Wrapped
  static [[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>
  TextSolid(Font &font, const std::string &text, Colour c, uint32_t w);
  static [[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>
  TextSolid(Font *font, const std::string &text, Colour c, uint32_t w);

  // pixels
  std::experimental::mdspan<
    Colour,
    std::experimental::extents<
      unsigned long long,
      std::experimental::dynamic_extent,
      std::experimental::dynamic_extent>>
  Pixels();
  Colour &Pixels(std::size_t x, std::size_t y);
};
} // namespace nge::sdl

#endif