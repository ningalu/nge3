#include "ngsdl/TTFException.h"

#include "SDL2/SDL_ttf.h"
#include "fmt/format.h"

namespace nge::sdl {
TTFException::TTFException(std::string msg) : message_(msg) {}
const char *TTFException::what() const noexcept {
  return fmt::format("Message: {0}\nSDL Error: {1}", message_, SDL_GetError())
    .c_str();
}
} // namespace nge::sdl