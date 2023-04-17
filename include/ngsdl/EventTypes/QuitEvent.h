#ifndef NGSDL_EVENTTYPES_QUITEVENT_H
#define NGSDL_EVENTTYPES_QUITEVENT_H

#include <SDL2/SDL.h>
#include <cstdint>

#include "ngsdl/EventTypes/DefaultEvent.h"

namespace nge::sdl {
class QuitEvent : public DefaultEvent {
public:
  QuitEvent() = default;
  QuitEvent(uint32_t timestamp);
};
} // namespace nge::sdl

#endif