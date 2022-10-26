#ifndef NGE3_NGSDL_FONT_H
#define NGE3_NGSDL_FONT_H

#include <memory>
#include <string>

#include "SDL2/SDL_ttf.h"

namespace nge::sdl {
class Texture;
class Font {
  friend class Texture;

public:
  Font(const std::string &filename, int point_size);

protected:
  std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> font_;
};
} // namespace nge::sdl

#endif