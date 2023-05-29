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
void Rectangle::SetX(int32_t x) { drawn_.SetX(x); }
void Rectangle::SetY(int32_t y) { drawn_.SetY(y); }
void Rectangle::MoveX(int32_t x) { drawn_.MoveX(x); }
void Rectangle::MoveY(int32_t y) { drawn_.MoveY(y); }

std::tuple<int32_t, int32_t> Rectangle::GetSize() const noexcept {
  return std::tuple<int32_t, int32_t>{GetW(), GetH()};
}
int32_t Rectangle::GetW() const noexcept { return drawn_.GetW(); }
int32_t Rectangle::GetH() const noexcept { return drawn_.GetH(); }

int32_t Rectangle::Top() const { return drawn_.GetY(); }
int32_t Rectangle::Bottom() const { return drawn_.GetY() + drawn_.GetH(); }
int32_t Rectangle::Left() const { return drawn_.GetX(); }
int32_t Rectangle::Right() const { return drawn_.GetX() + drawn_.GetW(); }

} // namespace nge