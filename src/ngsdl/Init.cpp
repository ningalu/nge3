#include "ngsdl/Init.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "ngsdl/SDLException.h"
#include "ngsdl/TTFException.h"

namespace nge::sdl {

void InitSDL(SDLInitFlags f) {
  if (SDL_Init(static_cast<uint32_t>(f)) != 0) {
    throw SDLException("SDL couldn't be initialised");
  };
}
void InitIMG(IMGInitFlags f) {
  // why does SDL image in particular have a different error scheme than
  // everything else
  if (IMG_Init(static_cast<uint32_t>(f)) == 0) {
    throw SDLException("SDL_image couldn't be initialised");
  }
}
void InitTTF() {
  if (TTF_Init() != 0) {
    throw TTFException("TTF couldn't be initialised");
  }
}

void Init(SDLInitFlags s, IMGInitFlags i) {
  InitSDL(s);
  InitIMG(i);
  InitTTF();
}

void QuitSDL() noexcept { SDL_Quit(); }
void QuitIMG() noexcept { IMG_Quit(); }
void QuitTTF() noexcept { TTF_Quit(); }
void Quit() noexcept {
  QuitTTF();
  QuitIMG();
  QuitSDL();
}
} // namespace nge::sdl