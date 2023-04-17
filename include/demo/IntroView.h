#ifndef NGE3_DEMO_INTROVIEW_H
#define NGE3_DEMO_INTROVIEW_H

#include <tuple>

#include "nge/Components/Sprite.h"
#include "nge/Components/Text.h"
#include "nge/View.h"
#include "ngsdl/Font.h"

namespace demo {
class IntroView : public nge::View {
public:
  IntroView(
    const std::shared_ptr<nge::Graphics> &graphics,
    const std::shared_ptr<nge::Input> &input
  );

  virtual void Render() override;
  virtual void Tick() override;

protected:
  nge::Sprite among_us_;
  std::tuple<double, double> among_us_pos_;
  nge::Text among_us_text_;
  std::shared_ptr<nge::sdl::Font> f_;
};
} // namespace demo

#endif