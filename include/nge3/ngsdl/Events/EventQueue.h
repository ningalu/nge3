#ifndef NGE3_NGSDL_EVENTS_EVENTQUEUE_H
#define NGE3_NGSDL_EVENTS_EVENTQUEUE_H

#include <optional>

#include "Events/Event.h"

namespace nge::sdl {
// The only real interpretation of the SDL Event Queue is that it's singleton
class EventQueue {
public:
  const static std::optional<Event> Poll();
  const static std::optional<Event> Peep();
  const static void Push(Event e);

  // SDL_WaitEvent
  // SDL_WaitEventTimeout

protected:
private:
};
} // namespace nge::sdl

#endif