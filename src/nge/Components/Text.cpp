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
}

void Text::UpdateText(
  const std::shared_ptr<sdl::Font> &font,
  const std::string &text,
  sdl::Color color,
  sdl::FontRenderType type,
  sdl::Color bg
) {
  texture_ = std::make_shared<sdl::Texture>(
    graphics_->GetRenderer(), *font, text, type, color, bg
  );
  src_ = {{0, 0}, texture_->GetSize()};
  dst_.SetW(src_.GetW());
  dst_.SetH(src_.GetH());
}

Text::~Text() {}
} // namespace nge