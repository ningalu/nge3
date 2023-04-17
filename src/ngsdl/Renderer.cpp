#include "ngsdl/Renderer.h"

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
  SDL_Renderer *renderer = SDL_CreateRenderer(
    window.window_.get(), index, static_cast<Uint32>(flags)
  );

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

void Renderer::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
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
  src.has_value() ?
    SDL_RenderCopy(
      renderer_.get(), texture.texture_.get(), &src->rect_, &dst.rect_
    ) :
    SDL_RenderCopy(
      renderer_.get(), texture.texture_.get(), nullptr, &dst.rect_
    );
}
void Renderer::CopyEx(
  const Texture &texture,
  const std::optional<Rectangle> &src,
  const Rectangle &dst,
  const double angle,
  const std::optional<Point> &center,
  const RendererFlip flip
) {
  SDL_RenderCopyEx(
    renderer_.get(),
    texture.texture_.get(),
    src == std::nullopt ? nullptr : &src->rect_,
    &dst.rect_,
    angle,
    center == std::nullopt ? nullptr : &center->point_,
    static_cast<SDL_RendererFlip>(flip)
  );
}

void Renderer::DrawLine(int x1, int y1, int x2, int y2) {
  SDL_RenderDrawLine(renderer_.get(), x1, y1, x2, y2);
}
void Renderer::DrawLine(const Point &p1, const Point &p2) {
  DrawLine(p1.GetX(), p1.GetY(), p2.GetX(), p2.GetY());
}

// this is not ideal
// i dont think creating a new collection here is avoidable without maybe
// creating collection classes for these wrappers that maintains the list of
// wrapped objects as well
// maybe i can hijack the specialisation of the std::vector<Point> constructor
// maybe look into custom allocators for vector
// maybe hard cap the number of points so it can be statically allocated each
// function call
void Renderer::DrawLines(const std::vector<Point> &points) {
  std::vector<SDL_Point> sdl_points;
  sdl_points.reserve(points.size());
  for (auto it : points) {
    sdl_points.push_back(it.point_);
  }
  SDL_RenderDrawLines(
    renderer_.get(), sdl_points.data(), static_cast<int>(sdl_points.size())
  );
}

void Renderer::DrawPoint(int x, int y) {
  SDL_RenderDrawPoint(renderer_.get(), x, y);
}
void Renderer::DrawPoint(const Point &p) { DrawPoint(p.GetX(), p.GetY()); }

void Renderer::DrawRect(const Rectangle &r) {
  SDL_RenderDrawRect(renderer_.get(), &r.rect_);
}

void Renderer::FillRect(const Rectangle &r) {
  SDL_RenderFillRect(renderer_.get(), &r.rect_);
}

} // namespace nge::sdl