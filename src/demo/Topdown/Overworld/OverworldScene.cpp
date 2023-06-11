#include "demo/Topdown/Overworld/OverworldScene.h"

#include <memory>

#include "nge/Components/Animation/FrameAnimationController.h"
#include "nge/Components/AtlasAnimation.h"
#include "nge/Components/Sprite.h"

#include "ngsdl/RendererFlip.h"

static std::shared_ptr<nge::AtlasAnimation> player_idle, player_run,
  player_attack;
static std::shared_ptr<nge::FrameAnimationController> run_controller;
static int anim_lockout = 0;

std::shared_ptr<nge::AtlasAnimation> dummy_anim = nullptr;
static std::shared_ptr<nge::AtlasAnimation> &current_anim{dummy_anim};
namespace demo {

void OverworldScene::Setup() {
  viewport_ = nge::sdl::Rectangle{0, 0, 1600, 900};

  auto idle_controller = std::make_shared<nge::FrameAnimationController>(10, 4);
  player_idle = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_idle.png", idle_controller
  );
  player_idle->SetScale(4.0);
  player_idle->SetPos(800, 450);

  current_anim = player_idle;

  run_controller = std::make_shared<nge::FrameAnimationController>(10, 6);
  player_run = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_run.png", run_controller
  );
  player_run->SetScale(4.0);
  player_run->SetPos(800, 450);

  auto attack_controller =
    std::make_shared<nge::FrameAnimationController>(5, 5);
  player_attack = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_attack_1.png", attack_controller
  );
  player_attack->SetScale(4.0);
  player_attack->SetPos(800, 450);

  auto run_atlas =
    std::make_shared<nge::Sprite>(graphics_, "resources/Game/player_run.png");
  RegisterDrawable(run_atlas);

  auto attack_atlas = std::make_shared<nge::Sprite>(
    graphics_, "resources/Game/player_attack_1.png"
  );
  attack_atlas->SetY(run_atlas->GetY() + run_atlas->GetH());
  RegisterDrawable(attack_atlas);
}
void OverworldScene::Render() {

  bool up = input_->KeyDown(nge::sdl::Scancode::W);
  bool down = input_->KeyDown(nge::sdl::Scancode::S);
  bool left = input_->KeyDown(nge::sdl::Scancode::A);
  bool right = input_->KeyDown(nge::sdl::Scancode::D);
  [[maybe_unused]] bool attack_up = input_->KeyDown(nge::sdl::Scancode::I);
  [[maybe_unused]] bool attack_down = input_->KeyDown(nge::sdl::Scancode::K);
  [[maybe_unused]] bool attack_left = input_->KeyDown(nge::sdl::Scancode::J);
  [[maybe_unused]] bool attack_right = input_->KeyDown(nge::sdl::Scancode::L);

  [&]() {
    anim_lockout--;
    if (anim_lockout > 0) {
      return;
    }
    if (attack_right) {
      current_anim = player_attack;
      anim_lockout = 25;
      return;
    }

    if (left) {
      player_run->SetFlip(nge::sdl::RendererFlip::HORIZONTAL);
      player_idle->SetFlip(nge::sdl::RendererFlip::HORIZONTAL);
      current_anim = player_run;
      return;
    }
    if (right) {
      player_run->SetFlip(nge::sdl::RendererFlip::NONE);
      player_idle->SetFlip(nge::sdl::RendererFlip::NONE);
      current_anim = player_run;
      return;
    }
    if (up || down) {
      current_anim = player_run;
      return;
    }
    run_controller->Restart();
    current_anim = player_idle;
  }();

  current_anim->Draw();
}
void OverworldScene::Tick() {}

} // namespace demo