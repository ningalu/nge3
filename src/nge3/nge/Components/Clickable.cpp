#include "nge3/nge/Components/Clickable.h"
#include "nge3/nge/Input.h"

namespace nge {
Clickable::Clickable(const std::shared_ptr<Input> &input) : input_(input) {
  held_ = false;
}
void Clickable::OnClick() {
  on_click_();
  held_ = true;
}
void Clickable::OnHold() {
  if (held_) {
    if (!Hovering()) {
      held_ = false;
    }
  }
  on_hold_();
}
void Clickable::OnRelease() {
  if (held_) {
    on_release_();
    held_ = false;
  }
}
} // namespace nge