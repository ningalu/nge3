#ifndef NGSDL_INIT_H
#define NGSDL_INIT_H

#include "ngsdl/InitFlags.h"

namespace nge::sdl {

void InitSDL(SDLInitFlags f);
void InitIMG(IMGInitFlags f);
void InitTTF();

void Init(
  SDLInitFlags s = SDLInitFlags::EVERYTHING, IMGInitFlags i = IMGInitFlags::ALL
);

void QuitSDL() noexcept;
void QuitIMG() noexcept;
void QuitTTF() noexcept;
void Quit() noexcept;
} // namespace nge::sdl

#endif