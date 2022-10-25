#include "EventTypes/KeyDownEvent.h"

namespace nge::sdl {
KeyDownEvent::KeyDownEvent(SDL_KeyboardEvent e) {
  timestamp_ = e.timestamp;
  window_id_ = e.windowID;
  state_ = KeyState(e.state);
  repeat_ = e.repeat;
  keysym_ = {
      Scancode{e.keysym.scancode}, Keycode{e.keysym.sym}, KeyMod{e.keysym.mod}};
}

Uint32 KeyDownEvent::GetWindowID() const { return window_id_; }
KeyState KeyDownEvent::GetState() const { return state_; }
bool KeyDownEvent::IsRepeat() const { return repeat_; }
KeySym KeyDownEvent::GetKeySym() const { return keysym_; }
} // namespace nge::sdl