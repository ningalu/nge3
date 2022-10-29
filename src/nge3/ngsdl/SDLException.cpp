#include "SDLException.h"

#pragma warning(push, 0)
#include "SDL2/SDL.h"
#pragma warning(pop)

namespace nge::sdl {
SDLException::SDLException(std::string msg) : message_(msg){};
const char *SDLException::what() const noexcept {
  std::string what
    = "Message: " + message_ + "\nSDL Error: " + std::string(SDL_GetError());
  return what.c_str();
}
} // namespace nge::sdl