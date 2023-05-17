#ifndef NGE3_DEMO_INTROVIEW_H
#define NGE3_DEMO_INTROVIEW_H

#include <memory>
#include <tuple>

#include "ngsdl/Font.h"

#include "nge/Components/AtlasAnimation.h"
#include "nge/Components/Composite.hpp"
#include "nge/Components/Mouse/Button.h"
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
  std::shared_ptr<nge::Sprite> s_;
  std::shared_ptr<nge::Text> nge3_demo_app_text_;

  std::shared_ptr<nge::Text> pong_normal_, pong_selected_;

  std::shared_ptr<nge::sdl::Font> h1_, h2_;
  std::shared_ptr<nge::AtlasAnimation> text_select_;
  std::shared_ptr<nge::Composite<nge::Text, nge::Button>> text_button_;
};
} // namespace demo

#endif