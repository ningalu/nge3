#include "WindowFlag.h"
namespace nge::sdl {
WindowFlag operator|(const WindowFlag &lhs, const WindowFlag &rhs) {
  return static_cast<WindowFlag>(static_cast<int>(lhs) | static_cast<int>(rhs));
}
} // namespace nge::sdl
