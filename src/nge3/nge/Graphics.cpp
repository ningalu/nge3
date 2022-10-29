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
} // namespace nge