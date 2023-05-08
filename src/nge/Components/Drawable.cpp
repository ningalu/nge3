#include "nge/Components/Drawable.h"

namespace nge {
[[nodiscard]] uint32_t Drawable::GetDrawPriority() const noexcept { return 0; }
[[nodiscard]] bool Drawable::CompareDrawPriority(
  const std::shared_ptr<Drawable> &lhs, const std::shared_ptr<Drawable> &rhs
) noexcept {
  return lhs->GetDrawPriority() < rhs->GetDrawPriority();
}
Drawable::~Drawable() {}
} // namespace nge