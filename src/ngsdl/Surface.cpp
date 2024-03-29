#include "ngsdl/Surface.h"

#include <bit>

#include "SDL2/SDL_ttf.h"

#include "ngsdl/Font.h"

namespace nge::sdl {
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::RGB(
  uint32_t w, uint32_t h
) {
  // this seems pretty fucking sketchy
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(SDL_CreateRGBSurface(
      0,
      w,
      h,
      32 /*sizeof(Colour) * sizeof(byte)*/,
      0x000000FF,
      0x0000FF00,
      0x00FF0000,
      0xFF000000
    )),
    SDL_FreeSurface};
}

[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextBlended(Font &font, const std::string &text, Colour c) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderUTF8_Blended(
      font.font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c)
    )),
    SDL_FreeSurface};
}
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextBlended(Font *font, const std::string &text, Colour c) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderUTF8_Blended(
      font->font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c)
    )),
    SDL_FreeSurface};
}
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextBlended(Font &font, const std::string &text, Colour c, uint32_t w) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderUTF8_Blended_Wrapped(
      font.font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c), w
    )),
    SDL_FreeSurface};
}
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextBlended(Font *font, const std::string &text, Colour c, uint32_t w) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderUTF8_Blended_Wrapped(
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
    std::bit_cast<Surface *>(TTF_RenderUTF8_Shaded(
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
    std::bit_cast<Surface *>(TTF_RenderUTF8_Shaded(
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
    std::bit_cast<Surface *>(TTF_RenderUTF8_Shaded_Wrapped(
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
    std::bit_cast<Surface *>(TTF_RenderUTF8_Shaded_Wrapped(
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
    std::bit_cast<Surface *>(TTF_RenderUTF8_Solid(
      font.font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c)
    )),
    SDL_FreeSurface};
}
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextSolid(Font *font, const std::string &text, Colour c) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderUTF8_Solid(
      font->font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c)
    )),
    SDL_FreeSurface};
}
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextSolid(Font &font, const std::string &text, Colour c, uint32_t w) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderUTF8_Solid_Wrapped(
      font.font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c), w
    )),
    SDL_FreeSurface};
}
[[nodiscard]] std::unique_ptr<Surface, decltype(&SDL_FreeSurface)> Surface::
  TextSolid(Font *font, const std::string &text, Colour c, uint32_t w) {
  return std::unique_ptr<Surface, decltype(&SDL_FreeSurface)>{
    std::bit_cast<Surface *>(TTF_RenderUTF8_Solid_Wrapped(
      font->font_.get(), text.c_str(), std::bit_cast<SDL_Color>(c), w
    )),
    SDL_FreeSurface};
}

std::experimental::mdspan<
  Colour,
  std::experimental::extents<
    unsigned long long,
    std::experimental::dynamic_extent,
    std::experimental::dynamic_extent>>
Surface::Pixels() {
  return std::experimental::mdspan{std::bit_cast<Colour *>(pixels), h, w};
}
Colour &Surface::Pixels(std::size_t x, std::size_t y) { return Pixels()(x, y); }

} // namespace nge::sdl