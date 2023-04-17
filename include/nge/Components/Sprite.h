#ifndef NGE3_NGE_COMPONENTS_SPRITE_H
#define NGE3_NGE_COMPONENTS_SPRITE_H

#include <memory>
#include <tuple>

#include "nge/Components/SimpleComponent.h"
#include "ngsdl/Texture.h"

namespace nge {
class Graphics;
class Sprite : public SimpleComponent {
public:
  Sprite() = default;
  Sprite(
    const std::shared_ptr<Graphics> &graphics, const std::string &filename
  );

  void SetScale(double scale);
};
} // namespace nge

#endif