#ifndef NGSDL_SURFACE_H
#define NGSDL_SURFACE_H

#include "SDL2/SDL.h"

#include <memory>
#include <string>

#include "ngsdl/Color.h"

namespace nge::sdl {
class Font;
class Surface : public SDL_Surface {
public:
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
};
} // namespace nge::sdl

#endif