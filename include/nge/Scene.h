#ifndef NGE_VIEW_H
#define NGE_VIEW_H

#include <memory>
#include <optional>
#include <vector>

#include "ngsdl/Rectangle.h"

namespace nge {
class Graphics;
class Input;
class SceneFactory;
class App;
class Drawable;
class Clickable;
class Scene {
  friend SceneFactory;
  friend App;

public:
  Scene();
  void Init();
  virtual void Render() = 0;
  virtual void Tick() = 0;
  virtual void Teardown();

  [[nodiscard]] const std::optional<sdl::Rect> &GetViewport() const;
  void SetViewport(const sdl::Rect &viewport);

  [[nodiscard]] std::tuple<int, int> GetSize() const;
  [[nodiscard]] sdl::Point GetPos() const;

  void RegisterDrawable(std::shared_ptr<Drawable> d);

  virtual ~Scene() = default;

protected:
  std::optional<sdl::Rect> viewport_;
  std::shared_ptr<Graphics> graphics_;
  std::shared_ptr<Input> input_;
  std::vector<std::shared_ptr<Drawable>> draw_queue_;
  std::vector<std::shared_ptr<Clickable>> click_queue_;

private:
  void SetGraphics(const std::shared_ptr<Graphics> &graphics) noexcept;
  void SetInput(const std::shared_ptr<Input> &input) noexcept;
  void RenderQueue() noexcept;
};
} // namespace nge

#endif