#ifndef NGE_COMPONENTS_ANIMATION_ANIMATIONCONTROLLER_H
#define NGE_COMPONENTS_ANIMATION_ANIMATIONCONTROLLER_H

#include <cstdint>
#include <string>

namespace nge {
class AnimationController {
public:
  virtual void Tick() = 0;
  [[nodiscard]] virtual uint32_t Frame() const = 0;
  [[nodiscard]] virtual uint32_t TotalFrames() const = 0;

  friend std::ostream &
  operator<<(std::ostream &os, const AnimationController &ac);

  virtual ~AnimationController() = default;

  [[nodiscard]] virtual std::string as_string() const = 0;

protected:
};
} // namespace nge

#endif