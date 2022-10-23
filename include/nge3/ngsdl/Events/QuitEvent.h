#ifndef NGE3_NGSDL_EVENTS_QUITEVENT_H
#define NGE3_NGSDL_EVENTS_QUITEVENT_H

#include "SDL2/SDL.h"

namespace nge::sdl {
class QuitEvent {
public:
  QuitEvent() = default;
  QuitEvent(Uint32 timestamp);

  Uint32 GetTimestamp() const;

protected:
  Uint32 timestamp_;

private:
};
} // namespace nge::sdl

#endif