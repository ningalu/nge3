#ifndef NGE_COMPONENTS_SHAPES_RECTANGLE_H
#define NGE_COMPONENTS_SHAPES_RECTANGLE_H

#include <memory>

#include "misc/Rectangle.hpp"

#include "nge/Components/Drawing/Drawable.h"
#include "nge/Components/Drawing/Translatable.h"
#include "nge/Graphics.h"

#include "ngsdl/Color.h"
#include "ngsdl/Rectangle.h"

namespace nge {
class Rectangle : public Drawable, public ngl::Rectangle<int32_t> {
public:
  Rectangle() = delete;

  Rectangle(std::shared_ptr<Graphics> graphics, sdl::Rectangle rect);
  Rectangle(
    std::shared_ptr<Graphics> graphics, sdl::Rectangle rect, sdl::Colour colour
  );

  virtual void Draw() override;
  virtual void SetScale(double n) override;
  [[nodiscard]] virtual bool Overlaps(int32_t x, int32_t y) const override;

  std::tuple<int32_t, int32_t> GetSize() const noexcept;

protected:
  std::shared_ptr<Graphics> graphics_;
  sdl::Rectangle base_;
  sdl::Colour colour_;
  double scale;
};
} // namespace nge

#endif