#include "nge/SceneFactory.hpp"

namespace nge {
SceneFactory::SceneFactory(
  const std::shared_ptr<Graphics> &graphics, const std::shared_ptr<Input> &input
)
    : graphics_(graphics), input_(input) {}
} // namespace nge