#include "nge/Components/Canvas.h"

#include "nge/Graphics.h"
#include "ngsdl/Surface.h"

namespace nge {
Canvas::Canvas(std::shared_ptr<Graphics> graphics, int w, int h)
    : BasicGraphicsUser(graphics), surf_(sdl::Surface::RGB(w, h)) {
  dst_ = sdl::Rectangle{0, 0, w, h};
}
Canvas::Canvas(std::shared_ptr<Graphics> graphics, int w, int h, sdl::Point dst)
    : BasicGraphicsUser(graphics), surf_(sdl::Surface::RGB(w, h)) {
  dst_ = sdl::Rectangle{dst, w, h};
}
Canvas::Canvas(
  std::shared_ptr<Graphics> graphics, int w, int h, sdl::Rectangle dst
)
    : BasicGraphicsUser(graphics), surf_(sdl::Surface::RGB(w, h)) {
  dst_ = dst;
}

void Canvas::Draw() {
  texture_ = std::make_shared<sdl::Texture>(graphics_->GetRenderer(), surf_);
  BasicGraphicsUser::Draw();
}

} // namespace nge