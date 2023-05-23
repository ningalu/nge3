#include "ngsdl/Color.h"

namespace nge::sdl {
Color::Color() { color_ = {0, 0, 0, 255}; }

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  color_ = {r, g, b, a};
}

[[nodiscard]] uint8_t Color::GetR() const noexcept { return color_.r; }
[[nodiscard]] uint8_t Color::GetG() const noexcept { return color_.g; }
[[nodiscard]] uint8_t Color::GetB() const noexcept { return color_.b; }
[[nodiscard]] uint8_t Color::GetA() const noexcept { return color_.a; }
[[nodiscard]] std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> Color::GetColors(
) const noexcept {
  return {color_.r, color_.g, color_.b, color_.a};
}
} // namespace nge::sdl