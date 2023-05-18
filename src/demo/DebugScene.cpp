#include "demo/DebugScene.h"

#include <format>
#include <iostream>
#include <memory>
#include <stdexcept>

#include "nge/Components/Animation/TimedAnimationController.h"
#include "nge/Components/Mouse/BasicMouseUser.h"
#include "nge/Components/Mouse/ClickController.h"
#include "nge/Components/Mouse/HoverController.h"
#include "nge/Graphics.h"
#include "nge/Input.h"
#include "nge/SceneManager.h"

#include "ngsdl/Color.h"
#include "ngsdl/Events/MouseButton.h"
#include "ngsdl/Events/Scancode.h"
#include "ngsdl/FontRenderType.h"

namespace demo {

void DebugScene::Setup() {
  viewport_ = {100, 100, 1200, 900};

  s_ = std::make_shared<nge::Sprite>(graphics_, "resources/Debug/parrot.jpg");
  s_->SetPos(50, 50);
  s_->SetScale(0.25);
  RegisterDrawable(s_);
  tc_ = std::make_shared<nge::TimedAnimationController>(.5, 4);
  a_ = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Debug/brendan.png", tc_
  );
  a_->SetPos(50, 700);
  a_->SetScale(6);
  RegisterDrawable(a_);

  h1_ = std::make_shared<nge::sdl::Font>(
    "./resources/pokemon_pixel_font.ttf", 64
  );
  h2_ = std::make_shared<nge::sdl::Font>(
    "./resources/pokemon_pixel_font.ttf", 48
  );
  p_ = std::make_shared<nge::sdl::Font>(
    "./resources/pokemon_pixel_font.ttf", 32
  );

  solid_ = std::make_shared<nge::Text>(
    graphics_, p_, "Solid Text Style", nge::sdl::Colour{128, 0, 128, 255}
  );
  solid_->SetPos(50, s_->GetY() + s_->GetH() + 20);
  RegisterDrawable(solid_);

  shaded_ = std::make_shared<nge::Text>(
    graphics_,
    p_,
    "Shaded Text Style",
    nge::sdl::Colour{128, 128, 0, 255},
    nge::sdl::FontRenderType::SHADED
  );
  shaded_->SetPos(50, solid_->GetPos().GetY() + solid_->GetH());
  RegisterDrawable(shaded_);

  blended_ = std::make_shared<nge::Text>(
    graphics_,
    p_,
    "Blended Text Style",
    nge::sdl::Colour{0, 128, 128, 255},
    nge::sdl::FontRenderType::BLENDED
  );
  blended_->SetPos(50, shaded_->GetPos().GetY() + shaded_->GetH());
  RegisterDrawable(blended_);

  mouse_x_label_ = std::make_shared<nge::Text>(
    graphics_, h1_, "Mouse X: ", nge::sdl::Colour{0, 0, 0, 128}
  );
  mouse_x_label_->SetPos(viewport_->GetW() - (mouse_x_label_->GetW() * 3), 50);
  RegisterDrawable(mouse_x_label_);

  mouse_y_label_ = std::make_shared<nge::Text>(
    graphics_, h1_, "Mouse Y: ", nge::sdl::Colour{0, 0, 0, 128}
  );
  mouse_y_label_->SetPos(
    mouse_x_label_->GetX(), mouse_x_label_->GetY() + mouse_x_label_->GetH() + 10
  );
  RegisterDrawable(mouse_y_label_);

  mouse_x_ = std::make_shared<nge::Text>(
    graphics_,
    h1_,
    std::to_string(input_->MouseX()),
    nge::sdl::Colour{0, 0, 0, 128}
  );
  mouse_x_->SetPos(
    mouse_x_label_->GetX() + mouse_x_label_->GetW() + 5, mouse_x_label_->GetY()
  );
  RegisterDrawable(mouse_x_);

  mouse_y_ = std::make_shared<nge::Text>(
    graphics_,
    h1_,
    std::to_string(input_->MouseY()),
    nge::sdl::Colour{0, 0, 0, 128}
  );
  mouse_y_->SetPos(
    mouse_y_label_->GetX() + mouse_y_label_->GetW() + 5, mouse_y_label_->GetY()
  );
  RegisterDrawable(mouse_y_);

  frame_interval_label_ = std::make_shared<nge::Text>(
    graphics_, h1_, "Frame Interval: ", nge::sdl::Colour{0, 0, 0, 128}
  );
  frame_interval_label_->SetPos(
    mouse_y_label_->GetX(), mouse_y_label_->GetY() + mouse_y_label_->GetH() + 10
  );
  RegisterDrawable(frame_interval_label_);

  frame_interval_ = std::make_shared<nge::Text>(
    graphics_, h1_, " ", nge::sdl::Colour{0, 0, 0, 128}
  );
  frame_interval_->SetPos(
    frame_interval_label_->GetX() + frame_interval_label_->GetW() + 5,
    frame_interval_label_->GetY()
  );
  RegisterDrawable(frame_interval_);

  frame_timer_.Restart();
}

void DebugScene::Render() {
  mouse_x_->UpdateText(
    h1_, std::to_string(input_->MouseX()), nge::sdl::Colour{0, 0, 0, 128}
  );
  mouse_y_->UpdateText(
    h1_, std::to_string(input_->MouseY()), nge::sdl::Colour{0, 0, 0, 128}
  );

  frame_interval_->UpdateText(
    h1_,
    std::format("{:.3f} ms", frame_timer_.GetElapsedTime() * 1000),
    nge::sdl::Colour{0, 0, 0, 128}
  );
  frame_timer_.Restart();
}

void DebugScene::Tick() {
  if (input_->KeyPressed(nge::sdl::Scancode::BACKSPACE)) {
    scene_manager_->PopScene();
  }
}
DebugScene::~DebugScene() { std::cout << "destroy debug scene\n"; }

} // namespace demo