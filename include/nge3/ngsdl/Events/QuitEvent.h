#ifndef NGE3_NGSDL_EVENTS_QUITEVENT_H
#define NGE3_NGSDL_EVENTS_QUITEVENT_H

#include "SDL2/SDL.h"

#include "Events/DefaultEvent.h"

namespace nge::sdl {
class QuitEvent : public DefaultEvent {
public:
  QuitEvent() = default;
  QuitEvent(Uint32 timestamp);
};
} // namespace nge::sdl

#endif