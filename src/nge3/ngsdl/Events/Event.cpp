#include "Events/Event.h"

namespace nge::sdl {
Event::Event(EventType type) { type_ = type; }
Event::Event(SDL_Event e) {
  switch (e.type) {
  case (SDL_QUIT):
    data_ = QuitEvent{e.quit.timestamp};
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