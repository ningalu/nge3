#include "ngsdl/EventTypes/KeyUpEvent.h"

namespace nge::sdl {
KeyUpEvent::KeyUpEvent(SDL_KeyboardEvent e) {
  timestamp_ = e.timestamp;
  window_id_ = e.windowID;
  state_ = KeyState(e.state);
  repeat_ = static_cast<bool>(e.repeat);
  keysym_ = {
    static_cast<Scancode>(e.keysym.scancode),
    static_cast<Keycode>(e.keysym.sym),
    static_cast<KeyMod>(e.keysym.mod)};
}

Uint32 KeyUpEvent::GetWindowID() const { return window_id_; }
KeyState KeyUpEvent::GetState() const { return state_; }
bool KeyUpEvent::IsRepeat() const { return repeat_; }
KeySym KeyUpEvent::GetKeySym() const { return keysym_; }
} // namespace nge::sdl