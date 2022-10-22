#ifndef NGE3_NGSDL_RENDERER_H
#define NGE3_NGSDL_RENDERER_H

#include <memory>

#include "SDL2/SDL.h"

#include "RendererFlags.h"
#include "Texture.h"
#include "Window.h"

namespace nge::sdl {
class TextureLoader;
class Renderer {
  friend class TextureLoader;

public:
  Renderer(const Window &window);
  Renderer(const Window &window, int index, RendererFlags flags);

  void Clear();
  void Present();
  void Copy(const Texture &texture, const Rectangle &src, const Rectangle &dst);

protected:
  std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer_;

private:
};
} // namespace nge::sdl

#endif