#ifndef NGSDL_SDLEXCEPTION_H
#define NGSDL_SDLEXCEPTION_H

#include <stdexcept>
#include <string>
#include <vector>

namespace nge::sdl {
class SDLException : public std::exception {
public:
  SDLException(std::string msg);
  static std::vector<std::string> history;
  const char *what() const noexcept;

protected:
  std::string message_;
};
} // namespace nge::sdl

#endif