#ifndef NGSDL_FONTRENDERTYPE_H
#define NGSDL_FONTRENDERTYPE_H

#include <SDL2/SDL_ttf.h>

namespace nge::sdl {
enum class FontRenderType { BLENDED, SHADED, SOLID, LCD };
}

#endif