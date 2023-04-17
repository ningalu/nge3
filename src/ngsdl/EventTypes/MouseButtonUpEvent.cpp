#include "ngsdl/EventTypes/MouseButtonUpEvent.h"

namespace nge::sdl {
MouseButtonUpEvent::MouseButtonUpEvent(SDL_MouseButtonEvent e) {
  timestamp_ = e.timestamp;
  window_id_ = e.windowID;
  mouse_id_ = e.which;
  button_ = MouseButton{e.button};
  clicks_ = e.clicks;
  position_ = {e.x, e.y};
}
Uint32 MouseButtonUpEvent::GetWindowID() const { return window_id_; }
Uint32 MouseButtonUpEvent::GetMouseID() const { return mouse_id_; }
MouseButton MouseButtonUpEvent::GetMouseButton() const { return button_; }
MouseButton MouseButtonUpEvent::GetButton() const { return GetMouseButton(); }
int MouseButtonUpEvent::GetClicks() const { return clicks_; }
Point MouseButtonUpEvent::GetPos() const { return position_; }
int MouseButtonUpEvent::GetX() const { return position_.GetX(); }
int MouseButtonUpEvent::GetY() const { return position_.GetY(); }
} // namespace nge::sdl