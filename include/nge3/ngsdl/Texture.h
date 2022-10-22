#ifndef NGE3_NGSDL_TEXTURE_H
#define NGE3_NGSDL_TEXTURE_H

#include <memory>

#include "SDL2/SDL.h"

#include "Rectangle.h"

namespace nge::sdl {
class Renderer;
class Texture {
  friend class Renderer;
  friend SDL_Texture *CreateTexture(Renderer &renderer, Uint32 format,
                                    int access, int w, int h);

public:
  Texture(Renderer &renderer, Uint32 format, int access, int w, int h);

protected:
  Uint32 format_;
  int access_;
  int w_;
  int h_;
  std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture_;

private:
};
} // namespace nge::sdl

#endif