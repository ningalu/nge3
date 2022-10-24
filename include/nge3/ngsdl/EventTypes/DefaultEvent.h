#ifndef NGE3_NGSDL_EVENTTYPES_DEFAULTEVENT_H
#define NGE3_NGSDL_EVENTTYPES_DEFAULTEVENT_H

#include "Events/EventType.h"
#include "SDL2/SDL.h"

namespace nge::sdl {
class DefaultEvent {
public:
  DefaultEvent() = default;
  DefaultEvent(SDL_CommonEvent e);

  Uint32 GetTimestamp() const;
  EventType GetType() const;

protected:
  Uint32 timestamp_;
  EventType type_;
};
} // namespace nge::sdl

#endif