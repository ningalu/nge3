#ifndef NGE3_NGSDL_EVENTTYPES_KEYDOWNEVENT_H
#define NGE3_NGSDL_EVENTTYPES_KEYDOWNEVENT_H

#include "EventTypes/DefaultEvent.h"
#include "Events/KeyState.h"
#include "Events/KeySym.h"

namespace nge::sdl {
class KeyDownEvent : public DefaultEvent {
public:
  KeyDownEvent() = default;
  KeyDownEvent(SDL_KeyboardEvent e);

  Uint32 GetWindowID() const;
  KeyState GetState() const;
  bool IsRepeat() const;
  KeySym GetKeySym() const;

protected:
  Uint32 window_id_;
  KeyState state_;
  bool repeat_;
  KeySym keysym_;
};
} // namespace nge::sdl

#endif