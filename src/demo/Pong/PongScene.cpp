#include "demo/Pong/PongScene.h"

#include <cstdlib>

#include "fmt/format.h"

namespace demo {
void PongScene::Setup() {
  viewport_ = {0, 0, 800, 600};

  ball_ = std::make_shared<Ball>(graphics_, 400, 300);
  RegisterDrawable(ball_);

  left_paddle_ = std::make_shared<Paddle>(graphics_, PaddleSide::LEFT);
  RegisterDrawable(left_paddle_);

  right_paddle_ = std::make_shared<Paddle>(graphics_, PaddleSide::RIGHT);
  RegisterDrawable(right_paddle_);
  // RegisterKeyable(left_paddle_);
}
void PongScene::Render() {

  // physics are calculated discretely per drawn frame, so this kinda has to be
  // manual
  // this kinda sucks
  if (input_->KeyDown(nge::sdl::Scancode::Q)) {
    left_paddle_->Move(nge::sdl::Scancode::Q);
  }
  if (input_->KeyDown(nge::sdl::Scancode::A)) {
    left_paddle_->Move(nge::sdl::Scancode::A);
  }

  if (input_->KeyDown(nge::sdl::Scancode::O)) {
    right_paddle_->Move(nge::sdl::Scancode::O);
  }
  if (input_->KeyDown(nge::sdl::Scancode::L)) {
    right_paddle_->Move(nge::sdl::Scancode::L);
  }

  if ((ball_->Left() < left_paddle_->Right())
    && (ball_->Right() > left_paddle_->Left())
    && (ball_->Top() < left_paddle_->Bottom())
    && (ball_->Bottom() > left_paddle_->Top())) {

    if ((ball_->Bottom() > left_paddle_->Top()) && (ball_->Top() < left_paddle_->Top())) {
      ball_->SetY(left_paddle_->Top() - ball_->H());
      ball_->yv = -std::abs(ball_->yv);
    }

    if ((ball_->Bottom() > left_paddle_->Bottom()) && (ball_->Top() < left_paddle_->Bottom())) {
      ball_->SetY(left_paddle_->Bottom());
      ball_->yv = std::abs(ball_->yv);
    }
  }

  if ((ball_->Left() < right_paddle_->Right())
    && (ball_->Right() > right_paddle_->Left())
    && (ball_->Top() < right_paddle_->Bottom())
    && (ball_->Bottom() > right_paddle_->Top())) {

    if ((ball_->Bottom() > right_paddle_->Top()) && (ball_->Top() < right_paddle_->Top())) {
      ball_->SetY(right_paddle_->Top() - ball_->H());
      ball_->yv = -std::abs(ball_->yv);
    }

    if ((ball_->Bottom() > right_paddle_->Bottom()) && (ball_->Top() < right_paddle_->Bottom())) {
      ball_->SetY(right_paddle_->Bottom());
      ball_->yv = std::abs(ball_->yv);
    }
  }

  auto newx =
    ball_->X() + static_cast<int32_t>(ball_->xv * draw_timer_.GetElapsedTime());
  auto newy =
    ball_->Y() + static_cast<int32_t>(ball_->yv * draw_timer_.GetElapsedTime());
  auto newright = newx + ball_->W();
  auto newbottom = newy + ball_->H();

  if (newx < 0) {
    newx = 0;
    ball_->xv = std::abs(ball_->xv);
  }
  if (newright > 800) {
    newx = 800 - ball_->W();
    ball_->xv = -std::abs(ball_->xv);
  }

  if (newy < 0) {
    newy = 0;
    ball_->yv = std::abs(ball_->yv);
  }
  if (newbottom > 600) {
    newy = 600 - ball_->H();
    ball_->yv = -std::abs(ball_->yv);
  }

  if ((newx < left_paddle_->Right())
    && (newright > left_paddle_->Left())
    && (newy < left_paddle_->Bottom())
    && (newbottom > left_paddle_->Top())) {

    if (ball_->Right() <= left_paddle_->Left()) {
      std::cout << "paddle left/ball right collision\n";
      newx = left_paddle_->Left() - ball_->W();
      ball_->xv = -std::abs(ball_->xv);
    }

    if (ball_->Left() >= left_paddle_->Right()) {
      std::cout << "paddle right/ball left collision\n";
      newx = left_paddle_->Right();
      ball_->xv = std::abs(ball_->xv);
    }

    if (ball_->Bottom() <= left_paddle_->Top()) {
      std::cout << "paddle top/ball bottom collision\n";
      newy = left_paddle_->Top() - ball_->H();
      ball_->yv = -std::abs(ball_->yv);
    }
    if (ball_->Top() >= left_paddle_->Bottom()) {
      std::cout << "paddle bottom/ball top collision\n";
      newy = left_paddle_->Bottom();
      ball_->yv = std::abs(ball_->yv);
    }
    std::cout << "collision\n";
  }

  if ((newx < right_paddle_->Right())
    && (newright > right_paddle_->Left())
    && (newy < right_paddle_->Bottom())
    && (newbottom > right_paddle_->Top())) {

    if (ball_->Right() <= right_paddle_->Left()) {
      std::cout << "paddle left/ball right collision\n";
      newx = right_paddle_->Left() - ball_->W();
      ball_->xv = -std::abs(ball_->xv);
    }

    if (ball_->Left() >= right_paddle_->Right()) {
      std::cout << "paddle right/ball left collision\n";
      newx = right_paddle_->Right();
      ball_->xv = std::abs(ball_->xv);
    }

    if (ball_->Bottom() <= right_paddle_->Top()) {
      std::cout << "paddle top/ball bottom collision\n";
      newy = right_paddle_->Top() - ball_->H();
      ball_->yv = -std::abs(ball_->yv);
    }
    if (ball_->Top() >= right_paddle_->Bottom()) {
      std::cout << "paddle bottom/ball top collision\n";
      newy = right_paddle_->Bottom();
      ball_->yv = std::abs(ball_->yv);
    }
    std::cout << "collision\n";
  }

  ball_->SetX(newx);
  ball_->SetY(newy);

  draw_timer_.Restart();
}
void PongScene::Tick() {
  if (input_->KeyPressed(nge::sdl::Scancode::ESCAPE)) {
    scene_manager_->PopScene();
  }
}
} // namespace demo