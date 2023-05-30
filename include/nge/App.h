#ifndef NGE3_NGE_APP_H
#define NGE3_NGE_APP_H

#include <memory>
#include <stack>
#include <string>

#include "nge/Timer.h"

#include "ngsdl/Rectangle.h"

namespace nge {
class Scene;
class Graphics;
class Input;
class SceneManager;
class SceneFactory;

namespace sdl {

class Window;
class Renderer;
} // namespace sdl
} // namespace nge

namespace nge {

class App {
public:
  App(
    const std::string &name = "DEFAULT APP NAME",
    sdl::Rectangle viewport = sdl::Rectangle{0, 0, 800, 600}
  );

  void SetInitialView(Scene *v);
  void SetInitialView(std::shared_ptr<Scene> v);

  std::shared_ptr<SceneFactory> GetSceneFactory();

  std::shared_ptr<Graphics> GetGraphics() const;
  std::shared_ptr<Input> GetInput() const;

  void Run();

  ~App();

protected:
  std::shared_ptr<Graphics> graphics_;
  std::shared_ptr<Input> input_;
  std::shared_ptr<SceneManager> scene_manager_;
  std::shared_ptr<SceneFactory> scene_fact_;

  bool running_;
  int fps_, tps_;
  Timer fps_timer_, tps_timer_;
};
} // namespace nge

#endif