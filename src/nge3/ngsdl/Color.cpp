#include "Color.h"

namespace nge::sdl {
Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  color_ = {r, g, b, a};
}
} // namespace nge::sdl