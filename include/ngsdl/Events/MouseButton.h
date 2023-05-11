#ifndef NGSDL_EVENTS_MOUSEBUTTON
#define NGSDL_EVENTS_MOUSEBUTTON

#include <SDL2/SDL.h>

namespace nge::sdl {
enum class MouseButton : uint8_t {
  LEFT = SDL_BUTTON_LEFT,
  MIDDLE = SDL_BUTTON_MIDDLE,
  RIGHT = SDL_BUTTON_RIGHT,
  X1 = SDL_BUTTON_X1,
  X2 = SDL_BUTTON_X2
};
MouseButton operator|(MouseButton lhs, MouseButton rhs);
bool operator&(MouseButton lhs, MouseButton rhs);
} // namespace nge::sdl

#endif