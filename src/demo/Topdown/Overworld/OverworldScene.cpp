#include "demo/Topdown/Overworld/OverworldScene.h"

#include <array>
#include <cstdlib>
#include <memory>

#include "nge/Components/Animation/FrameAnimationController.h"
#include "nge/Components/AtlasAnimation.h"
#include "nge/Components/Sprite.h"

#include "ngsdl/RendererFlip.h"
#include "ngsdl/Texture.h"

namespace demo {
enum class dir : uint8_t { u, d, l, r };
}

static std::shared_ptr<nge::AtlasAnimation> player_idle_horiz, player_run_horiz,
  player_attack_horiz;
static std::shared_ptr<nge::FrameAnimationController> run_horiz_controller,
  attack_horiz_controller;

static std::shared_ptr<nge::AtlasAnimation> player_idle_down, player_run_down,
  player_attack_down;
static std::shared_ptr<nge::FrameAnimationController> attack_down_controller,
  run_down_controller;

static std::shared_ptr<nge::AtlasAnimation> player_idle_up, player_run_up,
  player_attack_up;
static std::shared_ptr<nge::FrameAnimationController> attack_up_controller,
  run_up_controller;

static int anim_lockout = 0;

std::shared_ptr<nge::AtlasAnimation> dummy_anim = nullptr;
static std::shared_ptr<nge::AtlasAnimation> &current_anim{dummy_anim};
static std::shared_ptr<nge::sdl::Texture> tileset;

static std::array<std::array<nge::sdl::Point, 25>, 25> overworld_tiles;
static nge::sdl::Point overworld_offset{0, 0};

[[maybe_unused]] static bool attack_up;
[[maybe_unused]] static bool attack_down;
[[maybe_unused]] static bool attack_left;
[[maybe_unused]] static bool attack_right;

static demo::dir player_dir = demo::dir::l;

namespace demo {

void OverworldScene::Setup() {
  viewport_ = nge::sdl::Rectangle{0, 0, 1600, 900};

  for (auto &a : overworld_tiles) {
    for (auto &p : a) {
      p = nge::sdl::Point{32 * (std::rand() % 8), 32 * (std::rand() % 8)};
    }
  }

  tileset = std::make_shared<nge::sdl::Texture>(
    graphics_->GetRenderer(), "resources/Game/tileset_grass.png"
  );

  auto horiz_idle_controller =
    std::make_shared<nge::FrameAnimationController>(8, 6);
  player_idle_horiz = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_idle_horiz.png", horiz_idle_controller
  );
  player_idle_horiz->SetScale(4.0);
  player_idle_horiz->SetPos(800, 450);

