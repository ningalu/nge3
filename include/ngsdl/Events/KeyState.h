#ifndef NGSDL_EVENTS_KEYSTATE_H
#define NGSDL_EVENTS_KEYSTATE_H

#include <SDL2/SDL.h>

namespace nge::sdl {

enum class KeyState { PRESSED = SDL_PRESSED, RELEASED = SDL_RELEASED };
}

#endif