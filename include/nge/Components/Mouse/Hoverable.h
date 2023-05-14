#ifndef NGE_COMPONENTS_MOUSE_HOVERABLE_H
#define NGE_COMPONENTS_MOUSE_HOVERABLE_H

#include <cstdint>

namespace nge {
class Hoverable {
public:
  [[nodiscard]] virtual bool Hovering() const = 0;
  [[nodiscard]] virtual bool PrevHovering() const = 0;
  virtual void OnStartHover() = 0;
  virtual void OnHoldHover() = 0;
  virtual void OnReleaseHover() = 0;
};
} // namespace nge

#endif