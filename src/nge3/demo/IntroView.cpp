#include "IntroView.h"

namespace demo {
IntroView::IntroView(const std::shared_ptr<nge::Graphics> &graphics)
    : nge::View(graphics) {
  viewport_ = {50, 50, 600, 600};
}
} // namespace demo