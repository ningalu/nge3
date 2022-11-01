#include "nge/View.h"

#include <iostream>

#include "nge/Graphics.h"

namespace nge {
View::View(
  const std::shared_ptr<Graphics> &graphics,
  std::optional<sdl::Rectangle> viewport
)
    : graphics_(graphics) {
  if (viewport != std::nullopt) {
    viewport_ = viewport;
    graphics_->SetWindowPos({viewport_->GetX(), viewport_->GetY()});
    graphics_->SetWindowSize(viewport_->GetW(), viewport_->GetH());
  } else {
    auto p = graphics_->GetWindowPos();
    auto size = graphics_->GetWindowSize();
    viewport_ = {p, size};
  }
}
void View::Render() { /*std::cout << "Rendering\n";*/
}

// Viewport should always be initialised to some actual value
// I wonder if the compiler can see through this
const sdl::Rect &View::GetViewport() const { return *viewport_; }
std::tuple<int, int> View::GetSize() const {
  return {viewport_->GetW(), viewport_->GetH()};
}
sdl::Point View::GetPos() const {
  return {viewport_->GetX(), viewport_->GetY()};
}
} // namespace nge