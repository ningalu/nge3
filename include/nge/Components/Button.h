#ifndef NGE_COMPONENTS_BUTTON_H
#define NGE_COMPONENTS_BUTTON_H

#include <array>

#include "ngsdl/Events/MouseButton.h"

#include "nge/Components/Clickable.h"
#include "nge/Components/Mouse/ClickController.h"
#include "nge/Components/Mouse/HoverController.h"
#include "nge/Components/Mouse/Hoverable.h"

namespace nge {
class Button : public Clickable, public Hoverable {
public:
  std::function<bool(void)> click_valid;
  std::function<bool(void)> hover, prev_hover;

  Button();
  virtual bool ClickValid() const override;
  virtual void Click(nge::sdl::MouseButton b) override;
  virtual void Hold(nge::sdl::MouseButton b) override;
  virtual void Release(nge::sdl::MouseButton b) override;

  [[nodiscard]] virtual bool Hovering() const override;
  [[nodiscard]] virtual bool PrevHovering() const override;
  virtual void OnStartHover() override;
  virtual void OnHoldHover() override;
  virtual void OnReleaseHover() override;

  void AddClickControl(
    nge::sdl::MouseButton b, std::shared_ptr<nge::ClickController> c
  );
  void RemoveClickControl(nge::sdl::MouseButton b);

  void SetHoverControl(std::shared_ptr<HoverController> h);
  void RemoveHoverControl();

protected:
  std::array<std::shared_ptr<ClickController>, 6> click_controls_;
  std::shared_ptr<HoverController> hover_control_;
};
} // namespace nge

#endif