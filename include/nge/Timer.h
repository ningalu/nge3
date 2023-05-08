#ifndef NGE3_NGE_TIMER_H
#define NGE3_NGE_TIMER_H

#include <chrono>

namespace nge {
class Timer {
public:
  Timer();
  Timer(double timescale);

  void Restart() noexcept;
  [[nodiscard]] long double GetElapsedTime() const noexcept;
  [[nodiscard]] double GetTimescale() const noexcept;
  void SetTimescale(double timescale) noexcept;

protected:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_;
  double timescale_;
};
} // namespace nge

#endif