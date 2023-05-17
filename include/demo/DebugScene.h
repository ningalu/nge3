#ifndef NGE3_DEMO_DEBUGSCENE_H
#define NGE3_DEMO_DEBUGSCENE_H

#include <memory>
#include <tuple>

#include "ngsdl/Font.h"

#include "nge/Components/AtlasAnimation.h"
#include "nge/Components/Composite.hpp"
#include "nge/Components/Mouse/Button.h"
#include "nge/Components/Sprite.h"
#include "nge/Components/Text.h"
#include "nge/Scene.h"

namespace demo {
class DebugScene : public nge::Scene {
public:
  DebugScene() = default;

  virtual void Setup();
  virtual void Render() override;
  virtual void Tick() override;

  ~DebugScene();

protected:
  std::shared_ptr<nge::Sprite> s_;
};
} // namespace demo

#endif