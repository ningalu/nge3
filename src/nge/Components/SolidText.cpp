#include "nge/Components/SolidText.h"

namespace nge {
SolidText::SolidText(
  std::shared_ptr<Graphics> graphics,
  std::shared_ptr<sdl::Font> font,
  const std::string &text,
  nge::sdl::Colour colour
)
    : Text(graphics, font, text, colour, nge::sdl::FontRenderType::SOLID) {}
} // namespace nge