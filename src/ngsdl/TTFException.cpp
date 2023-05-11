#include "ngsdl/TTFException.h"

#include <SDL2/SDL_ttf.h>

namespace nge::sdl {
TTFException::TTFException(std::string msg) : message_(msg) {}
const char *TTFException::what() const noexcept {
  // what_
  //   = "Message: " + message_ + "\nSDL Error: " + std::string(TTF_GetError());
  return what_.c_str();
}
} // namespace nge::sdl