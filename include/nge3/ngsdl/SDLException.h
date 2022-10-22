#ifndef NGE3_NGSDL_SDLEXCEPTION_H
#define NGE3_NGSDL_SDLEXCEPTION_H

#include <stdexcept>
#include <string>

#include "SDL2/SDL.h"

namespace nge::sdl {
class SDLException : public std::exception {
public:
  SDLException(std::string msg);
  const char *what() const noexcept;

protected:
  std::string message_;
};
} // namespace nge::sdl

#endif