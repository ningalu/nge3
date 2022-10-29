#ifndef NGE3_NGE_APP_H
#define NGE3_NGE_APP_H

#include <memory>
#include <stack>

#include "nge/Timer.h"

namespace nge {
class View;
class Graphics;
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
  std::shared_ptr<Graphics> graphics_;

  std::stack<std::unique_ptr<View>> view_stack_;

  bool running_;
  int fps_, tps_;
  Timer fps_timer_, tps_timer_;
};
} // namespace nge

#endif