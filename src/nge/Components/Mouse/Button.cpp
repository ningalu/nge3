#include "nge/Components/Mouse/Button.h"

namespace nge {
Button::Button() {}

bool Button::ClickValid() const { return hover ? hover() : false; }
void Button::Click(nge::sdl::MouseButton b) {
  if (ClickValid()) {
    if (click_controls_[static_cast<std::size_t>(b)]) {
      click_controls_[static_cast<std::size_t>(b)]->OnClick();
    }
  }
}

void Button::Hold(nge::sdl::MouseButton b) {
  if (click_controls_[static_cast<std::size_t>(b)]) {
    click_controls_[static_cast<std::size_t>(b)]->OnHold(ClickValid());
  }
}
void Button::Release(nge::sdl::MouseButton b) {
  if (click_controls_[static_cast<std::size_t>(b)]) {
    click_controls_[static_cast<std::size_t>(b)]->OnRelease();
  }
}

[[nodiscard]] bool Button::Hovering() const { return hover ? hover() : false; }
[[nodiscard]] bool Button::PrevHovering() const {
  return prev_hover ? prev_hover() : false;
}
void Button::OnStartHover() { hover_control_->OnStartHover(); }
void Button::OnHoldHover() { hover_control_->OnHoldHover(); }
void Button::OnReleaseHover() { hover_control_->OnReleaseHover(); }

void Button::AddClickControl(
  nge::sdl::MouseButton b, std::shared_ptr<nge::ClickController> c
) {
  click_controls_[static_cast<std::size_t>(b)] = c;
}
void Button::RemoveClickControl(nge::sdl::MouseButton b) {
  click_controls_[static_cast<std::size_t>(b)] = nullptr;
}

void Button::SetHoverControl(std::shared_ptr<HoverController> h) {
  hover_control_ = h;
}
void Button::RemoveHoverControl() { hover_control_ = nullptr; }
} // namespace nge