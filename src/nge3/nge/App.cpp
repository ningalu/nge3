#include "nge/App.h"

#include <optional>

#pragma warning(push, 0)
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#pragma warning(pop)

#include "ngsdl/Events/Event.hpp"
#include "ngsdl/Events/EventQueue.h"
#include "ngsdl/Renderer.h"
#include "ngsdl/SDLException.h"
#include "ngsdl/TTFException.h"
#include "ngsdl/Window.h"

#include "nge/Graphics.h"
#include "nge/View.h"

#include <iostream>

namespace nge {
App::App() {
  Init();
  graphics_ = std::make_shared<Graphics>();
  fps_ = 60;
  tps_ = 1000;
}

App::App(const std::string &name, sdl::Rect viewport) {
  Init();
  graphics_ = std::make_shared<Graphics>(
    name,
    viewport,
    sdl::WindowFlags::OPENGL,
    sdl::RendererFlags::ACCELERATED | sdl::RendererFlags::TARGETTEXTURE
  );
  fps_ = 60;
  tps_ = 1000;
}

void App::SetInitialView(View *v) {
  std::unique_ptr<View> initial_view;
  initial_view.reset(v);
  view_stack_.push(std::move(initial_view));
}

void App::SetInitialView(std::unique_ptr<View> v) {
  view_stack_.push(std::move(v));
}

std::shared_ptr<Graphics> App::GetGraphics() const { return graphics_; }

void App::Run() {
  running_ = true;
  while (running_) {
    if (tps_timer_.GetElapsedTime() > (static_cast<long double>(1) / static_cast<long double>(tps_))) {
      tps_timer_.Restart();
      auto e = sdl::EventQueue::Poll();
      while (e != std::nullopt) {
        e->Visit(sdl::EventVisitor{
          [](const sdl::DefaultEvent &) {
          },
          [&](const sdl::QuitEvent &) {
            running_ = false;
          }});
        e = sdl::EventQueue::Poll();
      }
    }
    if (fps_timer_.GetElapsedTime() > (static_cast<long double>(1) / static_cast<long double>(fps_))) {
      fps_timer_.Restart();
      view_stack_.top()->Render();
      graphics_->Render();
    }
  }
}

void App::Init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    throw sdl::SDLException("SDL couldn't be initialised");
  }
  // IMG_Init is cringe and uses 0 as a failure code
  if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0) {
    throw sdl::SDLException("SDL_image couldn't be initialised");
  }
  if (TTF_Init() != 0) {
    throw sdl::TTFException("SDL_ttf couldn't be initialised");
  }
}

App::~App() {
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}
} // namespace nge