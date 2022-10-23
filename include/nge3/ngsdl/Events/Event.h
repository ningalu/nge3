#ifndef NGE3_NGSDL_EVENTS_EVENT_H
#define NGE3_NGSDL_EVENTS_EVENT_H

#include <variant>

#include "SDL2/SDL.h"

#include "EventType.h"
#include "QuitEvent.h"

namespace nge::sdl {
using EventVariants = std::variant<QuitEvent, int>;
class EventQueue;
class Event {
  friend class EventQueue;

public:
  Event(EventType type);

  EventType GetType() const;
  void SetType(EventType type);

  const EventVariants &GetEventData() const;

protected:
  Event(SDL_Event e);
  EventType type_;
  EventVariants data_;

private:
};
} // namespace nge::sdl

#endif