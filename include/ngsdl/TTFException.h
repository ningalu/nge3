#ifndef NGE3_NGSDL_TTFEXCEPTION_H
#define NGE3_NGSDL_TTFEXCEPTION_H

#include <stdexcept>
#include <string>

// Exists for the sake of semantic equivalence and readability, since
// TTF_GetError is literally just SDL_GetError
namespace nge::sdl {
class TTFException : public std::exception {
public:
  TTFException(std::string msg);
  const char *what() const noexcept;

protected:
  std::string message_;
};
} // namespace nge::sdl

#endif