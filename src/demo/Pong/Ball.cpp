#include "demo/Pong/Ball.h"

#include <iostream>
#include <random>

#include "nge/Graphics.h"

#include "ngsdl/Rectangle.h"

namespace demo {

Ball::Ball(std::shared_ptr<nge::Graphics> graphics, int32_t x, int32_t y)
    : Rectangle(graphics, nge::sdl::Rectangle{x, y, 25, 25}) {
  SetX(x);
  SetY(y);

  // stl moment
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<double> dist{250, 300};
  std::uniform_real_distribution<double> coin{-1, 1};

  xv = static_cast<int32_t>(dist(mt)) * (coin(mt) > 0 ? 1 : -1);
  yv = static_cast<int32_t>(dist(mt)) * (coin(mt) > 0 ? 1 : -1);
  std::cout << xv << " " << yv << "\n";
}

} // namespace demo