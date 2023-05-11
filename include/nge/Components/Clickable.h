#ifndef NGE_COMPONENTS_BUTTON_H
#define NGE_COMPONENTS_BUTTON_H

#include <functional>
#include <memory>

namespace nge {
class Clickable {
public:
  virtual bool Hovering() const = 0;

  virtual ~Clickable() = 0;
};
} // namespace nge

#endif