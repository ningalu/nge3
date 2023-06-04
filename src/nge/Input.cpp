#include "nge/Input.h"

#include <cstring>
#include <iostream>

#include "ngsdl/Events/Event.hpp"
#include "ngsdl/Events/EventQueue.h"
#include "ngsdl/Events/EventVisitor.hpp"
#include "ngsdl/Events/MouseButtonMask.h"
#include "ngsdl/Events/Scancode.h"

namespace nge {
Input::Input() : current_input_({0}), prev_input_({0}) {}

void Input::Update() {
  std::memcpy(prev_input_.data(), current_input_.data(), prev_input_.size());
  prev_mouse_ = current_mouse_;
  prev_mouse_pos_ = mouse_pos_;

  auto kb = sdl::EventQueue::GetKeyboardState();
  for (std::size_t i = 0; i < 512; i++) {
    current_input_[i] = kb[i];
  }
  auto [mouse, point] = sdl::EventQueue::GetMouseState();
  current_mouse_ = mouse;
  mouse_pos_ = point;
}

[[nodiscard]] bool Input::KeyDown(const sdl::Scancode key) const {
  return static_cast<bool>(current_input_.at(static_cast<uint32_t>(key)));
}
[[nodiscard]] bool Input::KeyUp(const sdl::Scancode key) const {
  return !KeyDown(key);
}

[[nodiscard]] bool Input::KeyPressed(const sdl::Scancode key) const {
  return (current_input_.at(static_cast<uint32_t>(key)))
         && !(prev_input_.at(static_cast<uint32_t>(key)));
}
[[nodiscard]] bool Input::KeyHeld(const sdl::Scancode key) const {
  return (current_input_.at(static_cast<uint32_t>(key)))
         && (prev_input_.at(static_cast<uint32_t>(key)));
}
[[nodiscard]] bool Input::KeyReleased(const sdl::Scancode key) const {
  return !(current_input_.at(static_cast<uint32_t>(key)))
         && (prev_input_.at(static_cast<uint32_t>(key)));
}

// fine with these for now, but could definitely be smarter and have Scenes
// check for what keys they actually need to respond to

[[nodiscard]] std::vector<sdl::Scancode> Input::AllKeysPressed() const {
  std::vector<sdl::Scancode> out;

  // keeps for loop on one line lol
  using i32 = uint32_t;
  using nge::sdl::Scancode;

  for (int i = 0; i < static_cast<i32>(Scancode::CARDINAL_SCANCODE); i++) {
    if (KeyPressed(static_cast<Scancode>(i))) {
      out.push_back(static_cast<Scancode>(i));
    }
  }
  return out;
}

[[nodiscard]] std::vector<sdl::Scancode> Input::AllKeysHeld() const {
  std::vector<sdl::Scancode> out;

  using i32 = uint32_t;
  using nge::sdl::Scancode;

  for (int i = 0; i < static_cast<i32>(Scancode::CARDINAL_SCANCODE); i++) {
    if (KeyHeld(static_cast<Scancode>(i))) {
      out.push_back(static_cast<Scancode>(i));
    }
  }
  return out;
}

[[nodiscard]] std::vector<sdl::Scancode> Input::AllKeysReleased() const {
  std::vector<sdl::Scancode> out;

  using i32 = uint32_t;
  using nge::sdl::Scancode;

  for (int i = 0; i < static_cast<i32>(Scancode::CARDINAL_SCANCODE); i++) {
    if (KeyReleased(static_cast<Scancode>(i))) {
      out.push_back(static_cast<Scancode>(i));
    }
  }
  return out;
}

[[nodiscard]] bool Input::MouseDown(const sdl::MouseButton button) const {
  return current_mouse_ & static_cast<uint32_t>(button);
}
[[nodiscard]] bool Input::MouseUp(const sdl::MouseButton button) const {
  return !MouseDown(button);
}

[[nodiscard]] bool Input::MouseClicked(const sdl::MouseButton button) const {
  return (current_mouse_ & static_cast<uint32_t>(sdl::Mask(button)))
         && !(prev_mouse_ & static_cast<uint32_t>(sdl::Mask(button)));
}
[[nodiscard]] bool Input::MouseHeld(const sdl::MouseButton button) const {
  return (current_mouse_ & static_cast<uint32_t>(sdl::Mask(button)))
         && (prev_mouse_ & static_cast<uint32_t>(sdl::Mask(button)));
}
[[nodiscard]] bool Input::MouseReleased(const sdl::MouseButton button) const {
  return !(current_mouse_ & static_cast<uint32_t>(sdl::Mask(button)))
         && (prev_mouse_ & static_cast<uint32_t>(sdl::Mask(button)));
}

// passing methods was annoying
[[nodiscard]] std::vector<sdl::MouseButton> Input::AllMouseClicked() const {
  return MouseInteraction_([&](const sdl::MouseButton m) {
    return MouseClicked(m);
  });
}
[[nodiscard]] std::vector<sdl::MouseButton> Input::AllMouseHeld() const {
  return MouseInteraction_([&](const sdl::MouseButton m) {
    return MouseHeld(m);
  });
}
[[nodiscard]] std::vector<sdl::MouseButton> Input::AllMouseReleased() const {
  return MouseInteraction_([&](const sdl::MouseButton m) {
    return MouseReleased(m);
  });
}

[[nodiscard]] int32_t Input::MouseX() const { return mouse_pos_.X(); }
[[nodiscard]] int32_t Input::MouseY() const { return mouse_pos_.Y(); }
[[nodiscard]] sdl::Point Input::MousePos() const { return mouse_pos_; }

[[nodiscard]] int32_t Input::PrevMouseX() const { return prev_mouse_pos_.X(); }
[[nodiscard]] int32_t Input::PrevMouseY() const { return prev_mouse_pos_.Y(); }
[[nodiscard]] sdl::Point Input::PrevMousePos() const { return prev_mouse_pos_; }

[[nodiscard]] inline std::vector<sdl::MouseButton> Input::MouseInteraction_(
  std::function<bool(sdl::MouseButton)> f
) const {
  std::vector<sdl::MouseButton> t;
  for (auto m : Input::MOUSE_BUTTONS) {
    if (f(m)) {
      t.push_back(m);
    }
  }
  return t;
}

} // namespace nge