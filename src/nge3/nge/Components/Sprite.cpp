#include "nge/Components/Sprite.h"

#include "nge/Graphics.h"
namespace nge {
Sprite::Sprite(
  const std::shared_ptr<Graphics> &graphics, const std::string &filename
)
    : graphics_(graphics) {
  texture_ = std::make_shared<sdl::Texture>(graphics_->GetRenderer(), filename);
  src_ = {{0, 0}, texture_->GetSize()};
}

void Sprite::SetScale(double scale) {
  dst_.SetW(static_cast<int>(static_cast<double>(src_.GetW()) * scale));
  dst_.SetH(static_cast<int>(static_cast<double>(src_.GetH()) * scale));
}

void Sprite::Rotate(double angle) { angle_ += angle; }
double Sprite::GetAngle() { return angle_; }
void Sprite::SetAngle(double angle) { angle_ = angle; }

sdl::Point Sprite::GetPos() { return dst_.GetPos(); }
void Sprite::SetPos(sdl::Point p) { dst_.SetPos(p); }
void Sprite::SetX(int x) { dst_.SetX(x); }
void Sprite::SetY(int y) { dst_.SetY(y); }
void Sprite::MoveX(int x) { dst_.MoveX(x); }
void Sprite::MoveY(int y) { dst_.MoveY(y); }
void Sprite::Draw() {
  graphics_->Draw(*texture_, std::nullopt, dst_, angle_, std::nullopt);
}
} // namespace nge