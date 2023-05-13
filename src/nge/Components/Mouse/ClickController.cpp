#include "nge/Components/Mouse/ClickController.h"

namespace nge {

void ClickController::OnClick() {
  if (click) {
    click();
  }
  held_ = true;
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
    if (release) {
      release();
    }
    held_ = false;
  }
}
} // namespace nge