#ifndef NGE3_NGSDL_EVENTS_EVENTQUEUE_H
#define NGE3_NGSDL_EVENTS_EVENTQUEUE_H

#include <optional>
#include <span>
#include <tuple>

#include "Events/Event.hpp"
#include "Point.h"

namespace nge::sdl {
// The only real interpretation of the SDL Event Queue is that it's singleton
class EventQueue {
public:
  static const std::optional<Event> Poll();
  static const std::optional<Event> Peep();
  static void Push(Event e);
  static void Pump();

  // SDL_GetKeyboardState
  static const std::span<const uint8_t> GetKeyboardState();
  static const std::tuple<uint32_t, Point> GetMouseState();

  // SDL_WaitEvent
  // SDL_WaitEventTimeout

protected:
private:
};
} // namespace nge::sdl

#endif