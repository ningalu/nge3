#include "ngsdl/Color.h"

namespace nge::sdl {
Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  color_ = {r, g, b, a};
}

uint8_t Color::GetR() const { return color_.r; }
uint8_t Color::GetG() const { return color_.g; }
uint8_t Color::GetB() const { return color_.b; }
uint8_t Color::GetA() const { return color_.a; }
std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> Color::GetColors() const {
  return {color_.r, color_.g, color_.b, color_.a};
}
} // namespace nge::sdl