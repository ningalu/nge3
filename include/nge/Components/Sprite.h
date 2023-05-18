#ifndef NGE_COMPONENTS_SPRITE_H
#define NGE_COMPONENTS_SPRITE_H

#include <memory>
#include <tuple>

#include "nge/Components/Drawing/BasicGraphicsUser.h"
#include "ngsdl/Texture.h"

namespace nge {
class Graphics;
class Sprite : public BasicGraphicsUser {
public:
  Sprite() = default;
  Sprite(
    const std::shared_ptr<Graphics> &graphics, const std::string &filename
  );
};
} // namespace nge

#endif