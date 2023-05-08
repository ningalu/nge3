#ifndef NGE_SCENEFACTORY_H
#define NGE_SCENEFACTORY_H

#include <concepts>
#include <iostream>
#include <memory>
#include <optional>

#include "ngsdl/Rectangle.h"

#include "nge/Scene.h"
#include "nge/Setupable.hpp"

namespace nge {
class Graphics;
class Input;
class SceneFactory {
public:
  SceneFactory() = delete;
  SceneFactory(
    const std::shared_ptr<Graphics> &graphics,
    const std::shared_ptr<Input> &input
  );

  template <class S, typename... Args>
  std::unique_ptr<Scene> Create(Args... args)
    requires std::derived_from<S, Scene> && Setupable<S, Args...>
  {
    std::unique_ptr<S> scene = std::make_unique<S>();
    scene->SetGraphics(graphics_);
    scene->SetInput(input_);
    if (scene->GetViewport() == std::nullopt) {
      scene->SetViewport({50, 50, 800, 600});
    }
    scene->Setup(args...);
    return scene;
  }

protected:
  std::shared_ptr<Graphics> graphics_;
  std::shared_ptr<Input> input_;
};
} // namespace nge

#endif