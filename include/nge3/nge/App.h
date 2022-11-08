#ifndef NGE3_NGE_APP_H
#define NGE3_NGE_APP_H

#include <memory>
#include <stack>
#include <string>

#include "nge/Timer.h"
#include "ngsdl/Rectangle.h"

namespace nge {
class View;
class Graphics;
class Input;
namespace sdl {

class Window;
class Renderer;
} // namespace sdl
} // namespace nge

namespace nge {

class App {
public:
  App();
  App(const std::string &name, sdl::Rect viewport);

  void SetInitialView(View *v);
  void SetInitialView(std::unique_ptr<View> v);

  std::shared_ptr<Graphics> GetGraphics() const;

  void Run();

  ~App();

protected:
  std::shared_ptr<Graphics> graphics_;
  std::shared_ptr<Input> input_;

  std::stack<std::unique_ptr<View>> view_stack_;

  bool running_;
  int fps_, tps_;
  Timer fps_timer_, tps_timer_;

  void Init();
};
} // namespace nge

#endif