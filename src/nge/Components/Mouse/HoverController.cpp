#include "nge/Components/Mouse/HoverController.h"

namespace nge {

void HoverController::OnStartHover() {
  if (start) {
    start();
  }
}
void HoverController::OnHoldHover() {
  if (hold) {
    hold();
  }
}
void HoverController::OnReleaseHover() {
  if (release) {
    release();
  }
}
} // namespace nge