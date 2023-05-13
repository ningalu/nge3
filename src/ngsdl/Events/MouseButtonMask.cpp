#include "ngsdl/Events/MouseButtonMask.h"

namespace nge::sdl {
[[nodiscard]] MouseButtonMask Mask(MouseButton m) {
  return static_cast<MouseButtonMask>(1 << (static_cast<uint32_t>(m) - 1));
}

}