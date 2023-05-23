#include "demo/Pong/PongScene.h"

namespace demo {
void PongScene::Setup() { viewport_ = {0, 0, 800, 600}; }
void PongScene::Render() {}
void PongScene::Tick() {
  if (input_->KeyPressed(nge::sdl::Scancode::ESCAPE)) {
    scene_manager_->PopScene();
  }
}
} // namespace demo