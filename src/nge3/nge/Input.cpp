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
  auto kb = sdl::EventQueue::GetKeyboardState();
  for (std::size_t i = 0; i < 512; i++) {
    current_input_[i] = kb[i];
  }
}

bool Input::KeyDown(const sdl::Scancode key) const {
  return static_cast<bool>(current_input_.at(static_cast<uint32_t>(key)));
}

} // namespace nge