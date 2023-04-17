#ifndef NGE3_NGE_COMPONENTS_BUTTON_H
#define NGE3_NGE_COMPONENTS_BUTTON_H

#include <functional>
#include <memory>

namespace nge {

class Input;

class Clickable {
public:
  Clickable(const std::shared_ptr<Input> &input);

  virtual void OnClick();
  virtual void OnHold();
  virtual void OnRelease();

  virtual bool Hovering() const;

protected:
  bool held_;
  std::shared_ptr<Input> input_;
  std::function<void(void)> on_click_, on_hold_, on_release_;
};
} // namespace nge

#endif