#include "ngsdl/Color.h"

#include <bit>
#include <iomanip>

#include "fmt/format.h"

namespace nge::sdl {
Color::Color() : r(0), g(0), b(0), a(0) {}

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : r(r), g(g), b(b), a(a) {}

[[nodiscard]] std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> Color::GetColors(
) const noexcept {
  return std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>{r, g, b, a};
}
} // namespace nge::sdl

std::ostream &operator<<(std::ostream &os, const nge::sdl::Color c) {
  os << fmt::format("r: {0} g: {1} b: {2} a: {3}", c.r, c.g, c.b, c.a);
  return os;
}