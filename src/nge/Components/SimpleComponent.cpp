#include "nge/Components/SimpleComponent.h"

#include <iostream>

#include "nge/Graphics.h"
#include "ngsdl/Texture.h"

namespace nge {
SimpleComponent::SimpleComponent(const std::shared_ptr<Graphics> &graphics)
    : graphics_(graphics) {
  angle_ = 0.0;
  dst_ = {0, 0, 0, 0};
  src_ = {0, 0, 0, 0};
}

void SimpleComponent::Rotate(double angle) { angle_ += angle; }
double SimpleComponent::GetAngle() { return angle_; }
void SimpleComponent::SetAngle(double angle) { angle_ = angle; }

[[nodiscard]] sdl::Point SimpleComponent::GetPos() { return dst_.GetPos(); }
[[nodiscard]] int32_t SimpleComponent::GetX() const { return dst_.GetX(); }
[[nodiscard]] int32_t SimpleComponent::GetY() const { return dst_.GetY(); }
void SimpleComponent::SetPos(sdl::Point p) { dst_.SetPos(p); }
void SimpleComponent::SetPos(int32_t x, int32_t y) { SetPos({x, y}); }
void SimpleComponent::SetX(int x) { dst_.SetX(x); }
void SimpleComponent::SetY(int y) { dst_.SetY(y); }
void SimpleComponent::MoveX(int x) { dst_.MoveX(x); }
void SimpleComponent::MoveY(int y) { dst_.MoveY(y); }
void SimpleComponent::Draw() {
  graphics_->Draw(*texture_, std::nullopt, dst_, angle_, std::nullopt);
}
[[nodiscard]] bool SimpleComponent::Overlaps(int32_t x, int32_t y) const {
  return dst_.Encloses(sdl::Point{x, y});
}
[[nodiscard]] uint32_t SimpleComponent::GetDrawPriority() const {
  return draw_priority_;
}

void SimpleComponent::SetZ(int32_t z) noexcept { draw_priority_ = z; }
[[nodiscard]] int32_t SimpleComponent::GetZ() const noexcept {
  return draw_priority_;
}
void SimpleComponent::SetDrawPriority(int32_t p) noexcept {
  draw_priority_ = p;
}

std::tuple<int32_t, int32_t> SimpleComponent::GetSize() const noexcept {
  return std::tuple<int32_t, int32_t>{GetW(), GetH()};
}
int32_t SimpleComponent::GetW() const noexcept { return dst_.GetW(); }
int32_t SimpleComponent::GetH() const noexcept { return dst_.GetH(); }

SimpleComponent::~SimpleComponent() {}
} // namespace nge