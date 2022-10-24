#ifndef NGE3_NGSDL_EVENTS_KEYUPEVENT_H
#define NGE3_NGSDL_EVENTS_KEYUPEVENT_H

#include "SDL2/SDL.h"

#include "Events/KeyState.h"

namespace nge::sdl {
class KeyUpEvent {
public:
  KeyUpEvent() = default;
  KeyUpEvent(SDL_KeyboardEvent e);

  Uint32 GetTimestamp() const;
  Uint32 GetWindowID() const;
  KeyState GetState() const;
  bool IsRepeat() const;

protected:
  Uint32 timestamp_, window_id_;
  KeyState state_;
  bool repeat_;
};
} // namespace nge::sdl

#endif