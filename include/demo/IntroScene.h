#ifndef NGE3_DEMO_INTROVIEW_H
#define NGE3_DEMO_INTROVIEW_H

#include <memory>
#include <tuple>

#include "nge/Components/Sprite.h"
#include "nge/Components/Text.h"
#include "nge/Scene.h"
#include "ngsdl/Font.h"

namespace demo {
class IntroScene : public nge::Scene {
public:
  IntroScene() = default;

  virtual void Setup();
  virtual void Render() override;
  virtual void Tick() override;

  ~IntroScene();

protected:
  nge::Sprite among_us_;
  std::shared_ptr<nge::Sprite> s_;
  std::tuple<double, double> among_us_pos_;
  std::shared_ptr<nge::Text> nge3_demo_app_text_, pong_text_;
  // nge::Text a, b;
  std::unique_ptr<nge::Text> c, d;
  std::shared_ptr<nge::sdl::Font> h1_, h2_;
};
} // namespace demo

#endif