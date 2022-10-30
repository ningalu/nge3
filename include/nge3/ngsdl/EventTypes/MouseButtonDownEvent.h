#ifndef NGE3_NGSDL_EVENTTYPES_MOUSEBUTTONDOWNEVENT_H
#define NGE3_NGSDL_EVENTTYPES_MOUSEBUTTONDOWNEVENT_H

#include <SDL2/SDL.h>

#include "EventTypes/DefaultEvent.h"
#include "Events/MouseButton.h"
#include "Point.h"

namespace nge::sdl {
class MouseButtonDownEvent : public DefaultEvent {
public:
  MouseButtonDownEvent() = default;
  MouseButtonDownEvent(SDL_MouseButtonEvent e);

  Uint32 GetWindowID() const;
  Uint32 GetMouseID() const;
  MouseButton GetMouseButton() const;
  MouseButton GetButton() const;
  int GetClicks() const;
  Point GetPos() const;
  int GetX() const;
  int GetY() const;

protected:
  Uint32 window_id_, mouse_id_;
  MouseButton button_;
  int clicks_;
  Point position_;
};
using MouseDownEvent = MouseButtonDownEvent;
} // namespace nge::sdl

#endif