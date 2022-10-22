#include "RendererFlags.h"

namespace nge::sdl {
RendererFlags operator|(const RendererFlags &lhs, const RendererFlags &rhs) {
  return static_cast<RendererFlags>(static_cast<int>(lhs) |
                                    static_cast<int>(rhs));
}
} // namespace nge::sdl