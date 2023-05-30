#include "nge/Components/Shapes/Rectangle.h"

#include "ngsdl/Point.h"

namespace nge::shape {
Rectangle::Rectangle(std::shared_ptr<Graphics> graphics, sdl::Rectangle rect)
    : graphics_(graphics), base_(rect), drawn_(rect), colour_(0, 0, 0, 255) {}
Rectangle::Rectangle(
  std::shared_ptr<Graphics> graphics, sdl::Rectangle rect, sdl::Colour colour
)
    : graphics_(graphics), base_(rect), drawn_(rect), colour_(colour) {}

void Rectangle::Draw() { graphics_->Draw(drawn_, colour_); }

void Rectangle::SetScale(double n) {
  drawn_ = sdl::Rectangle{
    base_.X(),
    base_.Y(),
    static_cast<int32_t>(base_.W() * n),
    static_cast<int32_t>(base_.H() * n)};
}
[[nodiscard]] bool Rectangle::Overlaps(int32_t x, int32_t y) const {
  return drawn_.Encloses(sdl::Point{x, y});
}

[[nodiscard]] sdl::Point Rectangle::GetPos() { return drawn_.GetPos(); }
[[nodiscard]] int32_t Rectangle::GetX() const { return drawn_.X(); }
[[nodiscard]] int32_t Rectangle::GetY() const { return drawn_.Y(); }
void Rectangle::SetPos(sdl::Point p) { drawn_.SetPos(p); }
void Rectangle::SetPos(int32_t x, int32_t y) { SetPos({x, y}); }
void Rectangle::SetX(int32_t x) { drawn_.SetX(x); }
void Rectangle::SetY(int32_t y) { drawn_.SetY(y); }
void Rectangle::MoveX(int32_t x) { drawn_.MoveX(x); }
void Rectangle::MoveY(int32_t y) { drawn_.MoveY(y); }

std::tuple<int32_t, int32_t> Rectangle::GetSize() const noexcept {
  return std::tuple<int32_t, int32_t>{GetW(), GetH()};
}
int32_t Rectangle::GetW() const noexcept { return drawn_.W(); }
int32_t Rectangle::GetH() const noexcept { return drawn_.H(); }

int32_t Rectangle::Top() const { return drawn_.Y(); }
int32_t Rectangle::Bottom() const { return drawn_.Y() + drawn_.H(); }
int32_t Rectangle::Left() const { return drawn_.X(); }
int32_t Rectangle::Right() const { return drawn_.X() + drawn_.W(); }

} // namespace nge