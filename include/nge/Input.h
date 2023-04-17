#ifndef NGE3_NGE_INPUT_H
#define NGE3_NGE_INPUT_H

#include <array>

#include <SDL2/SDL.h>

#include "ngsdl/Events/MouseButton.h"
#include "ngsdl/Events/Scancode.h"

namespace nge {
class Input {
public:
  Input();

  void Update();

  bool KeyDown(const sdl::Scancode key) const;
  bool KeyUp(const sdl::Scancode key) const;

  bool KeyPressed(const sdl::Scancode key) const;
  bool KeyHeld(const sdl::Scancode key) const;
  bool KeyReleased(const sdl::Scancode key) const;

  bool MouseDown(const sdl::MouseButton button) const;
  bool MouseUp(const sdl::MouseButton button) const;

  bool MouseClicked(const sdl::MouseButton button) const;
  bool MouseHeld(const sdl::MouseButton button) const;
  bool MouseReleased(const sdl::MouseButton button) const;

protected:
  std::array<uint8_t, SDL_NUM_SCANCODES> current_input_, prev_input_;

  uint32_t current_mouse_, prev_mouse_;
  int mouse_x_, mouse_y_, rel_mouse_x, rel_mouse_y_;
};
} // namespace nge

#endif