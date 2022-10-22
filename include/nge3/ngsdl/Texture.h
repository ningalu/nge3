#ifndef NGE3_NGSDL_TEXTURE_H
#define NGE3_NGSDL_TEXTURE_H

#include <memory>
#include <string>

#include "SDL2/SDL.h"

#include "Rectangle.h"

namespace nge::sdl {
class Renderer;
class TextureLoader;
class Texture {
  friend class Renderer;
  friend class TextureLoader;

public:
  Texture(const Renderer &renderer, Uint32 format, int access, int w, int h);
  Texture(const Renderer &renderer, std::string filename);

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