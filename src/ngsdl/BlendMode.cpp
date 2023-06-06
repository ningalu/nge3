#include "ngsdl/BlendMode.h"

namespace nge::sdl {
std::ostream &operator<<(std::ostream &os, BlendMode blend) {
  switch (blend) {
  case sdl::BlendMode::ADD:
    os << "ADD";
    break;
  case sdl::BlendMode::BLEND:
    os << "BLEND";
    break;
  case sdl::BlendMode::MOD:
    os << "MOD";
    break;
  case sdl::BlendMode::NONE:
    os << "NONE";
    break;
  default:
    os << "Unknown BlendMode";
    break;
  }
  return os;
}
} // namespace nge::sdl