#include "ngsdl/Font.h"

#include "SDL2/SDL_ttf.h"

#include "ngsdl/Renderer.h"
#include "ngsdl/SDLException.h"
#include "ngsdl/Surface.h"
#include "ngsdl/TTFException.h"
#include "ngsdl/Texture.h"

namespace nge::sdl {
Font::Font(const std::string &filename, int point_size)
    : font_(nullptr, TTF_CloseFont) {
  auto f = TTF_OpenFont(filename.c_str(), point_size);
  if (f == nullptr) {
    throw TTFException("Font couldn't be opened");
  }
  font_.reset(f);
}

[[nodiscard]] Texture Font::CreateBlendedTexture(
  const Renderer &renderer, const std::string &text, Colour colour
) {
  return Texture{renderer, Surface::TextBlended(this, text, colour)};
}
[[nodiscard]] Texture Font::CreateBlendedTexture(
  const Renderer &renderer,
  const std::string &text,
  Colour colour,
  uint32_t wrap_length
) {
  return Texture{
    renderer, Surface::TextBlended(this, text, colour, wrap_length)};
}

[[nodiscard]] Texture Font::CreateShadedTexture(
  const Renderer &renderer,
  const std::string &text,
  Colour foreground,
  Colour background
) {
  return Texture{
    renderer, Surface::TextShaded(this, text, foreground, background)};
}

[[nodiscard]] Texture Font::CreateShadedTexture(
  const Renderer &renderer,
  const std::string &text,
  Colour foreground,
  Colour background,
  uint32_t wrap_length
) {
  return Texture{
    renderer,
    Surface::TextShaded(this, text, foreground, background, wrap_length)};
}

[[nodiscard]] Texture Font::CreateSolidTexture(
  const Renderer &renderer, const std::string &text, Colour colour
) {
  return Texture{renderer, Surface::TextBlended(this, text, colour)};
}
[[nodiscard]] Texture Font::CreateSolidTexture(
  const Renderer &renderer,
  const std::string &text,
  Colour colour,
  uint32_t wrap_length
) {
  return Texture{
    renderer, Surface::TextBlended(this, text, colour, wrap_length)};
}

void Font::SetFontSize(int point_size) {
  if (TTF_SetFontSize(font_.get(), point_size) != 0) {
    throw TTFException("Font couldn't be resized");
  }
}

std::tuple<int, int> Font::CalcTextSize(const std::string &text) const {
  int w, h;
  if (TTF_SizeText(font_.get(), text.c_str(), &w, &h) != 0) {
    throw TTFException("Text size coudln't be calculated");
  }
  return {w, h};
}

Font::~Font() {}

} // namespace nge::sdl