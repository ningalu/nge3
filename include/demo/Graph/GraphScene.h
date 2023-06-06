#include "nge/Scene.h"

namespace demo {
class GraphScene : public nge::Scene {
public:
  GraphScene() = default;

  virtual void Setup();
  virtual void Render() override;
  virtual void Tick() override;

  ~GraphScene() = default;
};
} // namespace demo