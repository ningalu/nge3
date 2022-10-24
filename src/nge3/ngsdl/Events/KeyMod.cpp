#include "Events/KeyMod.h"

namespace nge::sdl {
KeyMod operator|(KeyMod lhs, KeyMod rhs) {
  return KeyMod{static_cast<Uint16>(lhs) | static_cast<Uint16>(rhs)};
}
bool operator&(KeyMod lhs, KeyMod rhs) {
  return static_cast<Uint16>(lhs) & static_cast<Uint16>(rhs);
}
} // namespace nge::sdl