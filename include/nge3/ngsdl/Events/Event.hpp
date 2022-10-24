#ifndef NGE3_NGSDL_EVENTS_EVENT_HPP
#define NGE3_NGSDL_EVENTS_EVENT_HPP

#include <variant>

#include "SDL2/SDL.h"

#include "EventType.h"
#include "EventVisitor.hpp"
#include "Events/KeyUpEvent.h"
#include "Events/QuitEvent.h"

namespace nge::sdl {
using EventVariants = std::variant<KeyUpEvent, QuitEvent, int>;
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