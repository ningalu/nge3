#include "nge/Components/Sprite.h"

#include "nge/Graphics.h"
namespace nge {
Sprite::Sprite(
  const std::shared_ptr<Graphics> &graphics, const std::string &filename
)
    : SimpleComponent(graphics) {
  texture_ = std::make_shared<sdl::Texture>(graphics_->GetRenderer(), filename);
  src_ = {{0, 0}, texture_->GetSize()};
  dst_ = src_;
}

void Sprite::SetScale(double scale) {
  dst_.SetW(static_cast<int>(static_cast<double>(src_.GetW()) * scale));
  dst_.SetH(static_cast<int>(static_cast<double>(src_.GetH()) * scale));
}
} // namespace nge