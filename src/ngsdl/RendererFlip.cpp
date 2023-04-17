#include "ngsdl/RendererFlip.h"

#include <cstdint>

namespace nge::sdl {
RendererFlip operator|(RendererFlip lhs, RendererFlip rhs) {
  return static_cast<RendererFlip>(
    static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs)
  );
}

} // namespace nge::sdl