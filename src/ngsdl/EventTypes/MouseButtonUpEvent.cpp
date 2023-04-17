#include "ngsdl/EventTypes/MouseButtonUpEvent.h"

#include <cstdint>

namespace nge::sdl {
MouseButtonUpEvent::MouseButtonUpEvent(SDL_MouseButtonEvent e) {
  timestamp_ = e.timestamp;
  window_id_ = e.windowID;
  mouse_id_ = e.which;
  button_ = MouseButton{e.button};
  clicks_ = e.clicks;
  position_ = {e.x, e.y};
}
[[nodiscard]] uint32_t MouseButtonUpEvent::GetWindowID() const noexcept {
  return window_id_;
}
[[nodiscard]] uint32_t MouseButtonUpEvent::GetMouseID() const noexcept {
  return mouse_id_;
}
[[nodiscard]] MouseButton MouseButtonUpEvent::GetMouseButton() const noexcept {
  return button_;
}
[[nodiscard]] MouseButton MouseButtonUpEvent::GetButton() const noexcept {
  return GetMouseButton();
}
[[nodiscard]] uint32_t MouseButtonUpEvent::GetClicks() const noexcept {
  return clicks_;
}
[[nodiscard]] Point MouseButtonUpEvent::GetPos() const noexcept {
  return position_;
}
[[nodiscard]] int32_t MouseButtonUpEvent::GetX() const noexcept {
  return position_.GetX();
}
[[nodiscard]] int32_t MouseButtonUpEvent::GetY() const noexcept {
  return position_.GetY();
}
} // namespace nge::sdl