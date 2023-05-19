#ifndef NGE_COMPONENTS_ANIMATION_FRAMEANIMATIONCONTROLLER_H
#define NGE_COMPONENTS_ANIMATION_FRAMEANIMATIONCONTROLLER_H

#include <cstdint>
#include <optional>
#include <ostream>
#include <string>
#include <vector>

#include "nge/Components/Animation/AnimationController.h"

namespace nge {
class FrameAnimationController : public AnimationController {
public:
  // not sure if i like this more than optional arg with default value
  FrameAnimationController() = delete;
  FrameAnimationController(uint32_t frames_per_frame, uint32_t total_frames);
  FrameAnimationController(
    uint32_t frames_per_frame, uint32_t total_frames, uint32_t repeats
  );
  FrameAnimationController(
    uint32_t frames_per_frame,
    uint32_t total_frames,
    std::vector<uint32_t> frame_order
  );
  FrameAnimationController(
    uint32_t frames_per_frame,
    uint32_t total_frames,
    uint32_t repeats,
    std::vector<uint32_t> frame_order
  );

  virtual void Tick() override;
  [[nodiscard]] virtual uint32_t Frame() const override;
  [[nodiscard]] virtual uint32_t TotalFrames() const override;
  [[nodiscard]] virtual uint32_t UniqueFrames() const override;

  [[nodiscard]] virtual std::string as_string() const override;

protected:
  void Init_(
    uint32_t frames_per_frame,
    uint32_t total_frames,
    std::optional<uint32_t> repeats,
    std::optional<std::vector<uint32_t>> frame_order
  );

  bool active;
  std::vector<uint32_t> frame_order_;
  uint32_t unique_frames_;

  uint32_t max_subframes_;
  uint32_t current_subframe_;

  uint32_t max_frames_;
  uint32_t current_frame_;

  std::optional<uint32_t> max_repeats_;
  uint32_t current_repeat_;
};
} // namespace nge

#endif