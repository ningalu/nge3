#include "nge/Components/AtlasAnimation.h"

#include <iostream>

#include "nge/Components/Animation/AnimationController.h"

namespace nge {
AtlasAnimation::AtlasAnimation(
  const std::shared_ptr<Graphics> &graphics,
  const std::string &filename,
  std::shared_ptr<AnimationController> control,
  sdl::Rect frame_size
)
    : SimpleComponent(graphics), control_(control) {
  texture_ = std::make_shared<sdl::Texture>(graphics_->GetRenderer(), filename);
  src_ = {0, 0, frame_size.GetW(), frame_size.GetH()};
  dst_ = src_;

  frame_dim_ = src_;
}

AtlasAnimation::AtlasAnimation(
  const std::shared_ptr<Graphics> &graphics,
  const std::string &filename,
  std::shared_ptr<AnimationController> control,
  uint32_t frame_count
)
    : SimpleComponent(graphics), control_(control) {
  texture_ = std::make_shared<sdl::Texture>(graphics_->GetRenderer(), filename);
  src_ = {
    0,
    0,
    texture_->GetW() / static_cast<int32_t>(frame_count),
    texture_->GetH()};
  dst_ = src_;

  frame_dim_ = src_;
}

void AtlasAnimation::Draw() {
  src_.SetX(control_->Frame() * frame_dim_.GetW());
  std::cout << *control_ << "\n\n";
  graphics_->Draw(*texture_, src_, dst_, angle_, std::nullopt);
  control_->Tick();
}
} // namespace nge