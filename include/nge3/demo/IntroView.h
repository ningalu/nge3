#ifndef NGE3_DEMO_INTROVIEW_H
#define NGE3_DEMO_INTROVIEW_H

#include "nge/View.h"

namespace demo {
class IntroView : public nge::View {
public:
  IntroView(const std::shared_ptr<nge::Graphics> &graphics);
};
} // namespace demo

#endif