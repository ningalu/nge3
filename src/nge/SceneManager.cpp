#include "nge/SceneManager.h"

#include "nge/Graphics.h"

#include <stdexcept>

namespace nge {
SceneManager::SceneManager(
  const std::shared_ptr<Graphics> &graphics, const std::shared_ptr<Input> &input
)
    : graphics_(graphics), input_(input) {}

[[nodiscard]] std::shared_ptr<Scene> &SceneManager::GetCurrentScene() {
  if (scenes_.empty()) [[unlikely]] {
    throw std::out_of_range("No Scenes left");
  } else [[likely]] {
    return scenes_.top();
  }
}

void SceneManager::PushScene(std::shared_ptr<Scene> s) { scenes_.push(s); }
void SceneManager::PopScene() {
  scenes_.pop();
  graphics_->SetWindowSize(scenes_.top()->GetSize());
}

void SceneManager::Quit() {
  while (!scenes_.empty()) {
    scenes_.pop();
  }
}

SceneManager::~SceneManager() { Quit(); }

} // namespace nge