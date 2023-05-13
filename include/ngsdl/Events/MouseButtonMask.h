#ifndef NGSDL_MOUSEBUTTONMASK_H
#define NGSDL_MOUSEBUTTONMASK_H

#include <cstdint>

#include "ngsdl/Events/MouseButton.h"

namespace nge::sdl {

enum class MouseButtonMask : uint32_t {
  LEFT = 1 << (static_cast<uint32_t>(MouseButton::LEFT) - 1),
  MIDDLE = 1 << (static_cast<uint32_t>(MouseButton::MIDDLE) - 1),
  RIGHT = 1 << (static_cast<uint32_t>(MouseButton::RIGHT) - 1),
  X1 = 1 << (static_cast<uint32_t>(MouseButton::X1) - 1),
  X2 = 1 << (static_cast<uint32_t>(MouseButton::X2) - 1)
};
[[nodiscard]] MouseButtonMask Mask(MouseButton m);
} // namespace nge::sdl

#endif