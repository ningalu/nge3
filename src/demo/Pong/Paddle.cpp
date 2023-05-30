#include "demo/Pong/Paddle.h"
namespace demo {
Paddle::Paddle(std::shared_ptr<nge::Graphics> graphics, PaddleSide side)
    : Rectangle(
      graphics,
      nge::sdl::Rectangle{side == PaddleSide::LEFT ? 100 : 675, 75, 25, 150},
      nge::sdl::Color{0, 0, 0, 255}
    ),
      up_code_(
        side == PaddleSide::LEFT ? nge::sdl::Scancode::Q : nge::sdl::Scancode::O
      ),
      down_code_(
        side == PaddleSide::LEFT ? nge::sdl::Scancode::A : nge::sdl::Scancode::L
      ) {}

void Paddle::PressKey(nge::sdl::Scancode s) { Move(s); }
void Paddle::HoldKey(nge::sdl::Scancode s) { Move(s); }
void Paddle::ReleaseKey(nge::sdl::Scancode) {}

void Paddle::Move(nge::sdl::Scancode s) {
  if (s == up_code_) {
    if (Rectangle::drawn_.GetY() > 0) {
      Rectangle::drawn_.MoveY(-12);
    }
  } else {
    if (s == down_code_) {
      if ((Rectangle::drawn_.GetY() + Rectangle::drawn_.GetH()) < 600) {
        Rectangle::drawn_.MoveY(12);
      }
    }
  }
}
} // namespace demo