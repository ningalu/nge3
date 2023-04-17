#include "ngsdl/Timer.h"

namespace nge::sdl {
Timer::Timer() { Restart(); }
void Timer::Restart() { start_tick_ = SDL_GetTicks64(); }
Uint64 Timer::GetTicks() const { return SDL_GetTicks64() - start_tick_; }
} // namespace nge::sdl