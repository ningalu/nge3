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
  case (SDL_KEYDOWN):
    data_ = KeyDownEvent(e.key);
    break;
  case (SDL_MOUSEBUTTONUP):
    data_ = MouseButtonUpEvent(e.button);
    break;
  default:
    data_ = DefaultEvent(e.common);
  }
  type_ = EventType(e.type);
}

EventType Event::GetType() const { return type_; }
void Event::SetType(EventType type) { type_ = type; }

const EventVariants &Event::GetEventData() const { return data_; }
} // namespace nge::sdl