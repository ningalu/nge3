#include "ngsdl/EventTypes/KeyDownEvent.h"

namespace nge::sdl {
KeyDownEvent::KeyDownEvent(SDL_KeyboardEvent e) {
  timestamp_ = e.timestamp;
  window_id_ = e.windowID;
  state_ = KeyState(e.state);
  repeat_ = static_cast<bool>(e.repeat);
  keysym_ = {
    static_cast<Scancode>(e.keysym.scancode),
    static_cast<Keycode>(e.keysym.sym),
    static_cast<KeyMod>(e.keysym.mod)};
}

[[nodiscard]] uint32_t KeyDownEvent::GetWindowID() const noexcept {
  return window_id_;
}
[[nodiscard]] KeyState KeyDownEvent::GetState() const noexcept {
  return state_;
}
[[nodiscard]] bool KeyDownEvent::IsRepeat() const noexcept { return repeat_; }
[[nodiscard]] KeySym KeyDownEvent::GetKeySym() const noexcept {
  return keysym_;
}
} // namespace nge::sdl