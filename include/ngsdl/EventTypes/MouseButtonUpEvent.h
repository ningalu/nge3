#ifndef NGE3_NGSDL_EVENTTYPES_MOUSEBUTTONUPEVENT_H
#define NGE3_NGSDL_EVENTTYPES_MOUSEBUTTONUPEVENT_H

#include <SDL2/SDL.h>

#include "ngsdl/EventTypes/DefaultEvent.h"
#include "ngsdl/Events/MouseButton.h"
#include "ngsdl/Point.h"

namespace nge::sdl {
class MouseButtonUpEvent : public DefaultEvent {
public:
  MouseButtonUpEvent() = default;
  MouseButtonUpEvent(SDL_MouseButtonEvent e);

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
using MouseUpEvent = MouseButtonUpEvent;
} // namespace nge::sdl

#endif