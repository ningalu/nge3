#include "Events/Event.hpp"

namespace nge::sdl {
Event::Event(EventType type) { type_ = type; }
Event::Event(SDL_Event e) {
  switch (e.type) {
  case (SDL_QUIT):
    data_ = QuitEvent{e.quit.timestamp};
    break;
  case (SDL_KEYUP):
    data_ = KeyUpEvent(e.key);
    break;
  default:
    data_ = 0;
  }
  type_ = EventType(e.type);
}

EventType Event::GetType() const { return type_; }
void Event::SetType(EventType type) { type_ = type; }

const EventVariants &Event::GetEventData() const { return data_; }
} // namespace nge::sdl