#include "nge/App.h"

#include <bitset>
#include <iostream>
#include <optional>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "ngsdl/Events/Event.hpp"
#include "ngsdl/Events/EventQueue.h"
#include "ngsdl/Init.h"
#include "ngsdl/Renderer.h"
#include "ngsdl/SDLException.h"
#include "ngsdl/TTFException.h"
#include "ngsdl/Window.h"

#include "nge/Graphics.h"
#include "nge/Input.h"
#include "nge/Scene.h"
#include "nge/SceneFactory.hpp"
#include "nge/SceneManager.h"

#include <iostream>

namespace nge {

App::App(const std::string &name, sdl::Rect viewport) {
  sdl::Init();
  input_ = std::make_shared<Input>();
  graphics_ = std::make_shared<Graphics>(
    name,
    viewport,
    sdl::WindowFlags::OPENGL,
    sdl::RendererFlags::ACCELERATED | sdl::RendererFlags::TARGETTEXTURE
  );
  scene_manager_ = std::make_shared<SceneManager>(graphics_, input_);
  scene_fact_
    = std::make_shared<nge::SceneFactory>(graphics_, input_, scene_manager_);
  fps_ = 60;
  tps_ = 1000;
}

void App::SetInitialView(Scene *v) {
  std::shared_ptr<Scene> initial_view;
  initial_view.reset(v);
  SetInitialView(std::move(initial_view));
}

void App::SetInitialView(std::shared_ptr<Scene> v) {
  graphics_->SetWindowSize(v->GetSize());
  graphics_->SetWindowPos(v->GetPos());
  // view_stack_.push(std::move(v));
  scene_manager_->PushScene(v);
}

std::shared_ptr<SceneFactory> App::GetSceneFactory() { return scene_fact_; }
std::shared_ptr<Graphics> App::GetGraphics() const { return graphics_; }
std::shared_ptr<Input> App::GetInput() const { return input_; }

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

      input_->Update();

      std::shared_ptr<Scene> &current_scene = scene_manager_->GetCurrentScene();

      current_scene->HoverQueue();

      for (auto m : input_->AllMouseClicked()) {
        current_scene->ClickMouseQueue(m);
      }
      for (auto m : input_->AllMouseHeld()) {
        current_scene->HoldMouseQueue(m);
      }
      for (auto m : input_->AllMouseReleased()) {
        current_scene->ReleaseMouseQueue(m);
      }

      current_scene->Tick();
    }
    if (fps_timer_.GetElapsedTime() > (static_cast<long double>(1) / static_cast<long double>(fps_))) {

      fps_timer_.Restart();

      graphics_->Clear();

      std::shared_ptr<Scene> &current_scene = scene_manager_->GetCurrentScene();

      current_scene->RenderQueue();
      current_scene->Render();

      graphics_->Render();
    }
  }
}

App::~App() {
  // i forgot why this needs to be destroyed in such a specific order
  scene_manager_->Quit();
  sdl::Quit();
}
} // namespace nge