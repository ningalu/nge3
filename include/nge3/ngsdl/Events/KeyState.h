#ifndef NGE3_NGSDL_EVENTS_KEYSTATE_H
#define NGE3_NGSDL_EVENTS_KEYSTATE_H

#pragma warning(push, 0)
#include "SDL2/SDL.h"
#pragma warning(pop)

namespace nge::sdl {

enum class KeyState { PRESSED = SDL_PRESSED, RELEASED = SDL_RELEASED };
}

#endif