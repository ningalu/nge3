#include "demo/IntroScene.h"

#include <iostream>
#include <memory>
#include <stdexcept>

#include "nge/Components/Animation/FrameAnimationController.h"
#include "nge/Components/Mouse/BasicMouseUser.h"
#include "nge/Components/Mouse/ClickController.h"
#include "nge/Components/Mouse/HoverController.h"

#include "nge/Components/Button.h"
#include "nge/Components/Canvas.h"

#include "ngsdl/Color.h"
#include "ngsdl/Events/MouseButton.h"
#include "ngsdl/FontRenderType.h"

#include "demo/DebugScene.h"
#include "demo/Graph/GraphScene.h"
#include "demo/Pong/PongScene.h"
#include "demo/Topdown/TitleScene/TitleScene.h"

namespace demo {

void IntroScene::Setup() {
  viewport_ = {50, 50, 800, 600};

  h1_ = std::make_shared<nge::sdl::Font>(
    std::string{SDL_GetBasePath()} + "resources/Fonts/PKMN-Mystery-Dungeon.ttf",
    96
  );
  h2_ = std::make_shared<nge::sdl::Font>(
    std::string{SDL_GetBasePath()} + "resources/Fonts/PKMN-Mystery-Dungeon.ttf",
    72
  );

  nge3_demo_app_text_ = std::make_shared<nge::Text>(
    graphics_, h1_, "NGE3 Demo App", nge::sdl::Colour{128, 128, 128, 128}
  );
  nge3_demo_app_text_->SetPos({25, 25});
  RegisterDrawable(nge3_demo_app_text_);

  pong_button_ = std::make_shared<nge::Button>(
    input_,
    std::make_shared<nge::Text>(graphics_, h2_, "Pong"),
    [&]() {
      scene_manager_->PushScene(scene_factory_->Create<demo::PongScene>());
    }
  );
  pong_button_->SetHoverGraphic(std::make_shared<nge::Text>(
    graphics_, h2_, "Pong", nge::sdl::Colour{100, 100, 100, 255}
  ));
  pong_button_->SetPos(75, 100);
  RegisterDrawable(pong_button_);
  RegisterClickable(pong_button_);
  RegisterHoverable(pong_button_);

  text_select_ = std::make_shared<nge::AtlasAnimation>(
    graphics_,
    "resources/Intro/text_select.png",
    std::make_shared<nge::FrameAnimationController>(45, 2)
  );
  text_select_->SetPos(25, 100);
  RegisterDrawable(text_select_);

  graph_button_ = std::make_shared<nge::Button>(
    input_,
    std::make_shared<nge::Text>(graphics_, h2_, "Graph"),
    [&]() {
      scene_manager_->PushScene(scene_factory_->Create<demo::GraphScene>());
    }
  );
  graph_button_->SetHoverGraphic(std::make_shared<nge::Text>(
    graphics_, h2_, "Graph", nge::sdl::Colour{100, 100, 100, 255}
  ));
  graph_button_->SetPos(75, 150);
  RegisterDrawable(graph_button_);
  RegisterClickable(graph_button_);
  RegisterHoverable(graph_button_);

  auto game_button = std::make_shared<nge::Button>(
    input_,
    std::make_shared<nge::Text>(graphics_, h2_, "Topdown"),
    [&]() {
      scene_manager_->PushScene(scene_factory_->Create<demo::TitleScene>());
    }
  );
  game_button->SetHoverGraphic(std::make_shared<nge::Text>(
    graphics_, h2_, "Topdown", nge::sdl::Colour{100, 100, 100, 255}
  ));
  game_button->SetPos(75, 200);
  RegisterDrawable(game_button);
  RegisterClickable(game_button);
  RegisterHoverable(game_button);
}

void IntroScene::Render() {}
void IntroScene::Tick() {
  if (input_->KeyPressed(nge::sdl::Scancode::F5)) {
    auto demo_scene = scene_factory_->Create<DebugScene>();
    scene_manager_->PushScene(demo_scene);
  }
}
IntroScene::~IntroScene() { std::cout << "destroy intro scene\n"; }

} // namespace demo