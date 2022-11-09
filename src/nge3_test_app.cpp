#include <iostream>

#include "nge3/demo/IntroView.h"
#include "nge3/nge/App.h"
#include "nge3/nge/View.h"

#include "nge3/ngsdl/SDLException.h"
#include "nge3/ngsdl/TTFException.h"

int main(int argc, char **argv) {
  try {
    nge::App app = {"test app", {50, 50, 800, 600}};
    std::cout << SDL_GetBasePath() << "\n";
    app.SetInitialView(new demo::IntroView(app.GetGraphics(), app.GetInput()));
    app.Run();

  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  std::cout << "App closed successfully\n";
  return 0;
}