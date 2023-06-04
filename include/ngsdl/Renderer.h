#ifndef NGSDL_RENDERER_H
#define NGSDL_RENDERER_H

#include <cstdint>
#include <memory>
#include <optional>
#include <vector>

#include <SDL2/SDL.h>

#include "Color.h"
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
  Renderer(const Renderer &) = delete;
  Renderer &operator=(const Renderer &) = delete;
  Renderer(const Window &window);
  Renderer(const Window &window, int index, RendererFlags flags);

  // SDL_GetRenderDrawBlendMode

  // SDL_GetRenderDrawColor
  Color GetDrawColor() const;
  void SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
  void SetDrawColor(Color c);

  // SDL_GetRendererInfo

  // SDL_GetRendererOutputSize

  // SDL_GetRendererTarget
  void SetTarget(const Texture &texture);
  void SetTarget(const Window &window);

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
  void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
  void DrawLine(const Point &p1, const Point &p2);

  // SDL_RenderDrawLines
  void DrawLines(const std::vector<Point> &points);

  // SDL_RenderDrawPoint
  void DrawPoint(int32_t x, int32_t y);
  void DrawPoint(const Point &p);

  // SDL_RenderDrawPoints

  // SDL_RenderDrawRect
  void DrawRect(const Rectangle &r);

  // SDL_RenderDrawRects

  // SDL_RenderFillRect
  void FillRect(const Rectangle &r);
  void FillRect(const Rectangle *r);

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