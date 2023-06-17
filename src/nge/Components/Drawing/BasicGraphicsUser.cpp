#include "nge/Components/Drawing/BasicGraphicsUser.h"

#include <iostream>

#include "nge/Graphics.h"
#include "ngsdl/Texture.h"

namespace nge {
BasicGraphicsUser::BasicGraphicsUser(const std::shared_ptr<Graphics> &graphics)
    : graphics_(graphics), angle_(0), flip_(sdl::RendererFlip::NONE) {}

void BasicGraphicsUser::Rotate(double angle) { angle_ += angle; }
double BasicGraphicsUser::GetAngle() { return angle_; }
void BasicGraphicsUser::SetAngle(double angle) { angle_ = angle; }

[[nodiscard]] sdl::Point BasicGraphicsUser::GetPos() { return dst_.GetPos(); }
[[nodiscard]] int32_t BasicGraphicsUser::GetX() const { return dst_.X(); }
[[nodiscard]] int32_t BasicGraphicsUser::GetY() const { return dst_.Y(); }
void BasicGraphicsUser::SetPos(sdl::Point p) { dst_.SetPos(p); }
void BasicGraphicsUser::SetPos(int32_t x, int32_t y) { SetPos({x, y}); }
void BasicGraphicsUser::SetX(int x) { dst_.SetX(x); }
void BasicGraphicsUser::SetY(int y) { dst_.SetY(y); }
void BasicGraphicsUser::MoveX(int x) { dst_.MoveX(x); }
void BasicGraphicsUser::MoveY(int y) { dst_.MoveY(y); }

void BasicGraphicsUser::Draw() {
  graphics_->Draw(*texture_, std::nullopt, dst_, angle_, std::nullopt, flip_);
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
  dst_.SetW(static_cast<int>(static_cast<double>(src_.W()) * scale));
  dst_.SetH(static_cast<int>(static_cast<double>(src_.H()) * scale));
}

[[nodiscard]] std::tuple<int32_t, int32_t> BasicGraphicsUser::GetSize(
) const noexcept {
  return std::tuple<int32_t, int32_t>{GetW(), GetH()};
}
[[nodiscard]] int32_t BasicGraphicsUser::GetW() const noexcept {
  return dst_.W();
}
[[nodiscard]] int32_t BasicGraphicsUser::GetH() const noexcept {
  return dst_.H();
}

[[nodiscard]] sdl::RendererFlip BasicGraphicsUser::Flip() const noexcept {
  return flip_;
}
void BasicGraphicsUser::SetFlip(sdl::RendererFlip flip) noexcept {
  flip_ = flip;
}

BasicGraphicsUser::~BasicGraphicsUser() {}
} // namespace nge