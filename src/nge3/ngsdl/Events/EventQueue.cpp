#include "Events/EventQueue.h"

#include "SDL2/SDL.h"

namespace nge::sdl {
const std::optional<Event> EventQueue::Poll() {
  SDL_Event e;
  if (SDL_PollEvent(&e) == 0) {
    return std::nullopt;
  }
  return Event(e);
}
} // namespace nge::sdl