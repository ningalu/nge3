#ifndef NGE3_NGSDL_EVENTS_KEYSYM_H
#define NGE3_NGSDL_EVENTS_KEYSYM_H

#include "Events/KeyMod.h"
#include "Events/Keycode.h"
#include "Events/Scancode.h"

namespace nge::sdl {
class KeySym {
public:
  KeySym() = default;
  KeySym(Scancode scancode, Keycode keycode, KeyMod keymod);

  Scancode GetScancode() const;
  Keycode GetKeycode() const;
  KeyMod GetKeyMod() const;

protected:
  Scancode scancode_;
  Keycode keycode_;
  KeyMod keymod_;
};
} // namespace nge::sdl

#endif