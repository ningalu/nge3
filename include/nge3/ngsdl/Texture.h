#ifndef NGE3_NGSDL_TEXTURE_H
#define NGE3_NGSDL_TEXTURE_H

#include <memory>

#include "SDL2/SDL.h"

#include "Rectangle.h"
#include "Renderer.h"

namespace nge::sdl {
class Texture {
public:
  Texture(std::shared_ptr<Renderer> renderer, Uint32 format, int access, int w,
          int h);
  void Draw(const Rectangle &src, const Rectangle &dst);

protected:
  std::shared_ptr<Renderer> renderer_;
  std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture_;

private:
};
} // namespace nge::sdl

#endif