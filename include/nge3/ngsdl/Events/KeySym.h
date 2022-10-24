#ifndef NGE3_NGSDL_EVENTS_KEYSYM_H
#define NGE3_NGSDL_EVENTS_KEYSYM_H

#include "Events/Scancode.h"

namespace nge::sdl {
class KeySym {
public:
  KeySym() = default;
  KeySym(Scancode scancode);

  Scancode GetScancode() const;

protected:
  Scancode scancode_;
};
} // namespace nge::sdl

#endif