#include "nge/Components/AtlasAnimation.h"

#include <iostream>

#include "nge/Components/Animation/AnimationController.h"

namespace nge {

AtlasAnimation::AtlasAnimation(
  const std::shared_ptr<Graphics> &graphics,
  const std::string &filename,
  std::shared_ptr<AnimationController> control
)
    : BasicGraphicsUser(graphics), control_(control) {
  texture_ = std::make_shared<sdl::Texture>(graphics_->GetRenderer(), filename);
  src_ = {
    0,
    0,
    texture_->GetW() / static_cast<int32_t>(control_->UniqueFrames()),
    texture_->GetH()};
  dst_ = src_;

  frame_dim_ = src_;
}

AtlasAnimation::AtlasAnimation(
  const std::shared_ptr<Graphics> &graphics,
  const std::string &filename,
  uint32_t atlas_frame_count,
  std::shared_ptr<AnimationController> control
)
    : BasicGraphicsUser(graphics), control_(control) {
  texture_ = std::make_shared<sdl::Texture>(graphics_->GetRenderer(), filename);
  src_ = {
    0,
    0,
    texture_->GetW() / static_cast<int32_t>(atlas_frame_count),
    texture_->GetH()};
  dst_ = src_;

  frame_dim_ = src_;
}

void AtlasAnimation::Draw() {
  src_.SetX(control_->Frame() * frame_dim_.W());
  graphics_->Draw(*texture_, src_, dst_, angle_, std::nullopt, flip_);
  control_->Tick();
}
} // namespace nge