#ifndef NGE3_NGSDL_TIMER_H
#define NGE3_NGSDL_TIMER_H

#pragma warning(push, 0)
#include "SDL2/SDL.h"
#pragma warning(pop)

namespace nge::sdl {
class Timer {
public:
  Timer();

  void Restart();
  Uint64 GetTicks() const;

protected:
  Uint64 start_tick_;
};
} // namespace nge::sdl

#endif