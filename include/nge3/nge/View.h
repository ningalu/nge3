#ifndef NGE3_NGE_VIEW_H
#define NGE3_NGE_VIEW_H

#include <memory>
#include <optional>

#include "ngsdl/Rectangle.h"

namespace nge {
class Graphics;

class View {
public:
  View(
    std::shared_ptr<Graphics> graphics,
    std::optional<sdl::Rectangle> viewport = std::nullopt
  );
  virtual void Render();
  virtual ~View() = default;

protected:
  std::optional<sdl::Rect> viewport_;
  std::shared_ptr<Graphics> graphics_;

private:
};
} // namespace nge

#endif