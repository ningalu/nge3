#ifndef NGE3_NGSDL_EVENTS_KEYMOD_H
#define NGE3_NGSDL_EVENTS_KEYMOD_H

#pragma warning(push, 0)
#include "SDL2/SDL.h"
#pragma warning(pop)

namespace nge::sdl {
enum class KeyMod {
  NONE = KMOD_NONE,
  LSHIFT = KMOD_LSHIFT,
  RSHIFT = KMOD_RSHIFT,
  LCTRL = KMOD_LCTRL,
  RCTRL = KMOD_RCTRL,
  LALT = KMOD_LALT,
  RALT = KMOD_RALT,
  LGUI = KMOD_LGUI,
  RGUI = KMOD_RGUI,
  NUM = KMOD_NUM,
  CAPS = KMOD_CAPS,
  MODE = KMOD_MODE,
  // SCROLL = KMOD_SCROLL, // should be available but isnt?
  CTRL = KMOD_CTRL,
  SHIFT = KMOD_SHIFT,
  ALT = KMOD_ALT,
  GUI = KMOD_GUI,

};
KeyMod operator|(KeyMod lhs, KeyMod rhs);
bool operator&(KeyMod lhs, KeyMod rhs);
} // namespace nge::sdl

#endif