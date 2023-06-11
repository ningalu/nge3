#ifndef DEMO_TOPDOWN_OVERWORLDSCENE_OVERWORLDSCENE_H
#define DEMO_TOPDOWN_OVERWORLDSCENE_OVERWORLDSCENE_H

#include "nge/Scene.h"

namespace demo {
class OverworldScene : public nge::Scene {
public:
  OverworldScene() = default;

  virtual void Setup();
  virtual void Render() override;
  virtual void Tick() override;

  ~OverworldScene() = default;
};
} // namespace demo

#endif