#include "nge/Components/Mouse/ClickController.h"

namespace nge {

void ClickController::OnClick() {
  held_ = true;
  if (click) {
    click();
  }
}
void ClickController::OnHold(bool hover) {

  if (!hover) {
    held_ = false;
  }
  if (hold) {
    hold();
  }
}
void ClickController::OnRelease() {
  if (held_) {
    held_ = false;
    if (release) {
      release();
    }
  }
}
} // namespace nge