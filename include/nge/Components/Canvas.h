#ifndef NGE_COMPONENTS_CANVAS_H
#define NGE_COMPONENTS_CANVAS_H

#include "nge/Components/Drawing/BasicGraphicsUser.h"

#include <memory>

#include "SDL2/SDL.h"

#include "ngsdl/Color.h"
#include "ngsdl/Rectangle.h"
#include "ngsdl/Surface.h"

namespace nge {
namespace sdl {
class Surface;
}
class Canvas : public BasicGraphicsUser {
public:
  Canvas() = delete;
  Canvas(std::shared_ptr<Graphics> graphics, int w, int h);
  Canvas(std::shared_ptr<Graphics> graphics, int w, int h, sdl::Point dst);
  Canvas(std::shared_ptr<Graphics> graphics, int w, int h, sdl::Rectangle dst);

  virtual void Draw() override;

  [[nodiscard]] inline sdl::Colour &operator()(std::size_t x, std::size_t y) {
    return surf_->Pixels(x, y);
  }
  [[nodiscard]] inline sdl::Colour &at(std::size_t x, std::size_t y) {
    return surf_->Pixels(x, y);
  }

protected:
  std::unique_ptr<sdl::Surface, decltype(&SDL_FreeSurface)> surf_;
};
} // namespace nge

#endif