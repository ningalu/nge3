#include "Events/KeyUpEvent.h"

namespace nge::sdl {
KeyUpEvent::KeyUpEvent(SDL_KeyboardEvent e) {
  timestamp_ = e.timestamp;
  window_id_ = e.windowID;
  state_ = KeyState(e.state);
  repeat_ = e.repeat;
}

Uint32 KeyUpEvent::GetTimestamp() const { return timestamp_; }
Uint32 KeyUpEvent::GetWindowID() const { return window_id_; }
KeyState KeyUpEvent::GetState() const { return state_; }
bool KeyUpEvent::IsRepeat() const { return repeat_; }
} // namespace nge::sdl