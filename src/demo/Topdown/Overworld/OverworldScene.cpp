#include "demo/Topdown/Overworld/OverworldScene.h"

#include <memory>

#include "nge/Components/Animation/FrameAnimationController.h"
#include "nge/Components/AtlasAnimation.h"

static std::shared_ptr<nge::AtlasAnimation> player_idle;

namespace demo {

void OverworldScene::Setup() {
  auto idle_controller = std::make_shared<nge::FrameAnimationController>(10, 4);
  player_idle = std::make_shared<nge::AtlasAnimation>(
    graphics_, "resources/Game/player_idle.png", idle_controller
  );
}
void OverworldScene::Render() { player_idle->Draw(); }
void OverworldScene::Tick() {}

} // namespace demo