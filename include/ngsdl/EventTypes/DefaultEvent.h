#ifndef NGSDL_EVENTTYPES_DEFAULTEVENT_H
#define NGSDL_EVENTTYPES_DEFAULTEVENT_H

#include "ngsdl/Events/EventType.h"

#include <SDL2/SDL.h>

namespace nge::sdl {
class DefaultEvent {
public:
  DefaultEvent() = default;
  DefaultEvent(SDL_CommonEvent e);

  [[nodiscard]] Uint32 GetTimestamp() const noexcept;
  [[nodiscard]] EventType GetType() const noexcept;

protected:
  Uint32 timestamp_;
  EventType type_;
};
} // namespace nge::sdl

#endif