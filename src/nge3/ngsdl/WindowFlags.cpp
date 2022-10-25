#include "WindowFlags.h"
namespace nge::sdl {
WindowFlags operator|(const WindowFlags &lhs, const WindowFlags &rhs) {
  return static_cast<WindowFlags>(
    static_cast<int>(lhs) | static_cast<int>(rhs)
  );
}
} // namespace nge::sdl
