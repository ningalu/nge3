#include "BlendMode.h"

namespace nge::sdl {
std::ostream &operator<<(std::ostream &os, const BlendMode blend) {
  switch (blend) {
  case sdl::BlendMode::ADD:
    os << "ADD";
    return os;
  case sdl::BlendMode::BLEND:
    os << "BLEND";
    return os;
  case sdl::BlendMode::MOD:
    os << "MOD";
    return os;
  case sdl::BlendMode::NONE:
    os << "NONE";
    return os;
  default:
    os << "Unknown BlendMode";
    return os;
  }
}
} // namespace nge::sdl