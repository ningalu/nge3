#ifndef NGE_COMPONENTS_ANIMATION_TIMEDANIMATIONCONTROLLER_H
#define NGE_COMPONENTS_ANIMATION_TIMEDANIMATIONCONTROLLER_H

#include <cstdint>
#include <optional>
#include <ostream>
#include <string>

#include "nge/Components/Animation/AnimationController.h"
#include "nge/Timer.h"

namespace nge {
class TimedAnimationController : public AnimationController {
public:
  TimedAnimationController() = delete;
  TimedAnimationController(
    double time_per_frame,
    uint32_t total_frames,
    std::optional<uint32_t> repeats = std::nullopt
  );

  virtual void Tick() override;
  [[nodiscard]] virtual uint32_t Frame() const override;
  [[nodiscard]] virtual uint32_t TotalFrames() const override;

  [[nodiscard]] virtual std::string as_string() const override;

protected:
  bool active;

  Timer timer_;
  double time_per_frame_;

  uint32_t max_frames_;
  uint32_t current_frame_;

  std::optional<uint32_t> max_repeats_;
  uint32_t current_repeat_;
};
} // namespace nge

#endif