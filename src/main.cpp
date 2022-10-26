#include <iostream>

#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include "BlendMode.h"
#include "Events/Event.hpp"
#include "Events/EventQueue.h"
#include "Events/EventVisitor.hpp"
#include "Events/Scancode.h"
#include "nge3/ngsdl/Font.h"
#include "nge3/ngsdl/FontRenderType.h"
#include "nge3/ngsdl/Point.h"
#include "nge3/ngsdl/Rectangle.h"
#include "nge3/ngsdl/Renderer.h"
#include "nge3/ngsdl/RendererFlags.h"
#include "nge3/ngsdl/RendererFlip.h"
#include "nge3/ngsdl/SDLException.h"
#include "nge3/ngsdl/Texture.h"
#include "nge3/ngsdl/Timer.h"
#include "nge3/ngsdl/Window.h"
#include "nge3/ngsdl/WindowFlags.h"

int main(int argc, char **argv) {

  using namespace nge;

  sdl::Rect r(1, 2, 3, 4);
  std::cout << r << "\n";
  sdl::Point p(5, 6);
  std::cout << p << "\n";

  std::vector<sdl::Point> shape = {
    {0, 0}, {50, 0}, {50, 10}, {30, 80}, {20, 80}, {40, 20}, {0, 10}, {0, 0}};

  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
  TTF_Init();

  try {
    sdl::Window w;
    std::cout << w.GetKeyboardState().size() << "\n";

    auto r = sdl::Renderer{
      w,
      -1,
      sdl::RendererFlags::ACCELERATED | sdl::RendererFlags::TARGETTEXTURE};

    sdl::Texture t = {r, "./resources/parrot.jpg"};
    auto blend = t.GetBlendMode();
    std::cout << blend << "\n";
    t.SetBlendMode(sdl::BlendMode::ADD);
    blend = t.GetBlendMode();
    std::cout << blend << "\n";
    t.SetBlendMode(sdl::BlendMode::NONE);
    blend = t.GetBlendMode();
    std::cout << blend << "\n";

    sdl::Font font{"./resources/pokemon_pixel_font.ttf", 72};

    sdl::Texture text1{
      r,
      font,
      "font test",
      sdl::FontRenderType::SOLID,
      sdl::Colour{216, 191, 216, 255}};

    sdl::Texture text2 = font.CreateShadedTexture(
      r, "shaded", {0, 255, 0, 255}, {0, 0, 255, 255}
    );

    sdl::Point pos = {50, 50};

    SDL_Event buf;
    bool running = true;
    bool dragging = false;
    sdl::Timer frames, events;
    while (running) {

      if (dragging) {
        pos = w.GetMousePos() - sdl::Point{t.GetW() / 2, t.GetH() / 2};
      }

      if (frames.GetTicks() > (1000 / 60)) {
        frames.Restart();
        r.Clear();
        r.CopyEx(
          t,
          std::nullopt,
          {pos, {550, 550}},
          5.0,
          std::nullopt,
          sdl::RendererFlip::HORIZONTAL | sdl::RendererFlip::VERTICAL
        );
        r.Copy(text1, std::nullopt, {500, 500, text1.GetW(), text1.GetH()});
        r.Copy(text2, std::nullopt, {600, 600, text2.GetW(), text2.GetH()});
        r.SetDrawColor(255, 0, 0, 255);
        r.DrawLine({0, 0}, {600, 50});
        r.SetDrawColor(0, 0, 255, 255);
        r.DrawLines(shape);
        r.SetDrawColor(0, 255, 0, 255);
        r.DrawRect({40, 40, 100, 100});
        r.SetDrawColor(0, 255, 255, 255);
        r.FillRect({150, 50, 100, 100});
        r.SetDrawColor(255, 255, 255, 255);
        r.Present();
      }

      if (events.GetTicks() > (1000 / 1000)) {
        events.Restart();
        std::optional<sdl::Event> buffer = sdl::EventQueue::Poll();

        while (buffer != std::nullopt) {

          buffer->Visit(sdl::EventVisitor{
            [](auto v) {
            },
            [&](const sdl::KeyUpEvent &event) {
              std::cout << event.GetTimestamp() << " Key Up Event\n";
              switch (event.GetKeySym().GetScancode()) {
              case sdl::Scancode::ESCAPE:
                running = false;
                break;
              }
            },
            [&](const sdl::MouseUpEvent &event) {
              std::cout << event.GetTimestamp() << " Mouse Up Event\n";
              switch (event.GetButton()) {
              case sdl::MouseButton::LEFT:
                dragging = false;
                break;
              }
            },
            [&](const sdl::MouseDownEvent &event) {
              std::cout << event.GetTimestamp() << " Mouse Down Event\n";
              pos = event.GetPos();
              switch (event.GetButton()) {
              case sdl::MouseButton::LEFT:
                dragging = true;
                break;
              }
            },
            [&](const sdl::KeyDownEvent &event) {
              std::cout << event.GetTimestamp() << " Key Down Event\n";
            },
            [&](const sdl::QuitEvent &event) {
              std::cout << event.GetTimestamp() << " Quit\n";
              running = false;
            }});

          buffer = sdl::EventQueue::Poll();
        }
      }
    }
  } catch (sdl::SDLException &e) {
    std::cout << e.what() << "\n";
  }

  TTF_Quit();
  IMG_Quit();
  SDL_Quit();

  return 0;
}