#include "nge/Components/Text.h"

#include <iostream>

#include "nge/Graphics.h"
#include "ngsdl/Font.h"

namespace nge {
Text::Text(
  const std::shared_ptr<Graphics> &graphics,
  const std::shared_ptr<sdl::Font> &font,
  const std::string &text,
  sdl::Color color,
  sdl::FontRenderType type,
  sdl::Color bg
)
    : SimpleComponent(graphics) {
  texture_ = std::make_shared<sdl::Texture>(
    graphics->GetRenderer(), *font, text, type, color, bg
  );

  src_ = {{0, 0}, texture_->GetSize()};
  dst_ = src_;
  std::cout << src_ << "\n";
}
} // namespace nge