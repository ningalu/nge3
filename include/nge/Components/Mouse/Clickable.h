#ifndef NGE_COMPONENTS_MOUSE_CLICKABLE_H
#define NGE_COMPONENTS_MOUSE_CLICKABLE_H

#include <functional>
#include <memory>

#include "ngsdl/Events/MouseButton.h"

namespace nge {
class Clickable {
public:
  virtual bool ClickValid() const = 0;
  virtual void Click(nge::sdl::MouseButton b) = 0;
  virtual void Hold(nge::sdl::MouseButton b) = 0;
  virtual void Release(nge::sdl::MouseButton b) = 0;

  virtual ~Clickable() = default;
};
} // namespace nge

#endif