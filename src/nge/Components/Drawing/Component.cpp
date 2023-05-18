#include "nge/Components/Drawing/Component.h"

#include <iostream>

#include "nge/Graphics.h"
#include "ngsdl/Texture.h"

namespace nge {
Component::Component(const std::shared_ptr<Graphics> &graphics)
    : graphics_(graphics) {
  angle_ = 0.0;
  dst_ = {0, 0, 0, 0};
  src_ = {0, 0, 0, 0};
}

void Component::Rotate(double angle) { angle_ += angle; }
double Component::GetAngle() { return angle_; }
void Component::SetAngle(double angle) { angle_ = angle; }

[[nodiscard]] sdl::Point Component::GetPos() { return dst_.GetPos(); }
[[nodiscard]] int32_t Component::GetX() const { return dst_.GetX(); }
[[nodiscard]] int32_t Component::GetY() const { return dst_.GetY(); }
void Component::SetPos(sdl::Point p) { dst_.SetPos(p); }
void Component::SetPos(int32_t x, int32_t y) { SetPos({x, y}); }
void Component::SetX(int x) { dst_.SetX(x); }
void Component::SetY(int y) { dst_.SetY(y); }
void Component::MoveX(int x) { dst_.MoveX(x); }
void Component::MoveY(int y) { dst_.MoveY(y); }

void Component::Draw() {
  graphics_->Draw(*texture_, std::nullopt, dst_, angle_, std::nullopt);
}
[[nodiscard]] bool Component::Overlaps(int32_t x, int32_t y) const {
  return dst_.Encloses(sdl::Point{x, y});
}
[[nodiscard]] uint32_t Component::GetDrawPriority() const {
  return draw_priority_;
}

void Component::SetZ(int32_t z) noexcept { draw_priority_ = z; }
[[nodiscard]] int32_t Component::GetZ() const noexcept {
  return draw_priority_;
}
void Component::SetDrawPriority(int32_t p) noexcept { draw_priority_ = p; }
void Component::SetScale(double scale) {
  dst_.SetW(static_cast<int>(static_cast<double>(src_.GetW()) * scale));
  dst_.SetH(static_cast<int>(static_cast<double>(src_.GetH()) * scale));
}

std::tuple<int32_t, int32_t> Component::GetSize() const noexcept {
  return std::tuple<int32_t, int32_t>{GetW(), GetH()};
}
int32_t Component::GetW() const noexcept { return dst_.GetW(); }
int32_t Component::GetH() const noexcept { return dst_.GetH(); }

Component::~Component() {}
} // namespace nge