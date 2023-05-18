#ifndef COMPONENTS_ATLASANIMATION_H
#define COMPONENTS_ATLASANIMATION_H

#include <memory>
#include <optional>

#include "ngsdl/Rectangle.h"

#include "nge/Components/Drawing/Component.h"
#include "nge/Graphics.h"

namespace nge {
class AnimationController;

class AtlasAnimation : public Component {
public:
  AtlasAnimation(
    const std::shared_ptr<Graphics> &graphics,
    const std::string &filename,
    std::shared_ptr<AnimationController> control
  );

  virtual void Draw() override;

protected:
  sdl::Rect frame_dim_;
  std::shared_ptr<AnimationController> control_;
};
} // namespace nge

#endif