#include "nge/Timer.h"

namespace nge {
Timer::Timer() : timescale_(1.0) {
  start_ = std::chrono::high_resolution_clock::now();
}
Timer::Timer(double timescale) : timescale_(timescale) {
  start_ = std::chrono::high_resolution_clock::now();
}
long double Timer::GetElapsedTime() const noexcept {
  return static_cast<std::chrono::duration<double>>(
           std::chrono::high_resolution_clock::now() - start_
  )
    .count();
}

void Timer::Restart() noexcept {
  start_ = std::chrono::high_resolution_clock::now();
}

[[nodiscard]] double Timer::GetTimescale() const noexcept { return timescale_; }
void Timer::SetTimescale(double timescale) noexcept { timescale_ = timescale; }
} // namespace nge