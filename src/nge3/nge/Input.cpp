#include "nge3/nge/Input.h"

#include <iostream>

#include "nge3/ngsdl/Events/Event.hpp"
#include "nge3/ngsdl/Events/EventQueue.h"
#include "nge3/ngsdl/Events/EventVisitor.hpp"
#include "nge3/ngsdl/Events/Scancode.h"

namespace nge {
Input::Input() : current_input_({0}), prev_input_({0}) {}

void Input::Update() {
  prev_input_ = current_input_;
  prev_mouse_ = current_mouse_;

  auto kb = sdl::EventQueue::GetKeyboardState();
  for (std::size_t i = 0; i < 512; i++) {
    current_input_[i] = kb[i];
  }
  auto [mouse, point] = sdl::EventQueue::GetMouseState();
  current_mouse_ = mouse;
  mouse_x_ = point.GetX();
  mouse_y_ = point.GetY();
}

bool Input::KeyDown(const sdl::Scancode key) const {
  return static_cast<bool>(current_input_.at(static_cast<uint32_t>(key)));
}
bool Input::KeyUp(const sdl::Scancode key) const { return !KeyDown(key); }

bool Input::KeyPressed(const sdl::Scancode key) const {
  return (current_input_.at(static_cast<uint32_t>(key)))
         && !(prev_input_.at(static_cast<uint32_t>(key)));
}
bool Input::KeyHeld(const sdl::Scancode key) const {
  return (current_input_.at(static_cast<uint32_t>(key)))
         && (prev_input_.at(static_cast<uint32_t>(key)));
}
bool Input::KeyReleased(const sdl::Scancode key) const {
  return !(current_input_.at(static_cast<uint32_t>(key)))
         && (prev_input_.at(static_cast<uint32_t>(key)));
}

bool Input::MouseDown(const sdl::MouseButton button) const {
  return current_mouse_ & static_cast<uint32_t>(button);
}
bool Input::MouseUp(const sdl::MouseButton button) const {
  return !MouseDown(button);
}

bool Input::MouseClicked(const sdl::MouseButton button) const {
  return (current_mouse_ & static_cast<uint32_t>(button))
         && !(prev_mouse_ & static_cast<uint32_t>(button));
}
bool Input::MouseHeld(const sdl::MouseButton button) const {
  return (current_mouse_ & static_cast<uint32_t>(button))
         && (prev_mouse_ & static_cast<uint32_t>(button));
}
bool Input::MouseReleased(const sdl::MouseButton button) const {
  return !(current_mouse_ & static_cast<uint32_t>(button))
         && (prev_mouse_ & static_cast<uint32_t>(button));
}

} // namespace nge