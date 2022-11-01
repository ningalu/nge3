#ifndef NGE3_NGE_GRAPHICS_H
#define NGE3_NGE_GRAPHICS_H

#include <string>
#include <tuple>

#include "ngsdl/Rectangle.h"
#include "ngsdl/Renderer.h"
#include "ngsdl/RendererFlags.h"
#include "ngsdl/Window.h"
#include "ngsdl/WindowFlags.h"

namespace nge {
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

  void Render();

  void SetWindowSize(int w, int h);
  void SetWindowSize(const std::tuple<int, int> &size);
  std::tuple<int, int> GetWindowSize() const;

  void SetWindowPos(int x, int y);
  void SetWindowPos(sdl::Point pos);
  sdl::Point GetWindowPos() const;

protected:
  sdl::Window window_;
  sdl::Renderer renderer_;
};
} // namespace nge

#endif