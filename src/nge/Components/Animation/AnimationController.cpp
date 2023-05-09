#include "nge/Components/Animation/AnimationController.h"

#include <ostream>

namespace nge {
std::ostream &operator<<(std::ostream &os, const AnimationController &ac) {
  os << ac.as_string();
  return os;
}

} // namespace nge