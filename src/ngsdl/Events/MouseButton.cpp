#include "ngsdl/Events/MouseButton.h"

namespace nge::sdl {
MouseButton operator|(MouseButton lhs, MouseButton rhs) {
  return static_cast<MouseButton>(
    static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs)
  );
}
bool operator&(MouseButton lhs, MouseButton rhs) {
  return static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs);
}
} // namespace nge::sdl