#ifndef NGSDL_EVENTTYPES_MOUSEBUTTONUPEVENT_H
#define NGSDL_EVENTTYPES_MOUSEBUTTONUPEVENT_H

#include <SDL2/SDL.h>
#include <cstdint>

#include "ngsdl/EventTypes/DefaultEvent.h"
#include "ngsdl/Events/MouseButton.h"
#include "ngsdl/Point.h"

namespace nge::sdl {
class MouseButtonUpEvent : public DefaultEvent {
public:
  MouseButtonUpEvent() = default;
  MouseButtonUpEvent(SDL_MouseButtonEvent e);

  [[nodiscard]] uint32_t GetWindowID() const noexcept;
  [[nodiscard]] uint32_t GetMouseID() const noexcept;
  [[nodiscard]] MouseButton GetMouseButton() const noexcept;
  [[nodiscard]] MouseButton GetButton() const noexcept;
  [[nodiscard]] uint32_t GetClicks() const noexcept;
  [[nodiscard]] Point GetPos() const noexcept;
  [[nodiscard]] int32_t GetX() const noexcept;
  [[nodiscard]] int32_t GetY() const noexcept;

protected:
  uint32_t window_id_, mouse_id_;
  MouseButton button_;
  uint32_t clicks_;
  Point position_;
};
using MouseUpEvent = MouseButtonUpEvent;
} // namespace nge::sdl

#endif