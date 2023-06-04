#ifndef NGE_COMPONENTS_KEYBOARD_KEYABLE_H
#define NGE_COMPONENTS_KEYBOARD_KEYABLE_H

#include "ngsdl/Events/Scancode.h"

namespace nge {
class Keyable {
public:
  virtual void PressKey(nge::sdl::Scancode s) = 0;
  virtual void HoldKey(nge::sdl::Scancode s) = 0;
  virtual void ReleaseKey(nge::sdl::Scancode s) = 0;
  virtual ~Keyable() = 0;
};
} // namespace nge

#endif