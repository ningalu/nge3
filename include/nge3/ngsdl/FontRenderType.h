#ifndef NGE3_NGSDL_FONTRENDERTYPE_H
#define NGE3_NGSDL_FONTRENDERTYPE_H

#pragma warning(push, 0)
#include "SDL2/SDL_ttf.h"
#pragma warning(pop)

namespace nge::sdl {
enum class FontRenderType {
  BLENDED,
  SHADED,
  SOLID,
  // conan doesn't have SDL_ttf 2.20
  // LCD
};
}

#endif