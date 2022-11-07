#include "EventTypes/KeyDownEvent.h"

namespace nge::sdl {
KeyDownEvent::KeyDownEvent(SDL_KeyboardEvent e) {
  timestamp_ = e.timestamp;
  window_id_ = e.windowID;
  state_ = KeyState(e.state);
  repeat_ = static_cast<bool>(e.repeat);
  keysym_ = {
    static_cast<Scancode>(e.keysym.scancode), static_cast<Keycode>(e.keysym.sym), static_cast<KeyMod>(e.keysym.mod)};
}

Uint32 KeyDownEvent::GetWindowID() const { return window_id_; }
KeyState KeyDownEvent::GetState() const { return state_; }
bool KeyDownEvent::IsRepeat() const { return repeat_; }
KeySym KeyDownEvent::GetKeySym() const { return keysym_; }
} // namespace nge::sdl