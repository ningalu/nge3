#include <iostream>

#include "BlendMode.h"
#include "Events/Event.h"
#include "Events/EventQueue.h"
#include "nge3/ngsdl/Point.h"
#include "nge3/ngsdl/Rectangle.h"
#include "nge3/ngsdl/Renderer.h"
#include "nge3/ngsdl/RendererFlags.h"
#include "nge3/ngsdl/SDLException.h"
#include "nge3/ngsdl/Texture.h"
#include "nge3/ngsdl/Window.h"
#include "nge3/ngsdl/WindowFlags.h"

template <class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

int main(int argc, char **argv) {

  using namespace nge;

  sdl::Rect r(1, 2, 3, 4);
  std::cout << r << "\n";
  sdl::Point p(5, 6);
  std::cout << p << "\n";

  SDL_Init(SDL_INIT_EVERYTHING);
  try {
    sdl::Window w;
    auto r = sdl::Renderer{w, -1,
                           sdl::RendererFlags::ACCELERATED |
                               sdl::RendererFlags::TARGETTEXTURE};

    sdl::Texture t = {r, "./resources/parrot.jpg"};
    auto blend = t.GetBlendMode();
    std::cout << blend << "\n";
    t.SetBlendMode(sdl::BlendMode::ADD);
    blend = t.GetBlendMode();
    std::cout << blend << "\n";
    t.SetBlendMode(sdl::BlendMode::NONE);
    blend = t.GetBlendMode();
    std::cout << blend << "\n";

    SDL_Event buf;
    bool running = true;
    while (running) {
      r.Clear();
      r.Copy(t, std::nullopt, {50, 50, 550, 550});
      r.Present();
      // while (SDL_PollEvent(&buf)) {
      //   switch (buf.type) {
      //   case SDL_QUIT:
      //     goto end;
      //   }
      // }
      std::optional<sdl::Event> buffer = sdl::EventQueue::Poll();
      while (buffer != std::nullopt) {

        std::visit(overloaded{[](auto v) {},
                              [&](sdl::QuitEvent event) {
                                std::cout << "Quit\n";
                                running = false;
                              }},
                   buffer->GetEventData());
        buffer = sdl::EventQueue::Poll();
      }
    }
  } catch (sdl::SDLException &e) {
    std::cout << e.what() << "\n";
  }
end:

  SDL_Quit();

  return 0;
}