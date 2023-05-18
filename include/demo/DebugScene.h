#ifndef NGE3_DEMO_DEBUGSCENE_H
#define NGE3_DEMO_DEBUGSCENE_H

#include <memory>

#include "nge/Components/Sprite.h"
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