  auto up_idle_controller =
    std::make_shared<nge::FrameAnimationController>(8, 6);
  player_idle_up = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_idle_up.png", up_idle_controller
  );
  player_idle_up->SetScale(4.0);
  player_idle_up->SetPos(800, 450);

  auto down_idle_controller =
    std::make_shared<nge::FrameAnimationController>(8, 6);
  player_idle_down = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_idle_down.png", down_idle_controller
  );
  player_idle_down->SetScale(4.0);
  player_idle_down->SetPos(800, 450);

  run_horiz_controller = std::make_shared<nge::FrameAnimationController>(6, 6);
  player_run_horiz = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_walk_horiz.png", run_horiz_controller
  );
  player_run_horiz->SetScale(4.0);
  player_run_horiz->SetPos(800, 450);

  run_up_controller = std::make_shared<nge::FrameAnimationController>(6, 6);
  player_run_up = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_walk_up.png", run_up_controller
  );
  player_run_up->SetScale(4.0);
  player_run_up->SetPos(800, 450);

  run_down_controller = std::make_shared<nge::FrameAnimationController>(6, 6);
  player_run_down = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_walk_down.png", run_down_controller
  );
  player_run_down->SetScale(4.0);
  player_run_down->SetPos(800, 450);

  attack_horiz_controller =
    std::make_shared<nge::FrameAnimationController>(5, 4);
  player_attack_horiz = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_attack_horiz.png", attack_horiz_controller
  );
  player_attack_horiz->SetScale(4.0);
  player_attack_horiz->SetPos(800, 450);

  attack_down_controller =
    std::make_shared<nge::FrameAnimationController>(5, 4);
  player_attack_down = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_attack_down.png", attack_down_controller
  );
  player_attack_down->SetScale(4.0);
  player_attack_down->SetPos(800, 450);

  attack_up_controller = std::make_shared<nge::FrameAnimationController>(5, 4);
  player_attack_up = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_attack_up.png", attack_up_controller
  );
  player_attack_up->SetScale(4.0);
  player_attack_up->SetPos(800, 450);

  auto run_atlas = std::make_shared<nge::Sprite>(
    graphics_, "resources/Game/player_run_horiz.png"
  );
  RegisterDrawable(run_atlas);

  auto attack_atlas = std::make_shared<nge::Sprite>(
    graphics_, "resources/Game/player_attack_horiz.png"
  );
  attack_atlas->SetY(run_atlas->GetY() + run_atlas->GetH());
  RegisterDrawable(attack_atlas);

  current_anim = player_idle_horiz;
}
void OverworldScene::Render() {

  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 25; j++) {
      graphics_->Draw(
        *tileset,
        nge::sdl::Rectangle{overworld_tiles[i][j], 32, 32},
        nge::sdl::Rectangle{
          (96 * i) - overworld_offset.x, (96 * j) - overworld_offset.y, 96, 96}
      );
    }
  }

  bool up = input_->KeyDown(nge::sdl::Scancode::W);
  bool down = input_->KeyDown(nge::sdl::Scancode::S);
  bool left = input_->KeyDown(nge::sdl::Scancode::A);
  bool right = input_->KeyDown(nge::sdl::Scancode::D);

  [&]() {
    anim_lockout--;
    if (anim_lockout > 0) {
      return;
    }
    if (attack_right) {
      attack_right = false;
      player_dir = dir::r;
      attack_horiz_controller->Restart();
      player_run_horiz->SetFlip(nge::sdl::RendererFlip::NONE);
      player_idle_horiz->SetFlip(nge::sdl::RendererFlip::NONE);
      player_attack_horiz->SetFlip(nge::sdl::RendererFlip::NONE);
      player_attack_down->SetFlip(nge::sdl::RendererFlip::NONE);
      current_anim = player_attack_horiz;
      anim_lockout = 20;
      return;
    }
    if (attack_left) {
      attack_left = false;
      player_dir = dir::l;
      attack_horiz_controller->Restart();
      player_run_horiz->SetFlip(nge::sdl::RendererFlip::HORIZONTAL);
      player_idle_horiz->SetFlip(nge::sdl::RendererFlip::HORIZONTAL);
      player_attack_horiz->SetFlip(nge::sdl::RendererFlip::HORIZONTAL);
      player_attack_down->SetFlip(nge::sdl::RendererFlip::HORIZONTAL);
      current_anim = player_attack_horiz;
      anim_lockout = 20;
      return;
    }
    if (attack_down) {
      attack_down = false;
      player_dir = dir::d;
      attack_down_controller->Restart();
      current_anim = player_attack_down;
      anim_lockout = 20;
      return;
    }
    if (attack_up) {
      attack_up = false;
      player_dir = dir::u;
      attack_up_controller->Restart();
      current_anim = player_attack_up;
      anim_lockout = 20;
      return;
    }

    if (!left && !right && !up && !down) {
      switch (player_dir) {
      case dir::u:
        current_anim = player_idle_up;
        break;
      case dir::d:
        current_anim = player_idle_down;
        break;
      case dir::l:
        player_idle_horiz->SetFlip(nge::sdl::RendererFlip::HORIZONTAL);
        current_anim = player_idle_horiz;
        break;
      case dir::r:
        player_idle_horiz->SetFlip(nge::sdl::RendererFlip::NONE);
        current_anim = player_idle_horiz;
        break;
      }
      return;
    }

    if (left && !right) {
      player_dir = dir::l;
      player_run_horiz->SetFlip(nge::sdl::RendererFlip::HORIZONTAL);
      player_idle_horiz->SetFlip(nge::sdl::RendererFlip::HORIZONTAL);
      current_anim = player_run_horiz;
      return;
    }
    if (!left && right) {
      player_dir = dir::r;
      player_run_horiz->SetFlip(nge::sdl::RendererFlip::NONE);
      player_idle_horiz->SetFlip(nge::sdl::RendererFlip::NONE);
      current_anim = player_run_horiz;
      return;
    }
    if (up && !down) {
      player_dir = dir::u;
      current_anim = player_run_up;
      return;
    }
    if (!up && down) {
      player_dir = dir::d;
      current_anim = player_run_down;
      return;
    }
  }();

  if (!(anim_lockout > 0)) {

    if (left) {
      overworld_offset.x -= 8;
    }
    if (right) {
      overworld_offset.x += 8;
    }
    if (up) {
      overworld_offset.y -= 8;
    }
    if (down) {
      overworld_offset.y += 8;
    }
  }

  current_anim->Draw();
}
void OverworldScene::Tick() {
  if (!(anim_lockout > 0)) {

    if (input_->KeyPressed(nge::sdl::Scancode::RETURN)) {
      std::cout << overworld_offset << "\n";
    }

    if (input_->KeyPressed(nge::sdl::Scancode::I)) {
      attack_up = true;
      return;
    }
    if (input_->KeyPressed(nge::sdl::Scancode::K)) {
      attack_down = true;
      return;
    }
    if (input_->KeyPressed(nge::sdl::Scancode::J)) {
      attack_left = true;
      return;
    }
    if (input_->KeyPressed(nge::sdl::Scancode::L)) {
      attack_right = true;
      return;
    }
  }
}

} // namespace demo