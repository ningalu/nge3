#include "nge/View.h"

#include <iostream>

#include "nge/Graphics.h"

namespace nge {
View::View(
  std::shared_ptr<Graphics> graphics, std::optional<sdl::Rectangle> viewport
)
    : graphics_(graphics) {
  if (viewport != std::nullopt) {
    viewport_ = viewport;
    graphics_->SetWindowPos({viewport_->GetX(), viewport_->GetY()});
    graphics_->SetWindowSize(viewport_->GetW(), viewport_->GetH());
  } else {
    auto p = graphics_->GetWindowPos();
    auto [w, h] = graphics_->GetWindowSize();
    viewport_ = {p, {w, h}};
  }
}
void View::Render() { /*std::cout << "Rendering\n";*/
}
} // namespace nge