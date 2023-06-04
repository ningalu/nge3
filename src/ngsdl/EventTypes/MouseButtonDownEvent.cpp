#include "ngsdl/EventTypes/MouseButtonDownEvent.h"

namespace nge::sdl {
MouseButtonDownEvent::MouseButtonDownEvent(SDL_MouseButtonEvent e) {
  timestamp_ = e.timestamp;
  window_id_ = e.windowID;
  mouse_id_ = e.which;
  button_ = MouseButton{e.button};
  clicks_ = e.clicks;
  position_ = {e.x, e.y};
}
[[nodiscard]] uint32_t MouseButtonDownEvent::GetWindowID() const noexcept {
  return window_id_;
}
[[nodiscard]] uint32_t MouseButtonDownEvent::GetMouseID() const noexcept {
  return mouse_id_;
}
[[nodiscard]] MouseButton MouseButtonDownEvent::GetMouseButton(
) const noexcept {
  return button_;
}
[[nodiscard]] MouseButton MouseButtonDownEvent::GetButton() const noexcept {
  return GetMouseButton();
}
[[nodiscard]] uint32_t MouseButtonDownEvent::GetClicks() const noexcept {
  return clicks_;
}
[[nodiscard]] Point MouseButtonDownEvent::GetPos() const noexcept {
  return position_;
}
[[nodiscard]] int32_t MouseButtonDownEvent::GetX() const noexcept {
  return position_.X();
}
[[nodiscard]] int32_t MouseButtonDownEvent::GetY() const noexcept {
  return position_.Y();
}
} // namespace nge::sdl