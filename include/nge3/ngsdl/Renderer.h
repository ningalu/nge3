#ifndef NGE3_NGSDL_RENDERER_H
#define NGE3_NGSDL_RENDERER_H

#include <memory>
#include <optional>
#include <vector>

#include "SDL2/SDL.h"

#include "RendererFlags.h"
#include "RendererFlip.h"
#include "Texture.h"
#include "Window.h"

namespace nge::sdl {
class Font;
class Renderer {
  friend class Texture;
  friend class Font;

public:
  Renderer(const Window &window);
  Renderer(const Window &window, int index, RendererFlags flags);

  // SDL_GetRenderDrawBlendMode

  // SDL_GetRenderDrawColor
  std::tuple<Uint8, Uint8, Uint8, Uint8> GetDrawColor() const;
  void SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

  // SDL_GetRendererInfo

  // SDL_GetRendererOutputSize

  // SDL_GetRendererTarget
  void SetTarget(Texture texture);
  void SetTarget(Window window);

  // SDL_RenderClear
  void Clear();

  // SDL_RenderCopy
  void Copy(
    const Texture &texture,
    const std::optional<Rectangle> &src,
    const Rectangle &dst
  );

  // SDL_RenderCopyEx
  void CopyEx(
    const Texture &texture,
    const std::optional<Rectangle> &src,
    const Rectangle &dst,
    const double angle,
    const std::optional<Point> &center,
    const RendererFlip flip
  );

  // SDL_RenderDrawLine
  void DrawLine(int x1, int y1, int x2, int y2);
  void DrawLine(const Point &p1, const Point &p2);

  // SDL_RenderDrawLines
  void DrawLines(const std::vector<Point> &points);

  // SDL_RenderDrawPoint
  void DrawPoint(int x, int y);
  void DrawPoint(const Point &p);

  // SDL_RenderDrawPoints

  // SDL_RenderDrawRect
  void DrawRect(const Rectangle &r);

  // SDL_RenderDrawRects

  // SDL_RenderFillRect
  void FillRect(const Rectangle &r);

  // SDL_RenderFillRects

  // SDL_RenderGetClipRect

  // SDL_RenderGetIntegerScale

  // SDL_RenderGetLogicalSize

  // SDL_RenderGetScale

  // SDL_RenderGetViewport

  // SDL_RenderIsClipEnabled

  // SDL_RenderPresent
  void Present();

  // SDL_RenderReadPixels

  // SDL_RenderSetClipRect

  // SDL_RenderSetIntegerScale

  // SDL_RenderSetLogicalSize

  // SDL_RenderSetScale

  // SDL_RenderSetViewport

  // SDL_RenderTargetSupported

protected:
  std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer_;

private:
};
} // namespace nge::sdl

#endif