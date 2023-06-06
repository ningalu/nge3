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
    if (lose_hold) {
      lose_hold();
    }
  }
  if (hold) {
    hold();
  }
}

void ClickController::OnLoseHold() {
  if (lose_hold) {
    lose_hold();
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

[[nodiscard]] bool ClickController::Held() const noexcept { return held_; }
} // namespace nge