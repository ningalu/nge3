#ifndef NGE3_NGE_INPUT_H
#define NGE3_NGE_INPUT_H

#include <array>

#include <SDL2/SDL.h>

#include "nge3/ngsdl/Events/Scancode.h"

namespace nge {
class Input {
public:
  Input();

  void Update();

  bool KeyIsDown(const sdl::Scancode key) const;
  bool KeyIsUp(const sdl::Scancode key) const;
  bool KeyPressed(const sdl::Scancode key) const;
  bool KeyHeld(const sdl::Scancode key) const;
  bool KeyReleased(const sdl::Scancode key) const;

protected:
  std::array<uint8_t, SDL_NUM_SCANCODES> current_input_;
  std::array<uint8_t, SDL_NUM_SCANCODES> prev_input_;
};
} // namespace nge

#endif