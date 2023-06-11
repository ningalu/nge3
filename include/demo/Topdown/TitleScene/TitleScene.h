#ifndef DEMO_TOPDOWN_TITLESCENE_TITLESCENE_H
#define DEMO_TOPDOWN_TITLESCENE_TITLESCENE_H

#include "nge/Scene.h"

namespace demo {
class TitleScene : public nge::Scene {
public:
  TitleScene() = default;

  virtual void Setup();
  virtual void Render() override;
  virtual void Tick() override;

  ~TitleScene() = default;
};
} // namespace demo

#endif