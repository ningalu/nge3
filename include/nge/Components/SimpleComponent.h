#ifndef NGE3_NGE_COMPONENTS_SIMPLECOMPONENT_H
#define NGE3_NGE_COMPONENTS_SIMPLECOMPONENT_H

#include <memory>
#include <tuple>

#include "nge/Components/Component.h"
#include "ngsdl/Rectangle.h"

namespace nge {
namespace sdl {
class Texture;
}
class Graphics;
} // namespace nge

namespace nge {
class SimpleComponent : public Component {
public:
  SimpleComponent() = default;
  SimpleComponent(const std::shared_ptr<Graphics> &graphics);

  virtual void Rotate(double angle) override;
  virtual double GetAngle() override;
  virtual void SetAngle(double angle) override;

  [[nodiscard]] virtual sdl::Point GetPos() override;
  [[nodiscard]] virtual int32_t GetX() const override;
  [[nodiscard]] virtual int32_t GetY() const override;
  virtual void SetPos(sdl::Point p) override;
  virtual void SetPos(int32_t x, int32_t y) override;
  virtual void SetX(int x) override;
  virtual void SetY(int y) override;
  virtual void MoveX(int x) override;
  virtual void MoveY(int y) override;

  virtual void Draw() override;
  [[nodiscard]] virtual bool Overlaps(int32_t x, int32_t y) const override;
  [[nodiscard]] virtual uint32_t GetDrawPriority() const override;

  void SetZ(int32_t z) noexcept;
  [[nodiscard]] int32_t GetZ() const noexcept;
  void SetDrawPriority(int32_t p) noexcept;

  virtual std::tuple<int32_t, int32_t> GetSize() const noexcept;
  virtual int32_t GetW() const noexcept;
  virtual int32_t GetH() const noexcept;

  virtual ~SimpleComponent();

protected:
  std::shared_ptr<Graphics> graphics_;
  std::shared_ptr<sdl::Texture> texture_;
  sdl::Rect src_, dst_;
  double angle_;
  uint32_t draw_priority_;
};
} // namespace nge

#endif