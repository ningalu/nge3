#ifndef NGE_INPUT_H
#define NGE_INPUT_H

#include <array>
#include <functional>
#include <vector>

#include <SDL2/SDL.h>

#include "ngsdl/Events/MouseButton.h"
#include "ngsdl/Events/Scancode.h"
#include "ngsdl/Point.h"

namespace nge {

class App;
class Input {

  friend class App;

public:
  Input();

  void Update();

  static constexpr std::array<sdl::MouseButton, 5> MOUSE_BUTTONS{
    sdl::MouseButton::LEFT,
    sdl::MouseButton::MIDDLE,
    sdl::MouseButton::RIGHT,
    sdl::MouseButton::X1,
    sdl::MouseButton::X2};

  [[nodiscard]] bool KeyDown(const sdl::Scancode key) const;
  [[nodiscard]] bool KeyUp(const sdl::Scancode key) const;

  [[nodiscard]] bool KeyPressed(const sdl::Scancode key) const;
  [[nodiscard]] bool KeyHeld(const sdl::Scancode key) const;
  [[nodiscard]] bool KeyReleased(const sdl::Scancode key) const;

  [[nodiscard]] bool MouseDown(const sdl::MouseButton button) const;
  [[nodiscard]] bool MouseUp(const sdl::MouseButton button) const;

  [[nodiscard]] bool MouseClicked(const sdl::MouseButton button) const;
  [[nodiscard]] bool MouseHeld(const sdl::MouseButton button) const;
  [[nodiscard]] bool MouseReleased(const sdl::MouseButton button) const;

  [[nodiscard]] std::vector<sdl::MouseButton> AllMouseClicked() const;
  [[nodiscard]] std::vector<sdl::MouseButton> AllMouseHeld() const;
  [[nodiscard]] std::vector<sdl::MouseButton> AllMouseReleased() const;

  [[nodiscard]] int32_t MouseX() const;
  [[nodiscard]] int32_t MouseY() const;
  [[nodiscard]] sdl::Point MousePos() const;
  [[nodiscard]] int32_t PrevMouseX() const;
  [[nodiscard]] int32_t PrevMouseY() const;
  [[nodiscard]] sdl::Point PrevMousePos() const;

protected:
  std::array<uint8_t, SDL_NUM_SCANCODES> current_input_, prev_input_;

  [[nodiscard]] inline std::vector<sdl::MouseButton>
  MouseInteraction_(std::function<bool(sdl::MouseButton)> f) const;

  uint32_t current_mouse_, prev_mouse_;
  int rel_mouse_x, rel_mouse_y_;
  sdl::Point mouse_pos_, prev_mouse_pos_;
};
} // namespace nge

#endif