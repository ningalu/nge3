#include "demo/IntroScene.h"

#include <iostream>
#include <memory>
#include <stdexcept>

#include "nge/Components/Animation/FrameAnimationController.h"
#include "nge/Components/Mouse/BasicMouseUser.h"
#include "nge/Components/Mouse/ClickController.h"
#include "nge/Components/Mouse/HoverController.h"

#include "ngsdl/Color.h"
#include "ngsdl/Events/MouseButton.h"
#include "ngsdl/FontRenderType.h"

#include "demo/DebugScene.h"
#include "demo/Graph/GraphScene.h"
#include "demo/Pong/PongScene.h"

namespace demo {

void IntroScene::Setup() {
  viewport_ = {50, 50, 800, 600};

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

  pong_normal_ = std::make_shared<nge::Text>(
    graphics_, h2_, "Pong", nge::sdl::Colour{0, 0, 0, 255}
  );
  pong_normal_->SetPos(75, 100);

  pong_selected_ = std::make_shared<nge::Text>(
    graphics_, h2_, "Pong", nge::sdl::Colour{100, 100, 100, 255}
  );
  pong_selected_->SetPos(75, 100);

  text_button_ =
    std::make_shared<nge::Composite<nge::Text, nge::BasicMouseUser>>(
      *pong_normal_, nge::BasicMouseUser{}
    );
  text_button_->SetPos(75, 100);

  text_button_->hover = [&]() {
    return text_button_->Overlaps(input_->MouseX(), input_->MouseY());
  };
  text_button_->prev_hover = [&]() {
    return text_button_->Overlaps(input_->PrevMouseX(), input_->PrevMouseY());
  };
  text_button_->click_valid = text_button_->hover;

  std::shared_ptr<nge::ClickController> c =
    std::make_shared<nge::ClickController>();
  c->click = [&]() {
    std::cout << "pos: " << text_button_->GetPos() << "\n";
    scene_manager_->PushScene(scene_factory_->Create<demo::PongScene>());
  };
  text_button_->AddClickControl(nge::sdl::MouseButton::LEFT, c);

  std::shared_ptr<nge::HoverController> h =
    std::make_shared<nge::HoverController>();
  h->start = [&]() {
    std::cout << "hover start\n";
    text_button_->set<nge::Text>(*pong_selected_);
  };
  h->release = [&]() {
    std::cout << "hover end\n";
    text_button_->set<nge::Text>(*pong_normal_);
  };
  text_button_->SetHoverControl(h);

  RegisterDrawable(text_button_);
  RegisterClickable(text_button_);
  RegisterHoverable(text_button_);

  graph_normal_ = std::make_shared<nge::Text>(
    graphics_, h2_, "Graph", nge::sdl::Colour{0, 0, 0, 255}
  );
  graph_normal_->SetPos(75, 150);

  graph_selected_ = std::make_shared<nge::Text>(
    graphics_, h2_, "Graph", nge::sdl::Colour{100, 100, 100, 255}
  );
  graph_selected_->SetPos(75, 150);

  graph_button_ =
    std::make_shared<nge::Composite<nge::Text, nge::BasicMouseUser>>(
      *graph_normal_, nge::BasicMouseUser{}
    );
  graph_button_->SetPos(75, 150);
  graph_button_->hover = [&]() {
    return graph_button_->Overlaps(input_->MouseX(), input_->MouseY());
  };
  graph_button_->prev_hover = [&]() {
    return graph_button_->Overlaps(input_->PrevMouseX(), input_->PrevMouseY());
  };
  graph_button_->click_valid = graph_button_->hover;
  std::shared_ptr<nge::ClickController> graph_click_control =
    std::make_shared<nge::ClickController>();
  graph_click_control->click = [&]() {
    std::cout << "pos: " << graph_button_->GetPos() << "\n";
    scene_manager_->PushScene(scene_factory_->Create<demo::GraphScene>());
  };
  graph_button_->AddClickControl(
    nge::sdl::MouseButton::LEFT, graph_click_control
  );

  std::shared_ptr<nge::HoverController> graph_hover_control =
    std::make_shared<nge::HoverController>();
  graph_hover_control->start = [&]() {
    std::cout << "hover start\n";
    graph_button_->set<nge::Text>(*graph_selected_);
  };
  graph_hover_control->release = [&]() {
    std::cout << "hover end\n";
    graph_button_->set<nge::Text>(*graph_normal_);
  };
  graph_button_->SetHoverControl(graph_hover_control);

  RegisterDrawable(graph_button_);
  RegisterClickable(graph_button_);
  RegisterHoverable(graph_button_);

  text_select_ = std::make_shared<nge::AtlasAnimation>(
    graphics_,
    "resources/Intro/text_select.png",
    std::make_shared<nge::FrameAnimationController>(45, 2)
  );
  text_select_->SetPos(25, 100);
  RegisterDrawable(text_select_);
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