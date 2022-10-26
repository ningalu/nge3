#include "Font.h"

#include "TTFException.h"

namespace nge::sdl {
Font::Font(const std::string &filename, int point_size)
    : font_(nullptr, TTF_CloseFont) {
  auto f = TTF_OpenFont(filename.c_str(), point_size);
  if (f == nullptr) {
    throw TTFException("Font couldn't be opened");
  }
  font_.reset(f);
}
} // namespace nge::sdl