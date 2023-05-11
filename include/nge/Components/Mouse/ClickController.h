#ifndef NGE_COMPONENTS_MOUSE_CLICKCONTROLLER_H
#define NGE_COMPONENTS_MOUSE_CLICKCONTROLLER_H

#include <functional>

namespace nge {

struct ClickController {
  void OnClick();
  void OnHold(bool hover);
  void OnRelease();
  std::function<void(void)> click, hold, release;

protected:
  bool held_;
};
} // namespace nge

#endif