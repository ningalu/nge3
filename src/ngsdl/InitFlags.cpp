#include "ngsdl/InitFlags.h"

#include <cstdint>

namespace nge::sdl {
SDLInitFlags operator|(const SDLInitFlags &lhs, const SDLInitFlags &rhs) {
  return static_cast<SDLInitFlags>(
    static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs)
  );
}
IMGInitFlags operator|(const IMGInitFlags &lhs, const IMGInitFlags &rhs) {
  return static_cast<IMGInitFlags>(
    static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs)
  );
}
} // namespace nge::sdl