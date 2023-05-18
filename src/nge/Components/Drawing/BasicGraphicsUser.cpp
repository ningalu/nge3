#include "nge/Components/Drawing/BasicGraphicsUser.h"

#include <iostream>

#include "nge/Graphics.h"
#include "ngsdl/Texture.h"

namespace nge {
BasicGraphicsUser::BasicGraphicsUser(const std::shared_ptr<Graphics> &graphics)
    : graphics_(graphics) {
  angle_ = 0.0;
  dst_ = {0, 0, 0, 0};
  src_ = {0, 0, 0, 0};
}

void BasicGraphicsUser::Rotate(double angle) { angle_ += angle; }
double BasicGraphicsUser::GetAngle() { return angle_; }
void BasicGraphicsUser::SetAngle(double angle) { angle_ = angle; }

[[nodiscard]] sdl::Point BasicGraphicsUser::GetPos() { return dst_.GetPos(); }
[[nodiscard]] int32_t BasicGraphicsUser::GetX() const { return dst_.GetX(); }
[[nodiscard]] int32_t BasicGraphicsUser::GetY() const { return dst_.GetY(); }
void BasicGraphicsUser::SetPos(sdl::Point p) { dst_.SetPos(p); }
void BasicGraphicsUser::SetPos(int32_t x, int32_t y) { SetPos({x, y}); }
void BasicGraphicsUser::SetX(int x) { dst_.SetX(x); }
void BasicGraphicsUser::SetY(int y) { dst_.SetY(y); }
void BasicGraphicsUser::MoveX(int x) { dst_.MoveX(x); }
void BasicGraphicsUser::MoveY(int y) { dst_.MoveY(y); }

void BasicGraphicsUser::Draw() {
  graphics_->Draw(*texture_, std::nullopt, dst_, angle_, std::nullopt);
}
[[nodiscard]] bool BasicGraphicsUser::Overlaps(int32_t x, int32_t y) const {
  return dst_.Encloses(sdl::Point{x, y});
}
[[nodiscard]] uint32_t BasicGraphicsUser::GetDrawPriority() const {
  return draw_priority_;
}

void BasicGraphicsUser::SetZ(int32_t z) noexcept { draw_priority_ = z; }
[[nodiscard]] int32_t BasicGraphicsUser::GetZ() const noexcept {
  return draw_priority_;
}
void BasicGraphicsUser::SetDrawPriority(int32_t p) noexcept {
  draw_priority_ = p;
}
void BasicGraphicsUser::SetScale(double scale) {
  dst_.SetW(static_cast<int>(static_cast<double>(src_.GetW()) * scale));
  dst_.SetH(static_cast<int>(static_cast<double>(src_.GetH()) * scale));
}

std::tuple<int32_t, int32_t> BasicGraphicsUser::GetSize() const noexcept {
  return std::tuple<int32_t, int32_t>{GetW(), GetH()};
}
int32_t BasicGraphicsUser::GetW() const noexcept { return dst_.GetW(); }
int32_t BasicGraphicsUser::GetH() const noexcept { return dst_.GetH(); }

BasicGraphicsUser::~BasicGraphicsUser() {}
} // namespace nge