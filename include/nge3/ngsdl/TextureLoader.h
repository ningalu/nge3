#ifndef NGE3_NGSDL_TEXTURELOADER_H
#define NGE3_NGSDL_TEXTURELOADER_H

#include <string>

#include "SDL2/SDL.h"

#include "Renderer.h"
#include "Texture.h"

namespace nge::sdl {
class TextureLoader {
public:
  // SDL_CreateTexture
  static SDL_Texture *CreateTexture(const Renderer &renderer, Uint32 format,
                                    int access, int w, int h);

  // SDL_CreateTextureFromSurface

  // IMG_LoadTexture
  static SDL_Texture *LoadTexture(const Renderer &renderer,
                                  const std::string &filename);

  // IMG_LoadTexture_RW

  // IMG_LoadTextureTyped_RW

protected:
private:
};
} // namespace nge::sdl

#endif