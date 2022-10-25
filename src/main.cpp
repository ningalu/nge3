#include <iostream>

#include "BlendMode.h"
#include "Events/Event.hpp"
#include "Events/EventQueue.h"
#include "Events/EventVisitor.hpp"
#include "Events/Scancode.h"
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

  SDL_Init(SDL_INIT_EVERYTHING);

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

    sdl::Point pos = {50, 50};

    SDL_Event buf;
    bool running = true;
    bool dragging = false;
    sdl::Timer frames, events;
    while (running) {

      if (dragging) {
        pos = w.GetMousePos();
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
end:

  SDL_Quit();

  return 0;
}