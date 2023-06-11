#include "demo/Topdown/TitleScene/TitleScene.h"

#include <iostream>
#include <vector>

#include "nge/Components/Animation/FrameAnimationController.h"
#include "nge/Components/AtlasAnimation.h"
#include "nge/Components/Shapes/Rectangle.h"
#include "nge/Components/Sprite.h"
#include "nge/Components/Text.h"
#include "nge/Timer.h"
#include "ngsdl/Font.h"

static int16_t fade_in;
static bool fading_in;
static std::shared_ptr<nge::sdl::Font> h1_, h2_;
static std::shared_ptr<nge::AtlasAnimation> text_select;
static std::vector<std::shared_ptr<nge::BasicGraphicsUser>> text_select_options;
static int8_t text_select_pos = 0;
static std::shared_ptr<nge::FrameAnimationController> text_select_controller;
namespace demo {

void TitleScene::Setup() {
  viewport_ = nge::sdl::Rectangle{0, 0, 1600, 900};
  text_select_options = {};

  fade_in = 200;
  fading_in = true;

  h1_ = std::make_shared<nge::sdl::Font>(
    "resources/Fonts/8-bit-limit/8bitlim.ttf", 72
  );
  h2_ = std::make_shared<nge::sdl::Font>(
    "resources/Fonts/8-bit-limit/8bitlim.ttf", 40
  );

  auto bg = std::make_shared<nge::Sprite>(
    graphics_, "resources/Game/title_background.png"
  );
  RegisterDrawable(bg);

  auto title_label = std::make_shared<nge::Text>(
    graphics_, h1_, "Working Title", nge::sdl::Color{0xFFBDF7FF}
  );
  title_label->SetPos(25, 25);
  title_label->SetDrawPriority(1);
  RegisterDrawable(title_label);
  auto title_shadow = std::make_shared<nge::Text>(
    graphics_, h1_, "Working Title", nge::sdl::Color{0x00000090}
  );
  title_shadow->SetPos(title_label->GetPos() + nge::sdl::Point{2, 2});
  RegisterDrawable(title_shadow);

  auto play_label = std::make_shared<nge::Text>(
    graphics_, h2_, "Start", nge::sdl::Color{0xFFBDF7FF}
  );
  play_label->SetPos(75, 125);
  play_label->SetDrawPriority(1);
  RegisterDrawable(play_label);
  auto play_shadow = std::make_shared<nge::Text>(
    graphics_, h2_, "Start", nge::sdl::Color{0x00000090}
  );
  play_shadow->SetPos(play_label->GetPos() + nge::sdl::Point{2, 2});
  RegisterDrawable(play_shadow);

  auto options_label = std::make_shared<nge::Text>(
    graphics_, h2_, "Options", nge::sdl::Color{0xFFBDF7FF}
  );
  options_label->SetPos(75, 175);
  options_label->SetDrawPriority(1);
  RegisterDrawable(options_label);
  auto options_shadow = std::make_shared<nge::Text>(
    graphics_, h2_, "Options", nge::sdl::Color{0x00000090}
  );
  options_shadow->SetPos(options_label->GetPos() + nge::sdl::Point{2, 2});
  RegisterDrawable(options_shadow);

  auto quit_label = std::make_shared<nge::Text>(
    graphics_, h2_, "Quit", nge::sdl::Color{0xFFBDF7FF}
  );
  quit_label->SetPos(75, 225);
  quit_label->SetDrawPriority(1);
  RegisterDrawable(quit_label);
  auto quit_shadow = std::make_shared<nge::Text>(
    graphics_, h2_, "Quit", nge::sdl::Color{0x00000090}
  );
  quit_shadow->SetPos(quit_label->GetPos() + nge::sdl::Point{2, 2});
  RegisterDrawable(quit_shadow);

  text_select_options.push_back(play_label);
  text_select_options.push_back(options_label);
  text_select_options.push_back(quit_label);

  text_select_controller =
    std::make_shared<nge::FrameAnimationController>(30, 2);
  text_select = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/text_select.png", text_select_controller
  );
  text_select->SetPos(30, 125);
  RegisterDrawable(text_select);
}
void TitleScene::Render() {

  // doesn't draw the last fade_in at -1
  if (fade_in > 0) {
    graphics_->Draw(
      *viewport_, nge::sdl::Colour{255, 255, 255, static_cast<uint8_t>(fade_in)}
    );
    fade_in -= 3;
  }
}
void TitleScene::Tick() {
  if (!(fade_in > 0)) {

    if (input_->KeyPressed(nge::sdl::Scancode::W)) {
      text_select_pos--;

      // %= doesnt work on negatives sad
      if (text_select_pos < 0) {
        text_select_pos = static_cast<uint8_t>(text_select_options.size() - 1);
      }
      text_select->SetY(text_select_options.at(text_select_pos)->GetY());
      text_select_controller->Restart();
    }
    if (input_->KeyPressed(nge::sdl::Scancode::S)) {
      text_select_pos++;
      text_select_pos %= text_select_options.size();
      text_select->SetY(text_select_options.at(text_select_pos)->GetY());
      text_select_controller->Restart();
    }
  }
}
} // namespace demo