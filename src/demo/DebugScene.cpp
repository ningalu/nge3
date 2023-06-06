#include "demo/DebugScene.h"

#include <iostream>
#include <memory>
#include <stdexcept>

#include "fmt/format.h"

#include "nge/Components/Animation/FrameAnimationController.h"
#include "nge/Components/Animation/TimedAnimationController.h"
#include "nge/Components/BlendedText.h"
#include "nge/Components/Button.h"
#include "nge/Components/Keyboard/BasicKeyUser.h"
#include "nge/Components/Mouse/BasicMouseUser.h"
#include "nge/Components/Mouse/ClickController.h"
#include "nge/Components/Mouse/HoverController.h"
#include "nge/Components/ShadedText.h"
#include "nge/Components/Shapes/Rectangle.h"
#include "nge/Components/SolidText.h"
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

  h1_ =
    std::make_shared<nge::sdl::Font>("./resources/pokemon_pixel_font.ttf", 64);
  h2_ =
    std::make_shared<nge::sdl::Font>("./resources/pokemon_pixel_font.ttf", 48);
  p_ =
    std::make_shared<nge::sdl::Font>("./resources/pokemon_pixel_font.ttf", 32);

  s_ = std::make_shared<nge::Sprite>(graphics_, "resources/Debug/parrot.jpg");
  s_->SetPos(50, 50);
  s_->SetScale(0.25);
  RegisterDrawable(s_);

  timer_anim_ = std::make_shared<nge::AtlasAnimation>(
    graphics_,
    "resources/Debug/brendan.png",
    std::make_shared<nge::TimedAnimationController>(
      .25, 4, std::vector<uint32_t>{0, 1, 0, 2}
    )
  );
  timer_anim_->SetPos(50, 700);
  timer_anim_->SetScale(6);
  RegisterDrawable(timer_anim_);

  timer_anim_label_ = std::make_shared<nge::Text>(
    graphics_, p_, "Timer-based Animation", nge::sdl::Colour{0, 0, 0, 255}
  );
  timer_anim_label_->SetPos(
    timer_anim_->GetPos() - nge::sdl::Point{0, timer_anim_label_->GetH() + 5}
  );

  RegisterDrawable(timer_anim_label_);

  frame_anim_ = std::make_shared<nge::AtlasAnimation>(
    graphics_,
    "resources/Debug/brendan.png",
    std::make_shared<nge::FrameAnimationController>(
      15, 4, std::vector<uint32_t>{0, 1, 0, 2}
    )
  );
  frame_anim_->SetPos(
    timer_anim_->GetPos() + nge::sdl::Point{timer_anim_label_->GetW() + 10, 0}
  );
  frame_anim_->SetScale(6);
  RegisterDrawable(frame_anim_);

  frame_anim_label_ = std::make_shared<nge::Text>(
    graphics_, p_, "Frame-based Animation", nge::sdl::Colour{0, 255, 0, 255}
  );
  frame_anim_label_->SetPos(frame_anim_->GetX(), timer_anim_label_->GetY());
  RegisterDrawable(frame_anim_label_);

  solid_ = std::make_shared<nge::SolidText>(
    graphics_, p_, "Solid Text Style", nge::sdl::Colour{128, 0, 128, 255}
  );

  solid_->SetPos(50, s_->GetY() + s_->GetH() + 20);
  RegisterDrawable(solid_);

  shaded_ = std::make_shared<nge::ShadedText>(
    graphics_,
    p_,
    "Shaded Text Style",
    nge::sdl::Colour{128, 128, 0, 255},
    nge::sdl::Colour{0, 128, 128, 255}
  );
  shaded_->SetPos(50, solid_->GetPos().Y() + solid_->GetH());
  RegisterDrawable(shaded_);

  blended_ = std::make_shared<nge::BlendedText>(
    graphics_, p_, "Blended Text Style", nge::sdl::Colour{0, 128, 128, 255}
  );
  blended_->SetPos(50, shaded_->GetPos().Y() + shaded_->GetH());
  RegisterDrawable(blended_);

  mouse_x_label_ = std::make_shared<nge::Text>(
    graphics_, h1_, "Mouse X: ", nge::sdl::Colour{0, 0, 0, 128}
  );
  mouse_x_label_->SetPos(viewport_->W() - (mouse_x_label_->GetW() * 3), 50);
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

  scene_open_time_ = std::make_shared<nge::Text>(
    graphics_, h2_, "0", nge::sdl::Colour{0, 0, 0, 128}
  );
  scene_open_time_->SetPos(
    timer_anim_->GetPos() + nge::sdl::Point{0, timer_anim_->GetH() + 10}
  );
  RegisterDrawable(scene_open_time_);

  auto k = std::make_shared<nge::BasicKeyUser>();
  k->press = [&](nge::sdl::Scancode s) {
    std::cout << "Pressed: " << static_cast<uint32_t>(s) << "\n";
  };
  k->release = [&](nge::sdl::Scancode s) {
    std::cout << "Released: " << static_cast<uint32_t>(s) << "\n";
  };
  RegisterKeyable(k);

  RegisterDrawable(std::make_shared<nge::Rectangle>(
    graphics_,
    nge::sdl::Rectangle{400, 400, 50, 50},
    nge::sdl::Colour{255, 0, 0, 255}
  ));

  std::shared_ptr<nge::Button> b = std::make_shared<nge::Button>(
    graphics_,
    input_,
    std::make_shared<nge::Text>(
      graphics_, h1_, "test", nge::sdl::Colour{0, 255, 0, 255}
    ),
    []() {
      std::cout << "button test\n";
    }
  );
  b->SetHoverGraphic(std::make_shared<nge::Text>(
    graphics_, h1_, "test", nge::sdl::Colour{0, 0, 255, 255}
  ));
  b->SetHoldGraphic(std::make_shared<nge::Text>(
    graphics_, h1_, "test", nge::sdl::Colour{255, 0, 0, 255}
  ));
  b->SetPos(500, 500);
  RegisterDrawable(b);
  RegisterClickable(b);
  RegisterHoverable(b);

  frame_timer_.Restart();
  scene_timer_.Restart();
}

void DebugScene::Render() {
  mouse_x_->UpdateText(std::to_string(input_->MouseX()));
  mouse_y_->UpdateText(std::to_string(input_->MouseY()));

  frame_interval_->UpdateText(
    fmt::format("{:.3f} ms", frame_timer_.GetElapsedTime() * 1000)
  );

  scene_open_time_->UpdateText(
    h2_,
    fmt::format("{:.3f} s", scene_timer_.GetElapsedTime()),
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