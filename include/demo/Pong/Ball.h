#ifndef DEMO_PONG_BALL_H
#define DEMO_PONG_BALL_H

#include <cstdint>
#include <memory>

#include "nge/Components/Shapes/Rectangle.h"
#include "nge/Timer.h"

namespace nge {
class Graphics;
}

namespace demo {
class Ball : public nge::shape::Rectangle {
public:
  Ball() = delete;
  Ball(std::shared_ptr<nge::Graphics> graphics, int32_t x, int32_t y);

  int32_t xv, yv;

protected:
  nge::Timer move_timer_;
};
} // namespace demo

#endif