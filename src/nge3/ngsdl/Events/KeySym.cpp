#include "Events/KeySym.h"

namespace nge::sdl {
KeySym::KeySym(Scancode scancode, Keycode keycode, KeyMod keymod) {
  scancode_ = scancode;
  keycode_ = keycode;
  keymod_ = keymod;
}
Scancode KeySym::GetScancode() const { return scancode_; }
Keycode KeySym::GetKeycode() const { return keycode_; }
KeyMod KeySym::GetKeyMod() const { return keymod_; }

} // namespace nge::sdl