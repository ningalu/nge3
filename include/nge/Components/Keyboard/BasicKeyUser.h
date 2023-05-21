#ifndef NGE_COMPONENTS_KEYBOARD_BASICKEYUSER_H
#define NGE_COMPONENTS_KEYBOARD_BASICKEYUSER_H

#include <functional>

#include "nge/Components/Keyboard/Keyable.h"

namespace nge {
class BasicKeyUser : public Keyable {
public:
  virtual void PressKey(nge::sdl::Scancode) override;
  virtual void HoldKey(nge::sdl::Scancode) override;
  virtual void ReleaseKey(nge::sdl::Scancode) override;
  std::function<void(nge::sdl::Scancode)> press, hold, release;
};
} // namespace nge

#endif