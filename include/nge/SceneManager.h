#ifndef NGE_SCENEMANAGER_H
#define NGE_SCENEMANAGER_H

#include <concepts>
#include <iostream>
#include <memory>
#include <optional>
#include <stack>

#include "ngsdl/Rectangle.h"

#include "nge/Scene.h"
#include "nge/Setupable.hpp"

namespace nge {
class Graphics;
class Input;
class App;

class SceneManager {
public:
  SceneManager() = delete;
  SceneManager(
    const std::shared_ptr<Graphics> &graphics,
    const std::shared_ptr<Input> &input
  );

  [[nodiscard]] std::shared_ptr<Scene> &GetCurrentScene();
  void PushScene(std::shared_ptr<Scene> s);
  void PopScene();

  void Quit();

  ~SceneManager();

protected:
  std::shared_ptr<Graphics> graphics_;
  std::shared_ptr<Input> input_;
  std::stack<std::shared_ptr<Scene>> scenes_;
};
} // namespace nge

#endif