#include "Events/EventQueue.h"

#pragma warning(push, 0)
#include "SDL2/SDL.h"
#pragma warning(pop)

namespace nge::sdl {
const std::optional<Event> EventQueue::Poll() {
  SDL_Event e;
  if (SDL_PollEvent(&e) == 0) {
    return std::nullopt;
  }
  return Event(e);
}
} // namespace nge::sdl