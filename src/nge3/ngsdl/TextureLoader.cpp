#include "TextureLoader.h"

#include "SDLException.h"

namespace nge::sdl {
SDL_Texture *TextureLoader::CreateTexture(Renderer &renderer, Uint32 format,
                                          int access, int w, int h) {
  SDL_Texture *t =
      SDL_CreateTexture(renderer.renderer_.get(), format, access, w, h);
  if (t == nullptr) {
    throw SDLException("Texture couldn't be created");
  } else {
    return t;
  }
}
} // namespace nge::sdl