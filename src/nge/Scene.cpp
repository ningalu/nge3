#include "nge/Scene.h"

#include <algorithm>
#include <iostream>

#include "nge/Graphics.h"
#include "nge/Input.h"

#include "nge/Components/Clickable.h"
#include "nge/Components/Drawable.h"
#include "nge/Components/Mouse/Hoverable.h"

namespace nge {
Scene::Scene() /* : draw_queue_(&Drawable::CompareDrawPriority) */ {}

void Scene::Init() {}
void Scene::Teardown() {}
// Viewport should always be initialised to some actual value
// I wonder if the compiler can see through this
[[nodiscard]] const std::optional<sdl::Rect> &Scene::GetViewport() const {
  return viewport_;
}
void Scene::SetViewport(const sdl::Rect &viewport) {
  viewport_ = viewport;
  graphics_->SetWindowPos({viewport_->GetX(), viewport_->GetY()});
  graphics_->SetWindowSize(viewport_->GetW(), viewport_->GetH());
}
[[nodiscard]] std::tuple<int, int> Scene::GetSize() const {
  return {viewport_->GetW(), viewport_->GetH()};
}
[[nodiscard]] sdl::Point Scene::GetPos() const {
  return {viewport_->GetX(), viewport_->GetY()};
}

void Scene::SetGraphics(const std::shared_ptr<Graphics> &graphics) noexcept {
  graphics_ = graphics;
}
void Scene::SetInput(const std::shared_ptr<Input> &input) noexcept {
  input_ = input;
}

void Scene::RegisterDrawable(std::shared_ptr<Drawable> d) {
  draw_queue_.push_back(d);
  std::sort(
    draw_queue_.begin(), draw_queue_.end(), &Drawable::CompareDrawPriority
  );
}

void Scene::RegisterClickable(std::shared_ptr<Clickable> d) {
  click_queue_.push_back(d);
}

void Scene::RegisterHoverable(std::shared_ptr<Hoverable> h) {
  hover_queue_.push_back(h);
}

void Scene::RenderQueue() {
  for (const auto &d : draw_queue_) {
    d->Draw();
  }
}

void Scene::ClickMouseQueue(sdl::MouseButton m) {
  for (const auto &c : click_queue_) {
    c->Click(m);
  }
}

void Scene::HoldMouseQueue(sdl::MouseButton m) {
  for (const auto &c : click_queue_) {
    c->Hold(m);
  }
}
void Scene::ReleaseMouseQueue(sdl::MouseButton m) {
  for (const auto &c : click_queue_) {
    c->Release(m);
  }
}

void Scene::HoverQueue() {
  for (auto &h : hover_queue_) {
    if (h->Hovering() && !h->PrevHovering()) {
      h->OnStartHover();
    }
    if (h->Hovering() && h->PrevHovering()) {
      h->OnHoldHover();
    }
    if (!h->Hovering() && h->PrevHovering()) {
      h->OnReleaseHover();
    }
  }
}

} // namespace nge