#ifndef NGE_COMPONENTS_MOUSE_HOVERCONTROLLER_H
#define NGE_COMPONENTS_MOUSE_HOVERCONTROLLER_H

#include <functional>

namespace nge {
struct HoverController {
public:
  void OnStartHover();
  void OnHoldHover();
  void OnReleaseHover();
  std::function<void(void)> start, hold, release;

protected:
  bool hover_;
};
} // namespace nge

#endif