#include "ngsdl/EventTypes/QuitEvent.h"

namespace nge::sdl {
QuitEvent::QuitEvent(Uint32 timestamp) { timestamp_ = timestamp; }

} // namespace nge::sdl