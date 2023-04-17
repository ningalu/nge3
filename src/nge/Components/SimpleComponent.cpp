#include "nge/Components/SimpleComponent.h"

#include "nge/Graphics.h"
#include "ngsdl/Texture.h"

namespace nge {
SimpleComponent::SimpleComponent(const std::shared_ptr<Graphics> &graphics)
    : graphics_(graphics) {}

void SimpleComponent::Rotate(double angle) { angle_ += angle; }
double SimpleComponent::GetAngle() { return angle_; }
void SimpleComponent::SetAngle(double angle) { angle_ = angle; }

sdl::Point SimpleComponent::GetPos() { return dst_.GetPos(); }
void SimpleComponent::SetPos(sdl::Point p) { dst_.SetPos(p); }
void SimpleComponent::SetX(int x) { dst_.SetX(x); }
void SimpleComponent::SetY(int y) { dst_.SetY(y); }
void SimpleComponent::MoveX(int x) { dst_.MoveX(x); }
void SimpleComponent::MoveY(int y) { dst_.MoveY(y); }
void SimpleComponent::Draw() {
  graphics_->Draw(*texture_, std::nullopt, dst_, angle_, std::nullopt);
}
} // namespace nge