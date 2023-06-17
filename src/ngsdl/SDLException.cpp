#include "ngsdl/SDLException.h"

#include "fmt/format.h"

#include <SDL2/SDL.h>

namespace nge::sdl {
std::vector<std::string> SDLException::history = {};

SDLException::SDLException(std::string msg) : message_(msg) {}
const char *SDLException::what() const noexcept {
  SDLException::history.push_back(
    fmt::format("Message: {0}\nSDL Error: {1}", message_, SDL_GetError())
  );
  return SDLException::history.at(SDLException::history.size() - 1).c_str();
}
} // namespace nge::sdl