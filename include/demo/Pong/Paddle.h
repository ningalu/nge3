#ifndef DEMO_PADDLE_PADDLE_H
#define DEMO_PADDLE_PADDLE_H

#include <cstdint>
#include <memory>

#include "nge/Components/Keyboard/Keyable.h"
#include "nge/Components/Shapes/Rectangle.h"
#include "nge/Graphics.h"

namespace demo {
enum class PaddleSide : bool { LEFT, RIGHT };
class Paddle : public nge::Rectangle, public nge::Keyable {
public:
  Paddle() = delete;
  Paddle(std::shared_ptr<nge::Graphics> graphics, PaddleSide side);

  virtual void PressKey(nge::sdl::Scancode s) override;
  virtual void HoldKey(nge::sdl::Scancode s) override;
  virtual void ReleaseKey(nge::sdl::Scancode s) override;

  void Move(nge::sdl::Scancode s);

protected:
  nge::sdl::Scancode up_code_, down_code_;
};

} // namespace demo
#endif