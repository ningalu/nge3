#ifndef NGE3_NGE_TIMER_H
#define NGE3_NGE_TIMER_H

#include <chrono>

namespace nge {
class Timer {
public:
  Timer();
  Timer(double timescale);

  void Restart() noexcept;
  void Restart(double offset) noexcept;
  [[nodiscard]] double GetElapsedTime() const noexcept;
  [[nodiscard]] double GetTimescale() const noexcept;
  void SetTimescale(double timescale) noexcept;

protected:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_;
  double timescale_;
  double offset_;
};
} // namespace nge

#endif