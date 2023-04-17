#ifndef NGSDL_EVENTTYPE_H
#define NGSDL_EVENTTYPE_H

#include <SDL2/SDL.h>

namespace nge::sdl {
enum class EventType {
  QUIT = SDL_QUIT,
  APP_TERMINATING = SDL_APP_TERMINATING,
  APP_LOWMEMORY = SDL_APP_LOWMEMORY,
  APP_WILLENTERBACKGROUND = SDL_APP_WILLENTERBACKGROUND,
  APP_DIDENTERBACKGROUND = SDL_APP_DIDENTERBACKGROUND,
  APP_WILLENTERFOREGROUND = SDL_APP_WILLENTERFOREGROUND,
  APP_DIDENTERFOREGROUND = SDL_APP_DIDENTERFOREGROUND,
  DISPLAY = SDL_DISPLAYEVENT,
  WINDOW = SDL_WINDOWEVENT,
  SYSWMEVENT = SDL_SYSWMEVENT,
  KEYDOWN = SDL_KEYDOWN,
  KEYUP = SDL_KEYUP,
  TEXTEDITING = SDL_TEXTEDITING,
  TEXTINPUT = SDL_TEXTINPUT,
  KEYMAPCHANGES = SDL_KEYMAPCHANGED,
  MOUSEMOTION = SDL_MOUSEMOTION,
  MOUSEBUTTONDOWN = SDL_MOUSEBUTTONDOWN,
  MOUSEBUTTONUP = SDL_MOUSEBUTTONUP,
  MOUSEWHEEL = SDL_MOUSEWHEEL,
  JOYAXISMOTION = SDL_JOYAXISMOTION,
  JOYBALLMOTION = SDL_JOYBALLMOTION,
  JOYHATMOTION = SDL_JOYHATMOTION,
  JOYBUTTONDOWN = SDL_JOYBUTTONDOWN,
  JOYBUTTONUP = SDL_JOYBUTTONUP,
  JOYDEVICEADDED = SDL_JOYDEVICEADDED,
  JOYDEVICEREMOVED = SDL_JOYDEVICEREMOVED,
  CONTROLLERAXISMOTION = SDL_CONTROLLERAXISMOTION,
  CONTROLLERBUTTONDOWN = SDL_CONTROLLERBUTTONDOWN,
  CONTROLLERBUTTONUP = SDL_CONTROLLERBUTTONUP,
  CONTROLLERDEVICEADDED = SDL_CONTROLLERDEVICEADDED,
  CONTROLLERDEVICEREMOVED = SDL_CONTROLLERDEVICEREMOVED,
  CONTROLLERDEVICEREMAPPED = SDL_CONTROLLERDEVICEREMAPPED,
  FINGERDOWN = SDL_FINGERDOWN,
  FINGERUP = SDL_FINGERUP,
  FINGERMOTION = SDL_FINGERMOTION,
  DOLLARGESTURE = SDL_DOLLARGESTURE,
  DOLLARRECORD = SDL_DOLLARRECORD,
  MULTIGESTURE = SDL_MULTIGESTURE,
  CLIPBOARDUPDATE = SDL_CLIPBOARDUPDATE,
  DROPFILE = SDL_DROPFILE,
  DROPTEXT = SDL_DROPTEXT,
  DROPBEGIN = SDL_DROPBEGIN,
  DROPCOMPLETE = SDL_DROPCOMPLETE,
  AUDIODEVICEADDED = SDL_AUDIODEVICEADDED,
  AUDIODEVICEREMOVED = SDL_AUDIODEVICEREMOVED,
  RENDER_TARGETS_RESET = SDL_RENDER_TARGETS_RESET,
  RENDER_DEVICE_RESET = SDL_RENDER_DEVICE_RESET,
  USEREVENT = SDL_USEREVENT,
};
}

#endif