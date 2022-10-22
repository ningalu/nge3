#include "TextureLoader.h"

#include "SDL2/SDL_image.h"

#include "SDLException.h"

namespace nge::sdl {
SDL_Texture *TextureLoader::CreateTexture(const Renderer &renderer,
                                          Uint32 format, int access, int w,
                                          int h) {
  SDL_Texture *t =
      SDL_CreateTexture(renderer.renderer_.get(), format, access, w, h);
  if (t == nullptr) {
    throw SDLException("Texture couldn't be created");
  } else {
    return t;
  }
}

SDL_Texture *TextureLoader::LoadTexture(const Renderer &renderer,
                                        const std::string &filename) {
  SDL_Texture *t = IMG_LoadTexture(renderer.renderer_.get(), filename.c_str());
  if (t == nullptr) {
    throw SDLException("Texture couldn't be created");
  } else {
    return t;
  }
}
} // namespace nge::sdl