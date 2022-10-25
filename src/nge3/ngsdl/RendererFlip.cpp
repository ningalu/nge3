#include "RendererFlip.h"

namespace nge::sdl {
RendererFlip operator|(const RendererFlip &lhs, const RendererFlip &rhs) {
  return static_cast<RendererFlip>(
      static_cast<int>(lhs) | static_cast<int>(rhs)
  );
}

} // namespace nge::sdl