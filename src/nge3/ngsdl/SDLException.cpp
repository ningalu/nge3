#include "SDLException.h"

#include <SDL2/SDL.h>

namespace nge::sdl {
SDLException::SDLException(std::string msg) : message_(msg){};
const char *SDLException::what() const noexcept {
  std::string what
    = "Message: " + message_ + "\nSDL Error: " + std::string(SDL_GetError());
  return what.c_str();
}
} // namespace nge::sdl