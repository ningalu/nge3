#include "ngsdl/Events/EventQueue.h"

#include <SDL2/SDL.h>

namespace nge::sdl {
[[nodiscard]] const std::optional<Event> EventQueue::Poll() noexcept {
  SDL_Event e;
  if (SDL_PollEvent(&e) == 0) {
    return std::nullopt;
  }
  return Event(e);
}

void EventQueue::Pump() noexcept { SDL_PumpEvents(); }

[[nodiscard]] const std::span<const uint8_t> EventQueue::GetKeyboardState() {
  int l;
  // const uint8_t *kb = SDL_GetKeyboardState(&l);
  std::span s{SDL_GetKeyboardState(&l), static_cast<size_t>(l)};
  return s;
}

[[nodiscard]] const std::tuple<uint32_t, Point> EventQueue::GetMouseState() {
  int x, y;
  auto state = SDL_GetMouseState(&x, &y);
  return {state, {x, y}};
}

} // namespace nge::sdl