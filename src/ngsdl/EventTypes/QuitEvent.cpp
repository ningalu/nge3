#include "ngsdl/EventTypes/QuitEvent.h"

namespace nge::sdl {
QuitEvent::QuitEvent(uint32_t timestamp) { timestamp_ = timestamp; }

} // namespace nge::sdl