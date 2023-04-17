#ifndef NGE3_NGSDL_EVENTS_MOUSEBUTTON
#define NGE3_NGSDL_EVENTS_MOUSEBUTTON

#include <SDL2/SDL.h>

namespace nge::sdl {
enum class MouseButton {
  LEFT = SDL_BUTTON_LEFT,
  RIGHT = SDL_BUTTON_RIGHT,
  MIDDLE = SDL_BUTTON_MIDDLE,
  X1 = SDL_BUTTON_X1,
  X2 = SDL_BUTTON_X2
};
MouseButton operator|(MouseButton lhs, MouseButton rhs);
bool operator&(MouseButton lhs, MouseButton rhs);
} // namespace nge::sdl

#endif