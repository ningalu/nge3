#ifndef NGE_COMPONENTS_KEYBOARD_KEYABLE_H
#define NGE_COMPONENTS_KEYBOARD_KEYABLE_H

#include "ngsdl/Events/Scancode.h"

namespace nge {
class Keyable {
public:
  virtual void PressKey(nge::sdl::Scancode) = 0;
  virtual void HoldKey(nge::sdl::Scancode) = 0;
  virtual void ReleaseKey(nge::sdl::Scancode) = 0;
  ~Keyable();
};
} // namespace nge

#endif