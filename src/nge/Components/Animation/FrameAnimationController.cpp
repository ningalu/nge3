#include "nge/Components/Animation/FrameAnimationController.h"

#include <algorithm>
#include <format>
#include <string>

namespace nge {

FrameAnimationController::FrameAnimationController(
  uint32_t frames_per_frame, uint32_t total_frames
) {
  Init_(frames_per_frame, total_frames, std::nullopt, std::nullopt);
}

FrameAnimationController::FrameAnimationController(
  uint32_t frames_per_frame, uint32_t total_frames, uint32_t repeats
) {
  Init_(frames_per_frame, total_frames, repeats, std::nullopt);
}

FrameAnimationController::FrameAnimationController(
  uint32_t frames_per_frame,
  uint32_t total_frames,
  std::vector<uint32_t> frame_order
) {
  Init_(frames_per_frame, total_frames, std::nullopt, frame_order);
}
FrameAnimationController::FrameAnimationController(
  uint32_t frames_per_frame,
  uint32_t total_frames,
  uint32_t repeats,
  std::vector<uint32_t> frame_order
) {
  Init_(frames_per_frame, total_frames, repeats, frame_order);
}

void FrameAnimationController::Init_(
  uint32_t frames_per_frame,
  uint32_t total_frames,
  std::optional<uint32_t> repeats,
  std::optional<std::vector<uint32_t>> frame_order
) {
  max_subframes_ = frames_per_frame;
  current_subframe_ = 0;

  max_frames_ = total_frames;
  current_frame_ = 0;

  max_repeats_ = repeats;
  current_repeat_ = 0;

  if (frame_order == std::nullopt) {
    frame_order_.reserve(total_frames);
    for (uint32_t i = 0; i < total_frames; i++) {
      frame_order_.push_back(i);
    }
  } else {
    frame_order_ = frame_order.value();
  }

  unique_frames_
    = *std::max_element(frame_order_.begin(), frame_order_.end()) + 1;

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
  return frame_order_[current_frame_];
}

[[nodiscard]] uint32_t FrameAnimationController::TotalFrames() const {
  return max_frames_;
}

[[nodiscard]] uint32_t FrameAnimationController::UniqueFrames() const {
  return unique_frames_;
}

[[nodiscard]] std::string FrameAnimationController::as_string() const {

  // return std::format(
  //   "{}\n{}\n{}",
  //   std::format(
  //     "Frame Duration: {} frames | Current Subframe: {}",
  //     max_subframes_,
  //     current_subframe_
  //   ),
  //   std::format(
  //     "Total Frames: {} | Current Frame: {}", max_frames_, current_frame_
  //   ),
  //   std::format(
  //     "Total Repeats: {} times | Current Repeat: {}",
  //     max_repeats_ == std::nullopt ? "unlimited" :
  //                                    std::to_string(max_repeats_.value()),
  //     current_repeat_
  //   )
  // );
  return "";
}

} // namespace nge