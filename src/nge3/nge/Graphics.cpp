#include "nge/Graphics.h"

namespace nge {
Graphics::Graphics() : renderer_(window_) {}
Graphics::Graphics(
  const std::string &name,
  sdl::Rectangle viewport,
  sdl::WindowFlags window_flags,
  sdl::RendererFlags renderer_flags
)
    : window_(name, viewport, window_flags),
      renderer_(window_, -1, renderer_flags) {}

void Graphics::Render() { renderer_.Present(); }

void Graphics::SetWindowSize(int w, int h) { window_.SetSize(w, h); }

std::tuple<int, int> Graphics::GetWindowSize() const {
  return window_.GetSize();
}

void Graphics::SetWindowPos(int x, int y) { window_.SetPosition({x, y}); }

void Graphics::SetWindowPos(sdl::Point pos) { window_.SetPosition(pos); }

sdl::Point Graphics::GetWindowPos() const { return window_.GetPosition(); }

} // namespace nge