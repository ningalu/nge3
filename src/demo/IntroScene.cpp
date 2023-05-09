#include "demo/IntroScene.h"

#include <iostream>
#include <memory>
#include <stdexcept>

#include "nge/Components/Animation/FrameAnimationController.h"
#include "nge/Graphics.h"
#include "nge/Input.h"

#include "ngsdl/Color.h"
#include "ngsdl/Events/MouseButton.h"
#include "ngsdl/FontRenderType.h"

namespace demo {

void IntroScene::Setup() {
  viewport_ = {50, 50, 1200, 900};

  s_ = std::make_shared<nge::Sprite>(graphics_, "resources/Intro/parrot.jpg");
  s_->SetPos(400, 100);

  h1_ = std::make_shared<nge::sdl::Font>(
    std::string{SDL_GetBasePath()} + "resources/PKMN-Mystery-Dungeon.ttf", 96
  );
  h2_ = std::make_shared<nge::sdl::Font>(
    std::string{SDL_GetBasePath()} + "resources/PKMN-Mystery-Dungeon.ttf", 72
  );

  nge3_demo_app_text_ = std::make_shared<nge::Text>(
    graphics_, h1_, "NGE3 Demo App", nge::sdl::Colour{128, 128, 128, 128}
  );
  nge3_demo_app_text_->SetPos({25, 25});
  RegisterDrawable(nge3_demo_app_text_);

  pong_text_ = std::make_shared<nge::Text>(
    graphics_, h2_, "Pong", nge::sdl::Colour{0, 0, 0, 255}
  );
  pong_text_->SetPos({75, 100});
  RegisterDrawable(pong_text_);

  text_select_ = std::make_shared<nge::AtlasAnimation>(
    graphics_,
    "resources/Intro/text_select.png",
    std::make_shared<nge::FrameAnimationController>(45, 2)
  );
  text_select_->SetPos(25, 100);
}

void IntroScene::Render() {
  // nge3_demo_app_text_->Draw();
  // pong_text_->Draw();
  text_select_->Draw();
  // s_->Draw();
}
void IntroScene::Tick() {
  if (input_->KeyDown(nge::sdl::Scancode::SPACE)) {
  }
  if (input_->MouseClicked(nge::sdl::MouseButton::LEFT)) {
    std::cout << "left click\n";
  }
  if (input_->MouseHeld(nge::sdl::MouseButton::LEFT)) {
    std::cout << "left held\n";
  }
  if (input_->MouseReleased(nge::sdl::MouseButton::LEFT)) {
    std::cout << "left release\n";
  }
}
IntroScene::~IntroScene() { std::cout << "destroy intro scene\n"; }

} // namespace demo