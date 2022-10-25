#ifndef NGE3_NGSDL_EVENTS_EVENT_HPP
#define NGE3_NGSDL_EVENTS_EVENT_HPP

#include <variant>

#include "SDL2/SDL.h"

#include "EventType.h"
#include "EventTypes/DefaultEvent.h"
#include "EventTypes/KeyDownEvent.h"
#include "EventTypes/KeyUpEvent.h"
#include "EventTypes/MouseButtonUpEvent.h"
#include "EventTypes/QuitEvent.h"
#include "EventVisitor.hpp"

namespace nge::sdl {
using EventVariants = std::variant<
    MouseButtonUpEvent, KeyDownEvent, KeyUpEvent, QuitEvent, DefaultEvent>;
class EventQueue;
class Event {
  friend class EventQueue;

public:
  Event(EventType type);

  EventType GetType() const;
  void SetType(EventType type);

  template <class... Ts>
  void Visit(EventVisitor<Ts...> callbacks) const {
    std::visit(callbacks, data_);
  }

  const EventVariants &GetEventData() const;

protected:
  Event(SDL_Event e);
  EventType type_;
  EventVariants data_;

private:
};
} // namespace nge::sdl

#endif