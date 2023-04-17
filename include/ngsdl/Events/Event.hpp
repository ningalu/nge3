#ifndef NGSDL_EVENTS_EVENT_HPP
#define NGSDL_EVENTS_EVENT_HPP

#include <variant>

#include <SDL2/SDL.h>

#include "ngsdl/EventTypes/DefaultEvent.h"
#include "ngsdl/EventTypes/KeyDownEvent.h"
#include "ngsdl/EventTypes/KeyUpEvent.h"
#include "ngsdl/EventTypes/MouseButtonDownEvent.h"
#include "ngsdl/EventTypes/MouseButtonUpEvent.h"
#include "ngsdl/EventTypes/QuitEvent.h"
#include "ngsdl/Events/EventType.h"
#include "ngsdl/Events/EventVisitor.hpp"

namespace nge::sdl {

using EventVariants = std::variant<
  MouseButtonDownEvent,
  MouseButtonUpEvent,
  KeyDownEvent,
  KeyUpEvent,
  QuitEvent,
  DefaultEvent>;

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