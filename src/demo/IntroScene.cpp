#include "demo/IntroScene.h"

#include <iostream>
#include <memory>
#include <stdexcept>

#include "nge/Graphics.h"
#include "nge/Input.h"

#include "ngsdl/Color.h"
#include "ngsdl/Events/MouseButton.h"
#include "ngsdl/FontRenderType.h"

namespace demo {

void IntroScene::Setup() {
  viewport_ = {50, 50, 1200, 900};
  // among_us_ = nge::Sprite{graphics_, "resources/Intro/parrot.jpg"};
  // among_us_.SetScale(1.0);
  // among_us_.SetPos({50, 50});
  // among_us_pos_ = {50.0, 50.0};
  s_ = std::make_shared<nge::Sprite>(graphics_, "resources/Intro/parrot.jpg");

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
  // RegisterDrawable(nge3_demo_app_text_);

  pong_text_ = std::make_shared<nge::Text>(
    graphics_, h2_, "Pong", nge::sdl::Colour{0, 0, 0, 255}
  );
  pong_text_->SetPos({75, 100});
  // RegisterDrawable(pong_text_);

  // a = {graphics_, h1_, "NGE3 Demo App", nge::sdl::Colour{0, 0, 0, 255}};
  // a.SetAngle(180);
  // b = {graphics_, h2_, "Pong", nge::sdl::Colour{0, 0, 0, 255}};
  // b.SetAngle(270);

  c = std::make_unique<nge::Text>(
    graphics_, h1_, "C", nge::sdl::Colour{128, 128, 128, 128}
  );
  // c->SetAngle(180);
  c->SetPos({700, 700});
  d = std::make_unique<nge::Text>(
    graphics_, h2_, "D", nge::sdl::Colour{0, 255, 0, 255}
  );
  // d->SetAngle(270);
  d->SetPos({600, 600});
}

void IntroScene::Render() {
  // among_us_.Draw();
  nge3_demo_app_text_->Draw();
  // throw std::exception("lol");
  // pong_text_->Draw();
  // (&a)->Draw();
  // (&b)->Draw();
  c->Draw();
  // d->Draw();
  s_->Draw();
}
void IntroScene::Tick() {
  if (input_->KeyDown(nge::sdl::Scancode::SPACE)) {
    std::get<0>(among_us_pos_) += 0.1;
    std::get<1>(among_us_pos_) += 0.1;
    among_us_.SetPos(
      {static_cast<int>(std::get<0>(among_us_pos_)),
       static_cast<int>(std::get<1>(among_us_pos_))}
    );
  }
  if (input_->MouseClicked(nge::sdl::MouseButton::LEFT)) {
    std::cout << "left click\n";
    nge3_demo_app_text_->SetX(700);
    nge3_demo_app_text_->SetY(700);
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