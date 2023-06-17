#include <cstdlib>
#include <experimental/mdspan>
#include <iostream>

#include "fmt/format.h"

#include "ngsdl/BlendMode.h"
#include "ngsdl/Events/Event.hpp"
#include "ngsdl/Events/EventQueue.h"
#include "ngsdl/Events/EventVisitor.hpp"
#include "ngsdl/Events/Scancode.h"
#include "ngsdl/Font.h"
#include "ngsdl/FontRenderType.h"
#include "ngsdl/Init.h"
#include "ngsdl/InitFlags.h"
#include "ngsdl/Point.h"
#include "ngsdl/Rectangle.h"
#include "ngsdl/Renderer.h"
#include "ngsdl/RendererFlags.h"
#include "ngsdl/RendererFlip.h"
#include "ngsdl/SDLException.h"
#include "ngsdl/Surface.h"
#include "ngsdl/Texture.h"
#include "ngsdl/Timer.h"
#include "ngsdl/Window.h"
#include "ngsdl/WindowFlags.h"

int main(int argc, char **argv) {

  using namespace nge;

  // sdl::Rectangle r(1, 2, 3, 4);
  // std::cout << r << "\n";
  // sdl::Point p(5, 6);
  // std::cout << p << "\n";

  std::vector<sdl::Point> shape = {
    {0, 0}, {50, 0}, {50, 10}, {30, 80}, {20, 80}, {40, 20}, {0, 10}, {0, 0}};

  nge::sdl::Init();

  try {
    sdl::Window w;
    std::cout << sdl::EventQueue::GetKeyboardState().size() << "\n";

    auto r = sdl::Renderer{
      w,
      -1,
      sdl::RendererFlags::ACCELERATED | sdl::RendererFlags::TARGETTEXTURE};

    sdl::Texture t = {r, "./resources/parrot.jpg"};
    try {
      auto blend = t.GetBlendMode();
      std::cout << blend << "\n";
      t.SetBlendMode(sdl::BlendMode::ADD);
      blend = t.GetBlendMode();
      std::cout << blend << "\n";
      t.SetBlendMode(sdl::BlendMode::NONE);
      blend = t.GetBlendMode();
      std::cout << blend << "\n";
    } catch (std::exception &e) {
      std::cout << e.what() << "\n";
    }

    sdl::Font font{"./resources/Fonts/pokemon_pixel_font.ttf", 72};

    sdl::Texture text1{
      r,
      sdl::Surface::TextSolid(
        font, "font test", sdl::Colour{216, 191, 216, 255}
      )};

    sdl::Texture text2 =
      font.CreateShadedTexture(r, "shaded", {0, 255, 0, 255}, {0, 0, 255, 255});

    auto s = sdl::Surface::RGB(255, 255);

    sdl::Timer tex_timer;
    tex_timer.Restart();
    for (int i = 0; i < 10; i++) {
      volatile sdl::Texture t_{r, s};
    }
    std::cout << fmt::format(
      "100 surface to texture took {0} ms\n ", tex_timer.GetTicks()
    );

    std::cout << fmt::format(
      "extent 1: {0}, extent 2: {1}, size: {2}",
      s->Pixels().extent(0),
      s->Pixels().extent(1),
      sizeof(s->Pixels())
    ) << "\n";

    // i is row, j is column
    for (auto i = 0; i < s->Pixels().extent(0); i++) {
      for (auto j = 0; j < s->Pixels().extent(1); j++) {
        // s->Pixels()(i, j) = sdl::Colour{
        //   static_cast<uint8_t>(std::rand() % 256),
        //   static_cast<uint8_t>(std::rand() % 256),
        //   static_cast<uint8_t>(std::rand() % 256),
        //   255};
        s->Pixels(i, j) =
          sdl::Colour{static_cast<uint8_t>(i), static_cast<uint8_t>(j), 0, 255};
      }
    }
    // for (auto i = 0; i < 10; i++) {
    //   for (auto j = 0; j < 10; i++) {
    //     s->Pixels()(i, j) = sdl::Colour{255, 0, 0, 255};
    //   }
    // }

    sdl::Texture t3{r, s};

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
        // std::cout << frames.GetTicks() << "\n";
        frames.Restart();
        r.Clear();
        r.CopyEx(
          t,
          std::nullopt,
          nge::sdl::Rectangle{pos, std::tuple<int32_t, int32_t>{550, 550}},
          5.0,
          std::nullopt,
          sdl::RendererFlip::HORIZONTAL | sdl::RendererFlip::VERTICAL
        );
        r.Copy(text1, std::nullopt, {500, 500, text1.GetW(), text1.GetH()});
        r.Copy(text2, std::nullopt, {600, 600, text2.GetW(), text2.GetH()});
        // for (auto i = 0; i < s->Pixels().extent(0); i++) {
        //   for (auto j = 0; j < s->Pixels().extent(1); j++) {
        //     s->Pixels()(i, j) = sdl::Colour{
        //       static_cast<uint8_t>(std::rand() % 256),
        //       static_cast<uint8_t>(std::rand() % 256),
        //       static_cast<uint8_t>(std::rand() % 256),
        //       255};
        //   }
        // }
        auto t4 = sdl::Texture{r, s};
        r.Copy(
          t4, std::nullopt, sdl::Rectangle{700, 700, t3.GetW(), t3.GetH()}
        );
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
              default:
                break;
              }
            },
            [&](const sdl::MouseUpEvent &event) {
              std::cout << event.GetTimestamp() << " Mouse Up Event\n";
              switch (event.GetButton()) {
              case sdl::MouseButton::LEFT:
                dragging = false;
                break;
              default:
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
              default:
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
  } catch (std::exception &e) {
    std::cout << e.what() << "\n";
  }

  nge::sdl::Quit();

  return 0;
}