#ifndef DEMO_INTROSCENE_H
#define DEMO_INTROSCENE_H

#include <memory>
#include <tuple>

#include "ngsdl/Font.h"

#include "nge/Components/AtlasAnimation.h"
#include "nge/Components/Button.h"
#include "nge/Components/Composite.hpp"
#include "nge/Components/Mouse/BasicMouseUser.h"
#include "nge/Components/Sprite.h"
#include "nge/Components/Text.h"
#include "nge/Scene.h"

namespace demo {
class IntroScene : public nge::Scene {
public:
  IntroScene() = default;

  virtual void Setup();
  virtual void Render() override;
  virtual void Tick() override;

  ~IntroScene();

protected:
  std::shared_ptr<nge::Text> nge3_demo_app_text_;

  std::shared_ptr<nge::Button> pong_button_;
  std::shared_ptr<nge::Button> graph_button_;

  std::shared_ptr<nge::sdl::Font> h1_, h2_;
  std::shared_ptr<nge::AtlasAnimation> text_select_;
};
} // namespace demo

#endif