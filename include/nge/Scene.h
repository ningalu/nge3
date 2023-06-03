#ifndef NGE_SCENE_H
#define NGE_SCENE_H

#include <memory>
#include <optional>
#include <vector>

#include "ngsdl/Events/MouseButton.h"
#include "ngsdl/Events/Scancode.h"
#include "ngsdl/Rectangle.h"

#include "nge/Components/Drawing/Drawable.h"
#include "nge/Components/Keyboard/Keyable.h"
#include "nge/Components/Mouse/Clickable.h"
#include "nge/Components/Mouse/Hoverable.h"
#include "nge/Graphics.h"
#include "nge/Input.h"
#include "nge/SceneFactory.hpp"
#include "nge/SceneManager.h"

namespace nge {
class App;

class Scene {
  friend SceneManager;
  friend SceneFactory;
  friend App;

public:
  Scene();
  void Init();
  virtual void Render() = 0;
  virtual void Tick() = 0;
  virtual void Teardown();

  [[nodiscard]] const std::optional<sdl::Rectangle> &GetViewport() const;
  void SetViewport(const sdl::Rectangle &viewport);

  [[nodiscard]] std::tuple<int, int> GetSize() const;
  [[nodiscard]] sdl::Point GetPos() const;

  void RegisterDrawable(std::shared_ptr<Drawable> d);
  void RegisterClickable(std::shared_ptr<Clickable> c);
  void RegisterHoverable(std::shared_ptr<Hoverable> h);
  void RegisterKeyable(std::shared_ptr<Keyable> k);

  virtual ~Scene() = default;

protected:
  std::optional<sdl::Rectangle> viewport_;
  std::shared_ptr<Graphics> graphics_;
  std::shared_ptr<Input> input_;
  std::shared_ptr<SceneManager> scene_manager_;
  std::shared_ptr<SceneFactory> scene_factory_;
  std::vector<std::shared_ptr<Drawable>> draw_queue_;
  std::vector<std::shared_ptr<Clickable>> click_queue_;
  std::vector<std::shared_ptr<Hoverable>> hover_queue_;
  std::vector<std::shared_ptr<Keyable>> key_queue_;

private:
  void SetGraphics(const std::shared_ptr<Graphics> &graphics) noexcept;
  void SetInput(const std::shared_ptr<Input> &input) noexcept;
  void SetSceneManager(const std::shared_ptr<SceneManager> &sm) noexcept;
  void SetSceneFactory(const std::shared_ptr<SceneFactory> &sf) noexcept;

  void RenderQueue();

  void ClickMouseQueue(sdl::MouseButton m);
  void HoldMouseQueue(sdl::MouseButton m);
  void ReleaseMouseQueue(sdl::MouseButton m);

  void PressKeyQueue(sdl::Scancode s);
  void HoldKeyQueue(sdl::Scancode s);
  void ReleaseKeyQueue(sdl::Scancode s);

  void HoverQueue();
};
} // namespace nge

#endif