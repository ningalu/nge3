#include "nge/Components/Shapes/Rectangle.h"

#include "ngsdl/Point.h"

namespace nge {
Rectangle::Rectangle(std::shared_ptr<Graphics> graphics, sdl::Rect rect)
    : graphics_(graphics), base_(rect), drawn_(rect), colour_(0, 0, 0, 255) {}
Rectangle::Rectangle(
  std::shared_ptr<Graphics> graphics, sdl::Rect rect, sdl::Colour colour
)
    : graphics_(graphics), base_(rect), drawn_(rect), colour_(colour) {}

void Rectangle::Draw() { graphics_->Draw(drawn_, colour_); }

void Rectangle::SetScale(double n) {
  drawn_ = sdl::Rect{
    base_.GetX(),
    base_.GetY(),
    static_cast<int32_t>(base_.GetW() * n),
    static_cast<int32_t>(base_.GetH() * n)};
}
[[nodiscard]] bool Rectangle::Overlaps(int32_t x, int32_t y) const {
  return drawn_.Encloses(sdl::Point{x, y});
}

[[nodiscard]] sdl::Point Rectangle::GetPos() { return drawn_.GetPos(); }
[[nodiscard]] int32_t Rectangle::GetX() const { return drawn_.GetX(); }
[[nodiscard]] int32_t Rectangle::GetY() const { return drawn_.GetY(); }
void Rectangle::SetPos(sdl::Point p) { drawn_.SetPos(p); }
void Rectangle::SetPos(int32_t x, int32_t y) { SetPos({x, y}); }
void Rectangle::SetX(int x) { drawn_.SetX(x); }
void Rectangle::SetY(int y) { drawn_.SetY(y); }
void Rectangle::MoveX(int x) { drawn_.MoveX(x); }
void Rectangle::MoveY(int y) { drawn_.MoveY(y); }

} // namespace nge