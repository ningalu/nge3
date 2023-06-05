#include "ngsdl/Renderer.h"

#include <bit>
#include <cstdint>
#include <iostream>

#include "ngsdl/RendererFlags.h"
#include "ngsdl/SDLException.h"

namespace nge::sdl {
Renderer::Renderer(const Window &window)
    : renderer_(nullptr, SDL_DestroyRenderer) {
  SDL_Renderer *renderer = SDL_CreateRenderer(
    window.window_.get(),
    -1,
    static_cast<int>(RendererFlags::ACCELERATED)
      | static_cast<int>(RendererFlags::TARGETTEXTURE)
  );

  if (renderer == nullptr) {
    throw SDLException("Renderer couldn't be constructed");
  } else {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    renderer_.reset(renderer);
  }
}

Renderer::Renderer(const Window &window, int index, RendererFlags flags)
    : renderer_(nullptr, SDL_DestroyRenderer) {
  SDL_Renderer *renderer =
    SDL_CreateRenderer(window.window_.get(), index, static_cast<Uint32>(flags));

  if (renderer == nullptr) {
    throw SDLException("Renderer couldn't be constructed");
  } else {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    renderer_.reset(renderer);
  }
}

void Renderer::SetTarget(const Texture &texture) {
  SDL_SetRenderTarget(renderer_.get(), texture.texture_.get());
}
void Renderer::SetTarget([[maybe_unused]] const Window &window) {
  SDL_SetRenderTarget(renderer_.get(), nullptr);
}

Color Renderer::GetDrawColor() const {
  Uint8 r, g, b, a;
  SDL_GetRenderDrawColor(renderer_.get(), &r, &g, &b, &a);
  return {r, g, b, a};
}

void Renderer::SetDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  if (SDL_SetRenderDrawColor(renderer_.get(), r, g, b, a) != 0) {
    throw SDLException("Render Draw Colour couldn't be set");
  }
}

void Renderer::SetDrawColor(Color c) {
  auto [r, g, b, a] = c.GetColors();
  SetDrawColor(r, g, b, a);
}

void Renderer::Clear() { SDL_RenderClear(renderer_.get()); }

void Renderer::Present() { SDL_RenderPresent(renderer_.get()); }

void Renderer::Copy(
  const Texture &texture,
  const std::optional<Rectangle> &src,
  const Rectangle &dst
) {
  // how do you get ternary statements to clang-format nicely?
  if (src.has_value()) {
    SDL_RenderCopy(
      renderer_.get(),
      texture.texture_.get(),
      std::bit_cast<SDL_Rect *>(&src),
      std::bit_cast<SDL_Rect *>(&dst)
    );
  } else {
    SDL_RenderCopy(
      renderer_.get(),
      texture.texture_.get(),
      nullptr,
      std::bit_cast<SDL_Rect *>(&dst)
    );
  }
}
void Renderer::CopyEx(
  const Texture &texture,
  const std::optional<Rectangle> &src,
  const Rectangle dst,
  const double angle,
  const std::optional<Point> &center,
  const RendererFlip flip
) {
  SDL_RenderCopyEx(
    renderer_.get(),
    texture.texture_.get(),
    src == std::nullopt ? nullptr : std::bit_cast<SDL_Rect *>(&src),
    std::bit_cast<SDL_Rect *>(&dst),
    angle,
    center == std::nullopt ? nullptr :
                             std::bit_cast<SDL_Point *>(&center.value()),
    static_cast<SDL_RendererFlip>(flip)
  );
}

void Renderer::DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  SDL_RenderDrawLine(renderer_.get(), x1, y1, x2, y2);
}
void Renderer::DrawLine(Point p1, Point p2) {
  DrawLine(p1.X(), p1.Y(), p2.X(), p2.Y());
}
void Renderer::DrawLine(const Point *p1, const Point *p2) {
  DrawLine(p1->X(), p1->Y(), p2->X(), p2->Y());
}

void Renderer::DrawLines(const std::vector<Point> &points) {
  SDL_RenderDrawLines(
    renderer_.get(),
    std::bit_cast<SDL_Point *>(points.data()),
    static_cast<int>(points.size())
  );
}

void Renderer::DrawPoint(int32_t x, int32_t y) {
  SDL_RenderDrawPoint(renderer_.get(), x, y);
}
void Renderer::DrawPoint(Point p) { DrawPoint(p.X(), p.Y()); }
void Renderer::DrawPoint(const Point *p) { DrawPoint(p->X(), p->Y()); }

void Renderer::DrawPoints(const std::vector<Point> &points) {
  SDL_RenderDrawPoints(
    renderer_.get(), std::bit_cast<SDL_Point *>(points.data()), points.size()
  );
}

void Renderer::DrawRect(const Rectangle &r) {
  SDL_RenderDrawRect(renderer_.get(), std::bit_cast<SDL_Rect *>(&r));
}

void Renderer::FillRect(const Rectangle &r) {
  SDL_RenderFillRect(renderer_.get(), std::bit_cast<SDL_Rect *>(&r));
}
void Renderer::FillRect(const Rectangle *r) {
  SDL_RenderFillRect(renderer_.get(), std::bit_cast<SDL_Rect *>(&r));
}

void Renderer::FillRects(const std::vector<Rectangle> &rects) {
  SDL_RenderFillRects(
    renderer_.get(),
    std::bit_cast<SDL_Rect *>(rects.data()),
    static_cast<int>(rects.size())
  );
}

[[nodiscard]] std::tuple<float, float> Renderer::RenderScale() const {
  float x, y;
  SDL_RenderGetScale(renderer_.get(), &x, &y);
  return std::tuple<float, float>{x, y};
}
[[nodiscard]] float Renderer::XRenderScale() const {
  float x;
  SDL_RenderGetScale(renderer_.get(), &x, nullptr);
  return x;
}
[[nodiscard]] float Renderer::YRenderScale() const {
  float y;
  SDL_RenderGetScale(renderer_.get(), nullptr, &y);
  return y;
}
void Renderer::SetRenderScale(float x, float y) {
  SDL_RenderSetScale(renderer_.get(), x, y);
}
void Renderer::SetRenderScale(std::tuple<float, float> scale) {
  SDL_RenderSetScale(renderer_.get(), std::get<0>(scale), std::get<1>(scale));
}
void Renderer::SetXRenderScale(float x) const {
  SDL_RenderSetScale(renderer_.get(), x, YRenderScale());
}
void Renderer::SetYRenderScale(float y) const {
  SDL_RenderSetScale(renderer_.get(), XRenderScale(), y);
}
} // namespace nge::sdl