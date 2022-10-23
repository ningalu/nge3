#include "Events/QuitEvent.h"

namespace nge::sdl {
QuitEvent::QuitEvent(Uint32 timestamp) { timestamp_ = timestamp; }
Uint32 QuitEvent::GetTimestamp() const { return timestamp_; }

} // namespace nge::sdl