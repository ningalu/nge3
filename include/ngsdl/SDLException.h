#ifndef NGSDL_SDLEXCEPTION_H
#define NGSDL_SDLEXCEPTION_H

#include <stdexcept>
#include <string>

namespace nge::sdl {
class SDLException : public std::exception {
public:
  SDLException(std::string msg);
  const char *what() const noexcept;

protected:
  std::string message_;
  std::string what_;
};
} // namespace nge::sdl

#endif