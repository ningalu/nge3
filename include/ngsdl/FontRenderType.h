#ifndef NGE3_NGSDL_FONTRENDERTYPE_H
#define NGE3_NGSDL_FONTRENDERTYPE_H

#include <SDL2/SDL_ttf.h>

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