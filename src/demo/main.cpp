#include <iostream>

#include "demo/IntroScene.h"
#include "nge/App.h"
#include "nge/Scene.h"
#include "nge/SceneFactory.hpp"

#include "ngsdl/SDLException.h"
#include "ngsdl/TTFException.h"

int main(int argc, char **argv) {
  try {
    nge::App app = {"test app", {50, 50, 800, 600}};
    std::cout << SDL_GetBasePath() << "\n";
    auto initial = app.GetSceneFactory()->Create<demo::IntroScene>();

    app.SetInitialView(std::move(initial));
    app.Run();

  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  std::cout << "App closed successfully\n";
  return 0;
}