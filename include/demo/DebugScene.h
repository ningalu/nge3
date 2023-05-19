#ifndef DEMO_DEBUGSCENE_H
#define DEMO_DEBUGSCENE_H

#include <memory>

#include "nge/Components/Animation/TimedAnimationController.h"
#include "nge/Components/AtlasAnimation.h"
#include "nge/Components/BlendedText.h"
#include "nge/Components/ShadedText.h"
#include "nge/Components/SolidText.h"
#include "nge/Components/Sprite.h"
#include "nge/Components/Text.h"
#include "nge/Scene.h"
#include "nge/Timer.h"

#include "ngsdl/Font.h"

namespace demo {
class DebugScene : public nge::Scene {
public:
  DebugScene() = default;

  virtual void Setup();
  virtual void Render() override;
  virtual void Tick() override;

  ~DebugScene();

protected:
  std::shared_ptr<nge::sdl::Font> h1_, h2_, p_;

  std::shared_ptr<nge::Sprite> s_;

  std::shared_ptr<nge::Text> frame_anim_label_, timer_anim_label_;
  std::shared_ptr<nge::AtlasAnimation> frame_anim_, timer_anim_;

  std::shared_ptr<nge::BlendedText> blended_;
  std::shared_ptr<nge::ShadedText> shaded_;
  std::shared_ptr<nge::SolidText> solid_;

  std::shared_ptr<nge::Text> mouse_x_label_, mouse_y_label_;
  std::shared_ptr<nge::Text> mouse_x_, mouse_y_;

  nge::Timer frame_timer_;
  std::shared_ptr<nge::Text> frame_interval_label_, frame_interval_;

  nge::Timer scene_timer_;
  std::shared_ptr<nge::Text> scene_open_time_;
};
} // namespace demo

#endif