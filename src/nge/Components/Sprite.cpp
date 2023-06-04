#include "nge/Components/Sprite.h"

#include "nge/Graphics.h"
namespace nge {
Sprite::Sprite(
  const std::shared_ptr<Graphics> &graphics, const std::string &filename
)
    : BasicGraphicsUser(graphics) {
  texture_ = std::make_shared<sdl::Texture>(graphics_->GetRenderer(), filename);
  src_ = {0, 0, texture_->GetSize()};
  dst_ = src_;
}

} // namespace nge