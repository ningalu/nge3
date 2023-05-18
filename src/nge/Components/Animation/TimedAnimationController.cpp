#include "nge/Components/Animation/TimedAnimationController.h"

#include <string>

#include "fmt/format.h"

namespace nge {

TimedAnimationController::TimedAnimationController(
  double time_per_frame, uint32_t total_frames, std::optional<uint32_t> repeats
) {
  time_per_frame_ = time_per_frame;

  max_frames_ = total_frames;
  current_frame_ = 0;

  max_repeats_ = repeats;
  current_repeat_ = 0;

  active = true;
  timer_.Restart();
}

void TimedAnimationController::Tick() {
  if (active) {
    if (timer_.GetElapsedTime() < time_per_frame_) {
    } else {
      timer_.Restart();
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
  return current_frame_;
}

[[nodiscard]] uint32_t TimedAnimationController::TotalFrames() const {
  return max_frames_;
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