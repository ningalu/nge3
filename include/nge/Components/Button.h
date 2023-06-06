#ifndef NGE_COMPONENTS_BUTTON_H
#define NGE_COMPONENTS_BUTTON_H

#include "nge/Components/Drawing/BasicGraphicsUser.h"
#include "nge/Components/Mouse/BasicMouseUser.h"

#include <functional>
#include <memory>
#include <optional>

#include "nge/Graphics.h"
#include "nge/Input.h"

namespace nge {
class Button : public Drawable, public BasicMouseUser {
public:
  Button() = delete;
  Button(
    std::shared_ptr<Input> input,
    std::shared_ptr<BasicGraphicsUser> graphic,
    std::function<void(void)> click
  );

  virtual bool ClickValid() const override;

  [[nodiscard]] virtual bool Hovering() const override;
  [[nodiscard]] virtual bool PrevHovering() const override;

  virtual void Draw() override;
  virtual void SetScale(double n) override;
  [[nodiscard]] virtual bool Overlaps(int32_t x, int32_t y) const override;

  void SetPos(nge::sdl::Point p);
  void SetPos(int32_t x, int32_t y);

  [[nodiscard]] std::shared_ptr<BasicGraphicsUser> BaseGraphic() const;
  void SetBaseGraphic(std::shared_ptr<BasicGraphicsUser>);

  [[nodiscard]] std::shared_ptr<BasicGraphicsUser> HoverGraphic() const;
  void SetHoverGraphic(std::shared_ptr<BasicGraphicsUser>);

  [[nodiscard]] std::shared_ptr<BasicGraphicsUser> HoldGraphic() const;
  void SetHoldGraphic(std::shared_ptr<BasicGraphicsUser>);

protected:
  nge::sdl::Point pos_;
  std::shared_ptr<BasicGraphicsUser> base_graphic;
  std::shared_ptr<BasicGraphicsUser> hover_graphic;
  std::shared_ptr<BasicGraphicsUser> hold_graphic;

  std::shared_ptr<Input> input_;
};
} // namespace nge

#endif