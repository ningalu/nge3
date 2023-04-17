#include "ngsdl/Events/MouseButton.h"

namespace nge::sdl {
MouseButton operator|(MouseButton lhs, MouseButton rhs) {
  return MouseButton{static_cast<Uint16>(lhs) | static_cast<Uint16>(rhs)};
}
bool operator&(MouseButton lhs, MouseButton rhs) {
  return static_cast<Uint16>(lhs) & static_cast<Uint16>(rhs);
}
} // namespace nge::sdl