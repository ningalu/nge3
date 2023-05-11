#ifndef NGE_COMPONENTS_BUTTON_H
#define NGE_COMPONENTS_BUTTON_H

#include <array>

#include "ngsdl/Events/MouseButton.h"

#include "nge/Components/Clickable.h"
#include "nge/Components/Mouse/ClickController.h"

namespace nge {
class Button : Clickable {
public:
  Button() = default;
  virtual bool Hovering() const override;
  virtual void Click(nge::sdl::MouseButton b) override;
  virtual void Hold(nge::sdl::MouseButton b) override;
  virtual void Release(nge::sdl::MouseButton b) override;

  void AddController(
    nge::sdl::MouseButton b, std::shared_ptr<nge::ClickController> c
  );
  void RemoveController(nge::sdl::MouseButton b);
  std::function<bool(void)> hover;

protected:
  std::array<std::shared_ptr<nge::ClickController>, 6> controllers_;
};
} // namespace nge

#endif