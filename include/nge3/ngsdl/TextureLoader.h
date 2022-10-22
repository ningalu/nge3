#ifndef NGE3_NGSDL_TEXTURELOADER_H
#define NGE3_NGSDL_TEXTURELOADER_H

#include "SDL2/SDL.h"

#include "Renderer.h"
#include "Texture.h"

namespace nge::sdl {
class TextureLoader {
public:
  static SDL_Texture *CreateTexture(Renderer &renderer, Uint32 format,
                                    int access, int w, int h);

protected:
private:
};
} // namespace nge::sdl

#endif