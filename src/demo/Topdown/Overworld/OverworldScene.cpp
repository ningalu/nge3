#include "demo/Topdown/Overworld/OverworldScene.h"

#include <memory>

#include "nge/Components/Animation/FrameAnimationController.h"
#include "nge/Components/AtlasAnimation.h"
#include "nge/Components/Sprite.h"

#include "ngsdl/RendererFlip.h"

static std::shared_ptr<nge::AtlasAnimation> player_idle, player_run;
static std::shared_ptr<nge::FrameAnimationController> run_controller;
namespace demo {

void OverworldScene::Setup() {
  viewport_ = nge::sdl::Rectangle{0, 0, 1600, 900};

  auto idle_controller = std::make_shared<nge::FrameAnimationController>(10, 4);
  player_idle = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_idle.png", idle_controller
  );
  player_idle->SetScale(4.0);
  player_idle->SetPos(800, 450);

  run_controller = std::make_shared<nge::FrameAnimationController>(10, 6);
  player_run = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_run.png", run_controller
  );
  player_run->SetScale(4.0);
  player_run->SetPos(800, 450);

  auto run_atlas =
    std::make_shared<nge::Sprite>(graphics_, "resources/Game/player_run.png");
  RegisterDrawable(run_atlas);
}
void OverworldScene::Render() {

  bool up = input_->KeyDown(nge::sdl::Scancode::W);
  bool down = input_->KeyDown(nge::sdl::Scancode::S);
  bool left = input_->KeyDown(nge::sdl::Scancode::A);
  bool right = input_->KeyDown(nge::sdl::Scancode::D);

  [&]() {
    if (left) {
      player_run->SetFlip(nge::sdl::RendererFlip::HORIZONTAL);
      player_idle->SetFlip(nge::sdl::RendererFlip::HORIZONTAL);
      player_run->Draw();
      return;
    }
    if (right) {
      player_run->SetFlip(nge::sdl::RendererFlip::NONE);
      player_idle->SetFlip(nge::sdl::RendererFlip::NONE);
      player_run->Draw();
      return;
    }
    if (up || down) {
      player_run->Draw();
      return;
    }
    run_controller->Restart();
    player_idle->Draw();
  }();
}
void OverworldScene::Tick() {}

} // namespace demo