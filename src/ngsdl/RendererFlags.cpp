#include "ngsdl/RendererFlags.h"

namespace nge::sdl {
RendererFlags operator|(RendererFlags lhs, RendererFlags rhs) {
  return static_cast<RendererFlags>(
    static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs)
  );
}
} // namespace nge::sdl