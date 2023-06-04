#include "nge/Components/Shapes/Rectangle.h"

#include "ngsdl/Point.h"

namespace nge {
Rectangle::Rectangle(std::shared_ptr<Graphics> graphics, sdl::Rectangle rect)
    : graphics_(graphics), ngl::Rectangle<int32_t>(rect), base_(rect),
      colour_(0, 0, 0, 255) {}
Rectangle::Rectangle(
  std::shared_ptr<Graphics> graphics, sdl::Rectangle rect, sdl::Colour colour
)
    : graphics_(graphics), base_(rect), ngl::Rectangle<int32_t>(rect),
      colour_(colour) {}

void Rectangle::Draw() {
  graphics_->Draw(sdl::Rectangle(this->As<int32_t>()), colour_);
}

void Rectangle::SetScale(double n) {
  SetW<double>(base_.W() * n);
  SetH<double>(base_.H() * n);
}
[[nodiscard]] bool Rectangle::Overlaps(int32_t x, int32_t y) const {
  return Encloses(x, y);
}

} // namespace nge