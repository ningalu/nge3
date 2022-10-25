#ifndef NGE3_NGSDL_RENDERER_H
#define NGE3_NGSDL_RENDERER_H

#include <memory>
#include <optional>

#include "SDL2/SDL.h"

#include "RendererFlags.h"
#include "RendererFlip.h"
#include "Texture.h"
#include "Window.h"

namespace nge::sdl {
class Renderer {
  friend class Texture;

public:
  Renderer(const Window &window);
  Renderer(const Window &window, int index, RendererFlags flags);

  void Clear();
  void Present();
  void Copy(
    const Texture &texture,
    const std::optional<Rectangle> &src,
    const Rectangle &dst
  );

  void CopyEx(
    const Texture &texture,
    const std::optional<Rectangle> &src,
    const Rectangle &dst,
    const double angle,
    const std::optional<Point> &center,
    const RendererFlip flip
  );

  void SetTarget(Texture texture);
  void SetTarget(Window window);

protected:
  std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer_;

private:
};
} // namespace nge::sdl

#endif