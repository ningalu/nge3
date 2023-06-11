#include "nge/Components/Animation/TimedAnimationController.h"

#include <algorithm>
#include <string>

#include "fmt/format.h"

namespace nge {

TimedAnimationController::TimedAnimationController(
  double time_per_frame, uint32_t total_frames
) {
  Init_(time_per_frame, total_frames, std::nullopt, std::nullopt);
}
TimedAnimationController::TimedAnimationController(
  double time_per_frame, uint32_t total_frames, uint32_t repeats
) {
  Init_(time_per_frame, total_frames, repeats, std::nullopt);
}
TimedAnimationController::TimedAnimationController(
  double time_per_frame,
  uint32_t total_frames,
  std::vector<uint32_t> frame_order
) {
  Init_(time_per_frame, total_frames, std::nullopt, frame_order);
}
TimedAnimationController::TimedAnimationController(
  double time_per_frame,
  uint32_t total_frames,
  uint32_t repeats,
  std::vector<uint32_t> frame_order
) {
  Init_(time_per_frame, total_frames, repeats, frame_order);
}

void TimedAnimationController::Init_(
  double time_per_frame,
  uint32_t total_frames,
  std::optional<uint32_t> repeats,
  std::optional<std::vector<uint32_t>> frame_order
) {
  time_per_frame_ = time_per_frame;

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

  unique_frames_ =
    *std::max_element(frame_order_.begin(), frame_order_.end()) + 1;

  active = true;
  timer_.Restart();
}

void TimedAnimationController::Restart() { timer_.Restart(); }

void TimedAnimationController::Tick() {
  if (active) {
    if (timer_.GetElapsedTime() < time_per_frame_) {
    } else {
      timer_.Restart(time_per_frame_ - timer_.GetElapsedTime());
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
            current_frame_ = max_frames_ - 1;
            current_repeat_ = max_repeats_.value() - 1;
            active = false;
          }
        }
      }
    }
  }
}
[[nodiscard]] uint32_t TimedAnimationController::Frame() const {
  return frame_order_[current_frame_];
}

[[nodiscard]] uint32_t TimedAnimationController::TotalFrames() const {
  return max_frames_;
}

[[nodiscard]] uint32_t TimedAnimationController::UniqueFrames() const {
  return unique_frames_;
}

[[nodiscard]] std::string TimedAnimationController::as_string() const {

  return fmt::format(
    "{}\n{}\n{}",
    fmt::format(
      "Duration: {}s | Current Subframe: {}",
      time_per_frame_,
      timer_.GetElapsedTime()
    ),
    fmt::format(
      "Total Frames: {} | Current Frame: {}", max_frames_, current_frame_
    ),
    fmt::format(
      "Total Repeats: {} times | Current Repeat: {}",
      max_repeats_ == std::nullopt ? "unlimited" :
                                     std::to_string(max_repeats_.value()),
      current_repeat_
    )
  );
}

} // namespace nge