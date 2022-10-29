#ifndef NGE3_NGE_GRAPHICS_H
#define NGE3_NGE_GRAPHICS_H

#include <string>

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

  void Render();

protected:
  sdl::Window window_;
  sdl::Renderer renderer_;
};
} // namespace nge

#endif