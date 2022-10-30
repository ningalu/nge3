#ifndef NGE3_NGSDL_EVENTTYPES_QUITEVENT_H
#define NGE3_NGSDL_EVENTTYPES_QUITEVENT_H

#include <SDL2/SDL.h>

#include "EventTypes/DefaultEvent.h"

namespace nge::sdl {
class QuitEvent : public DefaultEvent {
public:
  QuitEvent() = default;
  QuitEvent(Uint32 timestamp);
};
} // namespace nge::sdl

#endif