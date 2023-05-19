#include "nge/Components/ShadedText.h"

namespace nge {
ShadedText::ShadedText(
  std::shared_ptr<Graphics> graphics,
  std::shared_ptr<sdl::Font> font,
  const std::string &text,
  nge::sdl::Colour colour,
  nge::sdl::Colour bg
)
    : Text(graphics, font, text, colour, nge::sdl::FontRenderType::SHADED, bg) {
}
} // namespace nge