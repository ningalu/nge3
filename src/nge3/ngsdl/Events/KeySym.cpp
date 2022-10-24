#include "Events/KeySym.h"

namespace nge::sdl {
KeySym::KeySym(Scancode scancode) { scancode_ = scancode; }
Scancode KeySym::GetScancode() const { return scancode_; }
} // namespace nge::sdl