#include "nge/Timer.h"

namespace nge {
Timer::Timer() { start_ = std::chrono::high_resolution_clock::now(); }

long double Timer::GetElapsedTime() const {
  return static_cast<std::chrono::duration<double>>(
           std::chrono::steady_clock::now() - start_
  )
    .count();
}

void Timer::Restart() { start_ = std::chrono::high_resolution_clock::now(); }
} // namespace nge