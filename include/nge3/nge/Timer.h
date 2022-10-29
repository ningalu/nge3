#ifndef NGE3_NGE3_TIMER_H
#define NGE3_NGE3_TIMER_H

#include <chrono>

namespace nge {
class Timer {
public:
  Timer();

  void Restart();
  long double GetElapsedTime() const;

protected:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_;
};
} // namespace nge

#endif