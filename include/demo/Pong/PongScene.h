#ifndef DEMO_PONG_PONGSCENE_H
#define DEMO_PONG_PONGSCENE_H

#include <memory>

#include "demo/Pong/Ball.h"
#include "demo/Pong/Paddle.h"
#include "nge/Scene.h"

namespace demo {
class PongScene : public nge::Scene {
public:
  PongScene() = default;

  virtual void Setup();
  virtual void Render() override;
  virtual void Tick() override;

  ~PongScene() = default;

protected:
  std::shared_ptr<Ball> ball_;
  std::shared_ptr<Paddle> left_paddle_, right_paddle_;
};

} // namespace demo

#endif