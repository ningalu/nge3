#include "ngsdl/EventTypes/DefaultEvent.h"

namespace nge::sdl {
DefaultEvent::DefaultEvent(SDL_CommonEvent e) { timestamp_ = e.timestamp; }

[[nodiscard]] Uint32 DefaultEvent::GetTimestamp() const noexcept {
  return timestamp_;
}
[[nodiscard]] EventType DefaultEvent::GetType() const noexcept { return type_; }
} // namespace nge::sdl