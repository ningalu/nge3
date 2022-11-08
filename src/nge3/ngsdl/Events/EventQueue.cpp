#include "Events/EventQueue.h"

#include <SDL2/SDL.h>

namespace nge::sdl {
const std::optional<Event> EventQueue::Poll() {
  SDL_Event e;
  if (SDL_PollEvent(&e) == 0) {
    return std::nullopt;
  }
  return Event(e);
}

void EventQueue::Pump() { SDL_PumpEvents(); }

const std::span<const uint8_t> EventQueue::GetKeyboardState() {
  int l;
  const uint8_t *kb = SDL_GetKeyboardState(&l);
  std::span s{kb, static_cast<size_t>(l)};
  return s;
}
} // namespace nge::sdl