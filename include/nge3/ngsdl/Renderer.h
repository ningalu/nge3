#ifndef NGE3_NGSDL_RENDERER_H
#define NGE3_NGSDL_RENDERER_H

#include <memory>

#include "SDL2/SDL.h"

#include "Window.h"

namespace nge::sdl {
class Texture;
class Renderer {
  friend class Texture;

public:
  Renderer(const Window &window);

  void Clear();
  void Present();

protected:
  std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer_;

private:
};
} // namespace nge::sdl

#endif