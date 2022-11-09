#include "nge3/demo/IntroView.h"

#include <iostream>

#include "nge3/nge/Graphics.h"
#include "nge3/nge/Input.h"

namespace demo {
IntroView::IntroView(
  const std::shared_ptr<nge::Graphics> &graphics,
  const std::shared_ptr<nge::Input> &input
)
    : nge::View(graphics, input) {
  viewport_ = {50, 50, 1200, 900};
  among_us_ = {graphics_, "resources/parrot.jpg"};
  among_us_.SetScale(1.0);
  among_us_.SetPos({50, 50});
  f_ = std::make_shared<nge::sdl::Font>(
    std::string{SDL_GetBasePath()} + "resources/pokemon_pixel_font.ttf", 72
  );
  among_us_text_ = nge::Text{graphics_, f_, "parrot", {255, 0, 0, 255}};
  among_us_text_.SetPos({25, 25});
}

void IntroView::Render() {
  among_us_.Draw();
  among_us_text_.Draw();
}
void IntroView::Tick() {
  if (input_->KeyPressed(nge::sdl::Scancode::SPACE)) {
    std::cout << "space pressed from IntroView\n";
  }
}
} // namespace demo