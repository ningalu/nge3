#include "nge/Components/Button.h"

namespace nge {
bool Button::Hovering() const { return hover(); }
void Button::Click(nge::sdl::MouseButton b) {
  if (Hovering()) {
    controllers_[static_cast<std::size_t>(b)]->OnClick();
  }
}

void Button::Hold(nge::sdl::MouseButton b) {
  controllers_[static_cast<std::size_t>(b)]->OnHold(Hovering());
}
void Button::Release(nge::sdl::MouseButton b) {
  controllers_[static_cast<std::size_t>(b)]->OnRelease();
}
void Button::AddController(
  nge::sdl::MouseButton b, std::shared_ptr<nge::ClickController> c
) {
  controllers_[static_cast<std::size_t>(b)] = c;
}
void Button::RemoveController(nge::sdl::MouseButton b) {
  controllers_[static_cast<std::size_t>(b)] = {};
}
} // namespace nge