#include "demo/IntroView.h"

#include <iostream>

#include "nge/Graphics.h"
#include "nge/Input.h"

#include "ngsdl/Events/MouseButton.h"

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
  among_us_pos_ = {50.0, 50.0};

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
  if (input_->KeyDown(nge::sdl::Scancode::SPACE)) {
    std::get<0>(among_us_pos_) += 0.1;
    std::get<1>(among_us_pos_) += 0.1;
    among_us_.SetPos(
      {static_cast<int>(std::get<0>(among_us_pos_)),
       static_cast<int>(std::get<1>(among_us_pos_))}
    );
  }
  if (input_->MouseClicked(nge::sdl::MouseButton::LEFT)) {
    std::cout << "left click\n";
  }
  if (input_->MouseHeld(nge::sdl::MouseButton::LEFT)) {
    std::cout << "left held\n";
  }
  if (input_->MouseReleased(nge::sdl::MouseButton::LEFT)) {
    std::cout << "left release\n";
  }
}
} // namespace demo