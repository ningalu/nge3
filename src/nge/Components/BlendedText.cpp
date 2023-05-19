#include "nge/Components/BlendedText.h"

namespace nge {
BlendedText::BlendedText(
  std::shared_ptr<Graphics> graphics,
  std::shared_ptr<sdl::Font> font,
  const std::string &text,
  nge::sdl::Colour colour
)
    : Text(graphics, font, text, colour, nge::sdl::FontRenderType::BLENDED) {}
} // namespace nge