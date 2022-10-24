#include "EventTypes/DefaultEvent.h"

namespace nge::sdl {
DefaultEvent::DefaultEvent(SDL_CommonEvent e) { timestamp_ = e.timestamp; }

Uint32 DefaultEvent::GetTimestamp() const { return timestamp_; }
EventType DefaultEvent::GetType() const { return type_; }
} // namespace nge::sdl