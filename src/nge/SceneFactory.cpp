#include "nge/SceneFactory.hpp"

namespace nge {
SceneFactory::SceneFactory(
  const std::shared_ptr<Graphics> &graphics,
  const std::shared_ptr<Input> &input,
  const std::shared_ptr<SceneManager> &scene_manager
)
    : graphics_(graphics), input_(input), manager_(scene_manager) {}
} // namespace nge