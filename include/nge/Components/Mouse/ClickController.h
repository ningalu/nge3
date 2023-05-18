#ifndef NGE_COMPONENTS_MOUSE_CLICKCONTROLLER_H
#define NGE_COMPONENTS_MOUSE_CLICKCONTROLLER_H

#include <functional>

namespace nge {

struct ClickController {
public:
  void OnClick();
  void OnHold(bool hover);
  void OnLoseHold();
  void OnRelease();
  std::function<void(void)> click, hold, release, lose_hold;

protected:
  bool held_;
};
} // namespace nge

#endif