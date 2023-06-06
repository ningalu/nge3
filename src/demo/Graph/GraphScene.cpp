#include "demo/Graph/GraphScene.h"

#include <algorithm>
#include <utility>
#include <vector>

static std::vector<nge::sdl::Point> curve1, curve2;
static std::vector<nge::sdl::Rectangle> drawn1, drawn2;
static std::vector<nge::sdl::Point> points1, points2;
namespace demo {
void GraphScene::Setup() {
  viewport_ = nge::sdl::Rectangle{100, 100, 1200, 900};

  curve1 = {};
  curve2 = {};
  drawn1 = {};
  drawn2 = {};
  points1 = {};
  points2 = {};

  auto fn = [](int32_t x) {
    return x * x;
  };
  for (auto i = -100; i < 100; i++) {
    curve1.push_back(nge::sdl::Point{i, fn(i)});
    curve2.push_back(nge::sdl::Point{
      (i * 6) + 600,
      static_cast<int32_t>(std::sin(static_cast<double>(i) / 25.0) * 300) + 450}
    );
  }
  for (auto &p : curve1) {
    p.SetX(p.X() + 600);
    p.SetY(p.Y() + 450);
  }
  for (auto i = 0; i < curve1.size() - 1; i++) {
    nge::sdl::Rectangle r;
    r.SetX(std::min(curve1[i].X(), curve1[i + 1].X()));
    r.SetY(std::min(curve1[i].Y(), curve1[i + 1].Y()));
    r.SetW(std::abs(curve1[i].X() - curve1[i + 1].X()));
    r.SetH(std::abs(curve1[i].Y() - curve1[i + 1].Y()));
    // graphics_->Draw(curve[i], curve[i + 1]);
    r.SetX(r.X() - 1);
    r.SetY(r.Y() - 1);
    r.SetW(r.W() + 3);
    r.SetH(r.H() + 3);
    drawn1.push_back(r);
  }
  for (auto i = 0; i < curve2.size() - 1; i++) {
    nge::sdl::Rectangle r;
    r.SetX(std::min(curve2[i].X(), curve2[i + 1].X()));
    r.SetY(std::min(curve2[i].Y(), curve2[i + 1].Y()));
    r.SetW(std::abs(curve2[i].X() - curve2[i + 1].X()));
    r.SetH(std::abs(curve2[i].Y() - curve2[i + 1].Y()));
    if (r.W() < 10) {
      r.SetW(10);
    }
    if (r.H() < 10) {
      r.SetH(10);
    }
    // graphics_->Draw(curve[i], curve[i + 1]);
    r.SetX(r.X() - 1);
    r.SetY(r.Y() - 1);
    r.SetW(r.W() + 3);
    r.SetH(r.H() + 3);
    drawn2.push_back(r);
  }
}
void GraphScene::Render() {
  graphics_->SetFillColour(nge::sdl::Color{50, 50, 50, 255});
  graphics_->Draw(
    nge::sdl::Point{0, viewport_->H() / 2},
    nge::sdl::Point{viewport_->W(), viewport_->H() / 2}
  );
  graphics_->Draw(
    nge::sdl::Point{viewport_->W() / 2, 0},
    nge::sdl::Point{viewport_->W() / 2, viewport_->H()}
  );

  graphics_->Draw(drawn1, nge::sdl::Color{0, 0, 255, 255});
  graphics_->Draw(drawn2, nge::sdl::Color{0, 255, 0, 255});
  graphics_->ResetFillColour();
}

void GraphScene::Tick() {
  if (input_->KeyPressed(nge::sdl::Scancode::ESCAPE)) {
    scene_manager_->PopScene();
  }
}
} // namespace demo