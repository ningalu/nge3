#ifndef NGE3_NGE_VIEW_H
#define NGE3_NGE_VIEW_H

#include <memory>
#include <optional>

#include "ngsdl/Rectangle.h"

namespace nge {
class Graphics;
class Input;

class View {
public:
  View(
    const std::shared_ptr<Graphics> &graphics,
    const std::shared_ptr<nge::Input> &input,
    std::optional<sdl::Rectangle> viewport = std::nullopt
  );

  virtual void Render();
  virtual void Tick();

  const sdl::Rect &GetViewport() const;
  std::tuple<int, int> GetSize() const;
  sdl::Point GetPos() const;

  virtual ~View() = default;

protected:
  std::optional<sdl::Rect> viewport_;
  std::shared_ptr<Graphics> graphics_;
  std::shared_ptr<Input> input_;

private:
};
} // namespace nge

#endif