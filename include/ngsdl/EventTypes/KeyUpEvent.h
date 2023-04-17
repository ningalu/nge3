#ifndef NGSDL_EVENTTYPES_KEYUPEVENT_H
#define NGSDL_EVENTTYPES_KEYUPEVENT_H

#include <SDL2/SDL.h>
#include <cstdint>

#include "ngsdl/EventTypes/DefaultEvent.h"
#include "ngsdl/Events/KeyState.h"
#include "ngsdl/Events/KeySym.h"

namespace nge::sdl {
class KeyUpEvent : public DefaultEvent {
public:
  KeyUpEvent() = default;
  KeyUpEvent(SDL_KeyboardEvent e);

  [[nodiscard]] uint32_t GetWindowID() const noexcept;
  [[nodiscard]] KeyState GetState() const noexcept;
  [[nodiscard]] bool IsRepeat() const noexcept;
  [[nodiscard]] KeySym GetKeySym() const noexcept;

protected:
  uint32_t window_id_;
  KeyState state_;
  bool repeat_;
  KeySym keysym_;
};
} // namespace nge::sdl

#endif