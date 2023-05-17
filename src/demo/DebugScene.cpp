#include "demo/DebugScene.h"

#include <iostream>
#include <memory>
#include <stdexcept>

#include "nge/Components/Animation/FrameAnimationController.h"
#include "nge/Components/Mouse/Button.h"
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
  viewport_ = {100, 100, 800, 600};

  s_ = std::make_shared<nge::Sprite>(graphics_, "resources/Intro/parrot.jpg");
  s_->SetPos(400, 100);
  RegisterDrawable(s_);
}

void DebugScene::Render() {}
void DebugScene::Tick() {
  if (input_->KeyPressed(nge::sdl::Scancode::BACKSPACE)) {
    scene_manager_->PopScene();
  }
}
DebugScene::~DebugScene() { std::cout << "destroy debug scene\n"; }

} // namespace demo