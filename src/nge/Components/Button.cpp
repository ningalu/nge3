#include "nge/Components/Button.h"

#include <utility>

#include "ngsdl/Events/MouseButton.h"

namespace nge {
Button::Button(
  std::shared_ptr<Graphics> graphics,
  std::shared_ptr<Input> input,
  std::shared_ptr<BasicGraphicsUser> graphic,
  std::function<void(void)> click
)
    : base_graphic(graphic), input_(input) {
  auto c = std::make_shared<ClickController>();
  c->release = click;
  AddClickControl(sdl::MouseButton::LEFT, c);
  hover_control_ = std::make_shared<HoverController>();
}

bool Button::ClickValid() const {
  return Overlaps(input_->MouseX(), input_->MouseY());
}
[[nodiscard]] bool Button::Hovering() const {
  return Overlaps(input_->MouseX(), input_->MouseY());
}
[[nodiscard]] bool Button::PrevHovering() const {
  return Overlaps(input_->PrevMouseX(), input_->PrevMouseY());
}

void Button::Draw() {
  if (hold_graphic) {
    if (click_controls_[static_cast<uint8_t>(sdl::MouseButton::LEFT)]->Held()) {
      hold_graphic->Draw();
      return;
    }
  }
  if (hover_graphic) {
    if (Hovering()) {
      hover_graphic->Draw();
      return;
    }
  }
  base_graphic->Draw();
}
void Button::SetScale([[maybe_unused]] double n) {}
[[nodiscard]] bool Button::Overlaps(int32_t x, int32_t y) const {
  return base_graphic->Overlaps(x, y);
}

void Button::SetPos(nge::sdl::Point p) { SetPos(p.X(), p.Y()); }
void Button::SetPos(int32_t x, int32_t y) {
  pos_ = sdl::Point{x, y};
  base_graphic->SetPos(pos_);
  if (hover_graphic) {
    hover_graphic->SetPos(pos_);
  }
  if (hold_graphic) {
    hold_graphic->SetPos(pos_);
  }
}

[[nodiscard]] std::shared_ptr<BasicGraphicsUser> Button::BaseGraphic() const {
  return base_graphic;
}
void Button::SetBaseGraphic(std::shared_ptr<BasicGraphicsUser> g) {
  base_graphic = g;
  base_graphic->SetPos(pos_);
}
[[nodiscard]] std::shared_ptr<BasicGraphicsUser> Button::HoverGraphic() const {
  return hover_graphic;
}
void Button::SetHoverGraphic(std::shared_ptr<BasicGraphicsUser> g) {
  hover_graphic = g;
  hover_graphic->SetPos(pos_);
}
[[nodiscard]] std::shared_ptr<BasicGraphicsUser> Button::HoldGraphic() const {
  return hold_graphic;
}
void Button::SetHoldGraphic(std::shared_ptr<BasicGraphicsUser> g) {
  hold_graphic = g;
  hold_graphic->SetPos(pos_);
}

} // namespace nge