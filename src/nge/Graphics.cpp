#include "nge/Graphics.h"

namespace nge {
Graphics::Graphics()
    : renderer_(window_), background_colour_{255, 255, 255, 255} {}
Graphics::Graphics(
  const std::string &name,
  sdl::Rectangle viewport,
  sdl::WindowFlags window_flags,
  sdl::RendererFlags renderer_flags
)
    : window_(name, viewport, window_flags),
      renderer_(window_, -1, renderer_flags),
      background_colour_{255, 255, 255, 255} {}

const sdl::Renderer &Graphics::GetRenderer() const { return renderer_; }

void Graphics::Render() { renderer_.Present(); }
void Graphics::Draw(const sdl::Rectangle dst) { renderer_.FillRect(dst); }
void Graphics::Draw(const sdl::Rectangle dst, sdl::Colour colour) {
  renderer_.SetDrawColor(colour);
  renderer_.FillRect(dst);
  renderer_.SetDrawColor(background_colour_);
}
void Graphics::Draw(const sdl::Rectangle *dst) { renderer_.FillRect(dst); }
void Graphics::Draw(const sdl::Rectangle *dst, sdl::Colour colour) {
  renderer_.SetDrawColor(colour);
  renderer_.FillRect(dst);
  renderer_.SetDrawColor(background_colour_);
}
void Graphics::Draw(
  const sdl::Texture &texture,
  const std::optional<sdl::Rectangle> src,
  const sdl::Rectangle dst,
  const double angle,
  const std::optional<sdl::Point> center,
  const sdl::RendererFlip flip
) {
  renderer_.CopyEx(texture, src, dst, angle, center, flip);
}
void Graphics::Clear() { renderer_.Clear(); }

void Graphics::SetWindowSize(int w, int h) { window_.SetSize(w, h); }
void Graphics::SetWindowSize(const std::tuple<int, int> &size) {
  window_.SetSize(std::get<0>(size), std::get<1>(size));
}

std::tuple<int, int> Graphics::GetWindowSize() const {
  return window_.GetSize();
}

void Graphics::SetWindowPos(int x, int y) { window_.SetPosition({x, y}); }

void Graphics::SetWindowPos(sdl::Point pos) { window_.SetPosition(pos); }

sdl::Point Graphics::GetWindowPos() const { return window_.GetPosition(); }

} // namespace nge