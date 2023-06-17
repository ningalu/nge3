#include "ngsdl/TTFException.h"

#include "SDL2/SDL_ttf.h"
#include "fmt/format.h"

namespace nge::sdl {
// i cant believe this doesnt default initialise
std::vector<std::string> TTFException::history = {};

TTFException::TTFException(std::string msg) : message_(msg) {}
// surely theres a better way of doing this
const char *TTFException::what() const noexcept {
  TTFException::history.push_back(
    fmt::format("Message: {0}\nSDL Error: {1}", message_, SDL_GetError())
  );
  return TTFException::history.at(TTFException::history.size() - 1).c_str();
}
} // namespace nge::sdl