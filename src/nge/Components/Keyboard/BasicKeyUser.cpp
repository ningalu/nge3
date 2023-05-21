#include "nge/Components/Keyboard/BasicKeyUser.h"

namespace nge {
void BasicKeyUser::PressKey(nge::sdl::Scancode s) {
  if (press) {
    press(s);
  }
}
void BasicKeyUser::HoldKey(nge::sdl::Scancode s) {
  if (hold) {
    hold(s);
  }
}
void BasicKeyUser::ReleaseKey(nge::sdl::Scancode s) {
  if (release) {
    release(s);
  }
}
} // namespace nge