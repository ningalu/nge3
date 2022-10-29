#ifndef NGE3_NGE3_APP_H
#define NGE3_NGE3_APP_H

#include <memory>
#include <stack>

namespace nge {
class View;

namespace sdl {

class Window;
class Renderer;
} // namespace sdl
} // namespace nge

namespace nge {

class App {
public:
  App();

  void SetInitialView(View *v);
  void SetInitialView(std::unique_ptr<View> v);

  void Run();

  ~App();

protected:
  std::shared_ptr<sdl::Window> window_;
  std::shared_ptr<sdl::Renderer> renderer_;

  std::stack<std::unique_ptr<View>> view_stack_;

  bool running_;
};
} // namespace nge

#endif