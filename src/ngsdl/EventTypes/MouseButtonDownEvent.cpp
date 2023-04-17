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
Uint32 MouseButtonDownEvent::GetWindowID() const { return window_id_; }
Uint32 MouseButtonDownEvent::GetMouseID() const { return mouse_id_; }
MouseButton MouseButtonDownEvent::GetMouseButton() const { return button_; }
MouseButton MouseButtonDownEvent::GetButton() const { return GetMouseButton(); }
int MouseButtonDownEvent::GetClicks() const { return clicks_; }
Point MouseButtonDownEvent::GetPos() const { return position_; }
int MouseButtonDownEvent::GetX() const { return position_.GetX(); }
int MouseButtonDownEvent::GetY() const { return position_.GetY(); }
} // namespace nge::sdl