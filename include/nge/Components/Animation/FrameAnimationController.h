#ifndef NGE_COMPONENTS_ANIMATION_FRAMEANIMATIONCONTROLLER_H
#define NGE_COMPONENTS_ANIMATION_FRAMEANIMATIONCONTROLLER_H

#include <cstdint>
#include <optional>
#include <ostream>
#include <string>

#include "nge/Components/Animation/AnimationController.h"

namespace nge {
class FrameAnimationController : public AnimationController {
public:
  FrameAnimationController() = delete;
  FrameAnimationController(
    uint32_t frames_per_frame,
    uint32_t total_frames,
    std::optional<uint32_t> repeats = std::nullopt
  );

  virtual void Tick() override;
  [[nodiscard]] virtual uint32_t Frame() const override;
  [[nodiscard]] virtual uint32_t TotalFrames() const override;

protected:
  [[nodiscard]] virtual std::string as_string() const override;

  bool active;

  uint32_t max_subframes_;
  uint32_t current_subframe_;

  uint32_t max_frames_;
  uint32_t current_frame_;

  std::optional<uint32_t> max_repeats_;
  uint32_t current_repeat_;
};
} // namespace nge

#endif