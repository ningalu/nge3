#include "ngsdl/Surface.h"

#include <bit>

#include "SDL2/SDL_ttf.h"

#include "ngsdl/Font.h"

namespace nge::sdl {
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextBlended(Font &font, const std::string &text, Colour c) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderText_Blended(
      font.font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c)
    )),
    SDL_FreeSurface};
}
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextBlended(Font *font, const std::string &text, Colour c) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderText_Blended(
      font->font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c)
    )),
    SDL_FreeSurface};
}
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextBlended(Font &font, const std::string &text, Colour c, uint32_t w) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderText_Blended_Wrapped(
      font.font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c), w
    )),
    SDL_FreeSurface};
}
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextBlended(Font *font, const std::string &text, Colour c, uint32_t w) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderText_Blended_Wrapped(
      font->font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c), w
    )),
    SDL_FreeSurface};
}

// TTF_RenderText_Shaded
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextShaded(
    Font &font, const std::string &text, Colour text_colour, Colour background
  ) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderText_Shaded(
      font.font_.get(),
      text.c_str(),
      std::bit_cast<SDL_Color>(text_colour),
      std::bit_cast<SDL_Color>(background)
    )),
    SDL_FreeSurface};
}
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextShaded(
    Font *font, const std::string &text, Colour text_colour, Colour background
  ) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderText_Shaded(
      font->font_.get(),
      text.c_str(),
      std::bit_cast<SDL_Color>(text_colour),
      std::bit_cast<SDL_Color>(background)
    )),
    SDL_FreeSurface};
}

// TTF_RenderText_Shaded_Wrapped
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextShaded(
    Font &font,
    const std::string &text,
    Colour text_colour,
    Colour background,
    uint32_t w
  ) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderText_Shaded_Wrapped(
      font.font_.get(),
      text.c_str(),
      std::bit_cast<SDL_Color>(text_colour),
      std::bit_cast<SDL_Color>(background),
      w
    )),
    SDL_FreeSurface};
}
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextShaded(
    Font *font,
    const std::string &text,
    Colour text_colour,
    Colour background,
    uint32_t w
  ) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderText_Shaded_Wrapped(
      font->font_.get(),
      text.c_str(),
      std::bit_cast<SDL_Color>(text_colour),
      std::bit_cast<SDL_Color>(background),
      w
    )),
    SDL_FreeSurface};
}

[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextSolid(Font &font, const std::string &text, Colour c) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderText_Solid(
      font.font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c)
    )),
    SDL_FreeSurface};
}
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextSolid(Font *font, const std::string &text, Colour c) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderText_Solid(
      font->font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c)
    )),
    SDL_FreeSurface};
}
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextSolid(Font &font, const std::string &text, Colour c, uint32_t w) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderText_Solid_Wrapped(
      font.font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c), w
    )),
    SDL_FreeSurface};
}
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextSolid(Font *font, const std::string &text, Colour c, uint32_t w) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderText_Solid_Wrapped(
      font->font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c), w
    )),
    SDL_FreeSurface};
}

} // namespace nge::sdl