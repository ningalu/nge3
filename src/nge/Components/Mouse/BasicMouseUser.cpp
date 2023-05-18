#include "nge/Components/Mouse/BasicMouseUser.h"

namespace nge {
BasicMouseUser::BasicMouseUser() {}

bool BasicMouseUser::ClickValid() const { return hover ? hover() : false; }
void BasicMouseUser::Click(nge::sdl::MouseButton b) {
  if (ClickValid()) {
    if (click_controls_[static_cast<std::size_t>(b)]) {
      click_controls_[static_cast<std::size_t>(b)]->OnClick();
    }
  }
}

void BasicMouseUser::Hold(nge::sdl::MouseButton b) {
  if (click_controls_[static_cast<std::size_t>(b)]) {
    click_controls_[static_cast<std::size_t>(b)]->OnHold(ClickValid());
  }
}

void BasicMouseUser::LoseHold(nge::sdl::MouseButton b) {
  if (click_controls_[static_cast<std::size_t>(b)]) {
    click_controls_[static_cast<std::size_t>(b)]->OnLoseHold();
  }
}

void BasicMouseUser::Release(nge::sdl::MouseButton b) {
  if (click_controls_[static_cast<std::size_t>(b)]) {
    click_controls_[static_cast<std::size_t>(b)]->OnRelease();
  }
}

[[nodiscard]] bool BasicMouseUser::Hovering() const {
  return hover ? hover() : false;
}
[[nodiscard]] bool BasicMouseUser::PrevHovering() const {
  return prev_hover ? prev_hover() : false;
}
void BasicMouseUser::OnStartHover() { hover_control_->OnStartHover(); }
void BasicMouseUser::OnHoldHover() { hover_control_->OnHoldHover(); }
void BasicMouseUser::OnReleaseHover() { hover_control_->OnReleaseHover(); }

void BasicMouseUser::AddClickControl(
  nge::sdl::MouseButton b, std::shared_ptr<nge::ClickController> c
) {
  click_controls_[static_cast<std::size_t>(b)] = c;
}
void BasicMouseUser::RemoveClickControl(nge::sdl::MouseButton b) {
  click_controls_[static_cast<std::size_t>(b)] = nullptr;
}

void BasicMouseUser::SetHoverControl(std::shared_ptr<HoverController> h) {
  hover_control_ = h;
}
void BasicMouseUser::RemoveHoverControl() { hover_control_ = nullptr; }
} // namespace nge