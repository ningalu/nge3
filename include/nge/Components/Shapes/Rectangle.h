#ifndef NGE_COMPONENTS_SHAPES_RECTANGLE_H
#define NGE_COMPONENTS_SHAPES_RECTANGLE_H

#include <memory>

#include "nge/Components/Drawing/Drawable.h"
#include "nge/Components/Drawing/Translatable.h"
#include "nge/Graphics.h"

#include "ngsdl/Color.h"
#include "ngsdl/Rectangle.h"

namespace nge::shape {
class Rectangle : public Drawable, public Translatable {
public:
  Rectangle() = delete;

  Rectangle(std::shared_ptr<Graphics> graphics, sdl::Rectangle rect);
  Rectangle(
    std::shared_ptr<Graphics> graphics, sdl::Rectangle rect, sdl::Colour colour
  );

  virtual void Draw() override;
  virtual void SetScale(double n) override;
  [[nodiscard]] virtual bool Overlaps(int32_t x, int32_t y) const override;

  [[nodiscard]] virtual sdl::Point GetPos() override;
  [[nodiscard]] virtual int32_t GetX() const override;
  [[nodiscard]] virtual int32_t GetY() const override;
  virtual void SetPos(sdl::Point p) override;
  virtual void SetPos(int32_t x, int32_t y) override;
  virtual void SetX(int32_t x) override;
  virtual void SetY(int32_t y) override;
  virtual void MoveX(int32_t x) override;
  virtual void MoveY(int32_t y) override;

  std::tuple<int32_t, int32_t> GetSize() const noexcept;
  int32_t GetW() const noexcept;
  int32_t GetH() const noexcept;

  int32_t Top() const;
  int32_t Bottom() const;
  int32_t Left() const;
  int32_t Right() const;

protected:
  std::shared_ptr<Graphics> graphics_;
  sdl::Rectangle base_, drawn_;
  sdl::Colour colour_;
  double scale;
};
} // namespace nge::shape

#endif