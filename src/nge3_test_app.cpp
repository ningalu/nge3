#include <iostream>

#include "nge3/nge/App.h"
#include "nge3/nge/View.h"

#include "nge3/ngsdl/SDLException.h"
#include "nge3/ngsdl/TTFException.h"

int main(int argc, char **argv) {
  try {
    nge::App app = {"test app", {50, 50, 800, 600}};
    app.SetInitialView(new nge::View(app.GetGraphics()));
    app.Run();

  } catch (const std::exception &e) {
    std::cout << e.what();
  }
  std::cout << "lol\n";
  return 0;
}