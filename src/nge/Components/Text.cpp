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
    : BasicGraphicsUser(graphics), font_(font), colour_(color), bg_(bg),
      type_(type) {
  texture_ = std::make_shared<sdl::Texture>(
    graphics->GetRenderer(), *font, text, type, color, bg
  );

  src_ = {{0, 0}, texture_->GetSize()};
  dst_ = src_;
}

void Text::UpdateText(const std::string &text) {
  texture_ = std::make_shared<sdl::Texture>(
    graphics_->GetRenderer(), *font_, text, type_, colour_, bg_
  );
  src_ = {{0, 0}, texture_->GetSize()};
  dst_.SetW(src_.GetW());
  dst_.SetH(src_.GetH());
}
void Text::UpdateText(
  const std::shared_ptr<sdl::Font> &font,
  const std::string &text,
  sdl::Color color,
  sdl::FontRenderType type,
  sdl::Color bg
) {
  font_ = font;
  colour_ = color;
  type_ = type;
  bg_ = bg;
  UpdateText(text);
}

Text::~Text() {}
} // namespace nge