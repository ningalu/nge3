#ifndef NGE3_NGE3_APP_H
#define NGE3_NGE3_APP_H

#include <memory>

namespace nge::sdl {
class Window;
class Renderer;
} // namespace nge::sdl

namespace nge {
class App {
public:
  App();

  ~App();

protected:
  std::shared_ptr<sdl::Window> window_;
  std::shared_ptr<sdl::Renderer> renderer_;
};
} // namespace nge

#endif