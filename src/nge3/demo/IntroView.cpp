#include "nge3/demo/IntroView.h"

namespace demo {
IntroView::IntroView(const std::shared_ptr<nge::Graphics> &graphics)
    : nge::View(graphics) {
  viewport_ = {50, 50, 600, 600};
  among_us_ = {graphics_, "resources/parrot.jpg"};
  among_us_.SetScale(1.0);
  among_us_.SetPos({50, 50});
}
void IntroView::Render() { among_us_.Draw(); }
void IntroView::Tick() {}
} // namespace demo