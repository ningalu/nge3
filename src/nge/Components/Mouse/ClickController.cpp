#include "nge/Components/Mouse/ClickController.h"

namespace nge {
void ClickController::OnClick() {
  click();
  held_ = true;
}
void ClickController::OnHold(bool hover) {

  if (!hover) {
    held_ = false;
  }
  hold();
}
void ClickController::OnRelease() {
  if (held_) {
    release();
    held_ = false;
  }
}
} // namespace nge