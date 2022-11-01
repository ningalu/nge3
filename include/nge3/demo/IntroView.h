#ifndef NGE3_DEMO_INTROVIEW_H
#define NGE3_DEMO_INTROVIEW_H

#include "nge3/nge/Components/Sprite.h"
#include "nge3/nge/View.h"

namespace demo {
class IntroView : public nge::View {
public:
  IntroView(const std::shared_ptr<nge::Graphics> &graphics);

  virtual void Render() override;
  virtual void Tick() override;

protected:
  nge::Sprite among_us_;
};
} // namespace demo

#endif