#ifndef NGSDL_INITFLAGS_H
#define NGSDL_INITFLAGS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdint>

namespace nge::sdl {
enum class SDLInitFlags : uint32_t {

  // timer subsystem
  TIMER = SDL_INIT_TIMER,

  // audio subsystem
  AUDIO = SDL_INIT_AUDIO,

  // video subsystem; automatically initializes the events subsystem
  VIDEO = SDL_INIT_VIDEO,

  //  joystick subsystem; automatically initializes the events subsystem
  JOYSTICK = SDL_INIT_JOYSTICK,

  // haptic (force feedback) subsystem
  HAPTIC = SDL_INIT_HAPTIC,

  // controller subsystem; automatically initializes the joystick subsystem
  GAMECONTROLLER = SDL_INIT_GAMECONTROLLER,

  // events subsystem
  EVENTS = SDL_INIT_EVENTS,

  // all of the above subsystems
  EVERYTHING = SDL_INIT_EVERYTHING,

  // compatibility; this flag is ignored
  NOPARACHUTE = SDL_INIT_NOPARACHUTE

};
SDLInitFlags operator|(SDLInitFlags lhs, SDLInitFlags rhs);

enum class IMGInitFlags : uint32_t {
  JPG = IMG_INIT_JPG,
  PNG = IMG_INIT_PNG,
  TIF = IMG_INIT_TIF,
  WEBP = IMG_INIT_WEBP,
  // JXL = IMG_INIT_JXL,
  // AVIF = IMG_INIT_AVIF
  ALL = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP
};
IMGInitFlags operator|(IMGInitFlags lhs, IMGInitFlags rhs);

// enum class TTFInitFlags : uint32_t {};
// TTFInitFlags operator|(TTFInitFlags lhs, TTFInitFlags rhs);

} // namespace nge::sdl

#endif