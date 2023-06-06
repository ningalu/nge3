#include "ngsdl/SDLException.h"

#include "fmt/format.h"

#include <SDL2/SDL.h>

namespace nge::sdl {
SDLException::SDLException(std::string msg) : message_(msg) {}
const char *SDLException::what() const noexcept {

  return fmt::format("Message: {0}\nSDL Error: {1}", message_, SDL_GetError())
    .c_str();
}
} // namespace nge::sdl