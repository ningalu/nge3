#ifndef NGE_SCENEFACTORY_H
#define NGE_SCENEFACTORY_H

#include <memory>
#include <optional>

#include "nge/Setupable.hpp"

namespace nge {
class Scene;
class SceneManager;
class Input;
class Graphics;

class SceneFactory : public std::enable_shared_from_this<SceneFactory> {
public:
  SceneFactory() = delete;
  SceneFactory(
    const std::shared_ptr<Graphics> &graphics,
    const std::shared_ptr<Input> &input,
    const std::shared_ptr<SceneManager> &scene_manager
  );

  template <class S, typename... Args>
  std::shared_ptr<Scene> Create(Args... args)
    requires std::derived_from<S, Scene> && Setupable<S, Args...>
  {
    std::shared_ptr<S> scene = std::make_shared<S>();
    scene->SetGraphics(graphics_);
    scene->SetInput(input_);
    scene->SetSceneManager(manager_);
    scene->SetSceneFactory(shared_from_this());
    if (scene->GetViewport() == std::nullopt) {
      scene->SetViewport({50, 50, 800, 600});
    }
    scene->Setup(args...);
    return scene;
  }

protected:
  std::shared_ptr<SceneManager> manager_;
  std::shared_ptr<Input> input_;
  std::shared_ptr<Graphics> graphics_;
};

} // namespace nge

#endif