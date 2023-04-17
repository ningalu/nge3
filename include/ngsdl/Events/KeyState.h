#ifndef NGE3_NGSDL_EVENTS_KEYSTATE_H
#define NGE3_NGSDL_EVENTS_KEYSTATE_H

#include <SDL2/SDL.h>

namespace nge::sdl {

enum class KeyState { PRESSED = SDL_PRESSED, RELEASED = SDL_RELEASED };
}

#endif