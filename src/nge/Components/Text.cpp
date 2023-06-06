#include "nge/Components/Text.h"

#include <iostream>

#include "nge/Graphics.h"
#include "ngsdl/Font.h"
#include "ngsdl/Surface.h"
#include "ngsdl/TTFException.h"

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
  switch (type) {
  case sdl::FontRenderType::BLENDED:
    texture_ = std::make_shared<sdl::Texture>(
      graphics->GetRenderer(),
      sdl::Surface::TextBlended(font.get(), text, color)
    );
    break;
  case sdl::FontRenderType::SHADED:
    texture_ = std::make_shared<sdl::Texture>(
      graphics->GetRenderer(),
      sdl::Surface::TextShaded(font.get(), text, color, bg)
    );
    break;
  case sdl::FontRenderType::SOLID:
    texture_ = std::make_shared<sdl::Texture>(
      graphics->GetRenderer(), sdl::Surface::TextSolid(font.get(), text, color)
    );
    break;
  default:
    throw sdl::TTFException{"Unrecognised Font Render Type"};
    break;
  }

  src_ = nge::sdl::Rectangle{0, 0, texture_->GetSize()};
  dst_ = src_;
}

void Text::UpdateText(const std::string &text) {
  switch (type_) {
  case sdl::FontRenderType::BLENDED:
    texture_ = std::make_shared<sdl::Texture>(
      graphics_->GetRenderer(),
      sdl::Surface::TextBlended(font_.get(), text, colour_)
    );
    break;
  case sdl::FontRenderType::SHADED:
    texture_ = std::make_shared<sdl::Texture>(
      graphics_->GetRenderer(),
      sdl::Surface::TextShaded(font_.get(), text, colour_, bg_)
    );
    break;
  case sdl::FontRenderType::SOLID:
    texture_ = std::make_shared<sdl::Texture>(
      graphics_->GetRenderer(),
      sdl::Surface::TextSolid(font_.get(), text, colour_)
    );
    break;
  default:
    throw sdl::TTFException{"Unrecognised Font Render Type"};
    break;
  }
  src_ = nge::sdl::Rectangle{0, 0, texture_->GetSize()};
  dst_.SetW(src_.W());
  dst_.SetH(src_.H());
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