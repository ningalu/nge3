#ifndef NGE3_NGE_GRAPHICS_H
#define NGE3_NGE_GRAPHICS_H

#include <string>
#include <tuple>
#include <vector>

#include "ngsdl/Rectangle.h"
#include "ngsdl/Renderer.h"
#include "ngsdl/RendererFlags.h"
#include "ngsdl/Window.h"
#include "ngsdl/WindowFlags.h"

namespace nge {

namespace sdl {
class Texture;
}

class Graphics {
public:
  Graphics();
  Graphics(
    const std::string &name,
    sdl::Rectangle viewport,
    sdl::WindowFlags window_flags,
    sdl::RendererFlags renderer_flags
  );

  Graphics(const Graphics &) = delete;
  Graphics &operator=(const Graphics &) = delete;

  const sdl::Renderer &GetRenderer() const;

  void Render();

  void Draw(sdl::Point p);
  void Draw(const sdl::Point *p);
  void Draw(const std::vector<sdl::Point> &points);

  void Draw(sdl::Point p1, sdl::Point p2);
  void Draw(const sdl::Point *p1, const sdl::Point *p2);

  void Draw(const sdl::Rectangle dst);
  void Draw(const sdl::Rectangle dst, sdl::Colour colour);
  void Draw(const sdl::Rectangle *dst);
  void Draw(const sdl::Rectangle *dst, sdl::Colour colour);
  void Draw(const std::vector<sdl::Rectangle> &rects);
  void Draw(const std::vector<sdl::Rectangle> &rects, sdl::Colour colour);

  void Draw(
    const sdl::Texture &texture,
    const std::optional<sdl::Rectangle> src,
    const sdl::Rectangle dst,
    const double angle = 0,
    const std::optional<sdl::Point> center = std::nullopt,
    const sdl::RendererFlip flip = sdl::RendererFlip::NONE
  );

  void Clear();

  void SetWindowSize(int w, int h);
  void SetWindowSize(const std::tuple<int, int> &size);
  std::tuple<int, int> GetWindowSize() const;

  void SetWindowPos(int x, int y);
  void SetWindowPos(sdl::Point pos);
  sdl::Point GetWindowPos() const;

  void SetFillColour(nge::sdl::Colour c);
  void ResetFillColour();

protected:
  sdl::Window window_;
  sdl::Renderer renderer_;
  sdl::Colour background_colour_;
};
} // namespace nge

#endif