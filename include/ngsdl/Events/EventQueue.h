#ifndef NGSDL_EVENTS_EVENTQUEUE_H
#define NGSDL_EVENTS_EVENTQUEUE_H

#include <optional>
#include <span>
#include <tuple>

#include "ngsdl/Events/Event.hpp"
#include "ngsdl/Point.h"

namespace nge::sdl {
// The only real interpretation of the SDL Event Queue is that it's singleton
class EventQueue {
public:
  [[nodiscard]] static const std::optional<Event> Poll() noexcept;
  [[nodiscard]] static const std::optional<Event> Peep() noexcept;
  static void Push(Event e);
  static void Pump() noexcept;

  // SDL_GetKeyboardState
  [[nodiscard]] static const std::span<const uint8_t> GetKeyboardState();
  [[nodiscard]] static const std::tuple<uint32_t, Point> GetMouseState();

  // SDL_WaitEvent
  // SDL_WaitEventTimeout

protected:
private:
};
} // namespace nge::sdl

#endif