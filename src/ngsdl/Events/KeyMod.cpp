#include "ngsdl/Events/KeyMod.h"

#include <cstdint>

namespace nge::sdl {
KeyMod operator|(KeyMod lhs, KeyMod rhs) {
  return static_cast<KeyMod>(
    static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs)
  );
}
bool operator&(KeyMod lhs, KeyMod rhs) {
  return static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs);
}
} // namespace nge::sdl