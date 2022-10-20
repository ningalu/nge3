#ifndef NGE3_NGSDL_RENDERER_H
#define NGE3_NGSDL_RENDERER_H

#include <memory>

#include "SDL2/SDL.h"

#include "Window.h"

namespace nge::sdl {
class Renderer {

public:
  Renderer(const Window &window);

  void Present();

protected:
  std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer_;

private:
};
} // namespace nge::sdl

#endif