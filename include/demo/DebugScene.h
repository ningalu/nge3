#ifndef DEMO_DEBUGSCENE_H
#define DEMO_DEBUGSCENE_H

#include <memory>

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
  nge::Timer frame_timer_;
  std::shared_ptr<nge::Sprite> s_;
  std::shared_ptr<nge::sdl::Font> h1_, h2_, p_;
  std::shared_ptr<nge::Text> blended_, shaded_, solid_;
  std::shared_ptr<nge::Text> mouse_x_label_, mouse_y_label_;
  std::shared_ptr<nge::Text> mouse_x_, mouse_y_;
  std::shared_ptr<nge::Text> frame_interval_label_, frame_interval_;
};
} // namespace demo

#endif