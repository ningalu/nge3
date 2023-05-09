#include "nge/Components/Animation/FrameAnimationController.h"

#include <format>
#include <string>

namespace nge {

FrameAnimationController::FrameAnimationController(
  uint32_t frames_per_frame,
  uint32_t total_frames,
  std::optional<uint32_t> repeats
) {
  max_subframes_ = frames_per_frame;
  current_subframe_ = 0;

  max_frames_ = total_frames;
  current_frame_ = 0;

  max_repeats_ = repeats;
  current_repeat_ = 0;

  active = true;
}

void FrameAnimationController::Tick() {
  if (active) {
    if (current_subframe_ < (max_subframes_ - 1)) {
      current_subframe_++;
    } else {
      current_subframe_ = 0;
      if (current_frame_ < (max_frames_ - 1)) {
        current_frame_++;
      } else {
        current_frame_ = 0;
        if (max_repeats_ == std::nullopt) {
          current_repeat_++;
        } else {
          if (current_repeat_ < (max_repeats_.value() - 1)) {
            current_repeat_++;
          } else {
            current_subframe_ = max_subframes_ - 1;
            current_frame_ = max_frames_ - 1;
            current_repeat_ = max_repeats_.value() - 1;
            active = false;
          }
        }
      }
    }
  }
}
[[nodiscard]] uint32_t FrameAnimationController::Frame() const {
  return current_frame_;
}

[[nodiscard]] uint32_t FrameAnimationController::TotalFrames() const {
  return max_frames_;
}

[[nodiscard]] std::string FrameAnimationController::as_string() const {
  return std::format(
    "{}\n{}\n{}",
    std::format(
      "Frame Duration: {} frames | Current Subframe: {}",
      max_subframes_,
      current_subframe_
    ),
    std::format(
      "Total Frames: {} | Current Frame: {}", max_frames_, current_frame_
    ),
    std::format(
      "Total Repeats: {} times | Current Repeat: {}",
      max_repeats_ == std::nullopt ? "unlimited" :
                                     std::to_string(max_repeats_.value()),
      current_repeat_
    )
  );
}

} // namespace nge