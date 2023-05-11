#include "ngsdl/SDLException.h"

// #include <format>

#include <SDL2/SDL.h>

namespace nge::sdl {
SDLException::SDLException(std::string msg) : message_(msg) {}
const char *SDLException::what() const noexcept {

  // what_
  //   = "Message: " + message_ + "\nSDL Error: " + std::string(SDL_GetError());
  return what_.c_str();
}
} // namespace nge::sdl