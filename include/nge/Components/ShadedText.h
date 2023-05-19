#ifndef NGE_COMPONENTS_SHADEDTEXT_H
#define NGE_COMPONENTS_SHADEDTEXT_H

#include "nge/Components/Text.h"

namespace nge {
class ShadedText : public Text {
public:
  ShadedText(
    std::shared_ptr<Graphics> graphics,
    std::shared_ptr<sdl::Font> font,
    const std::string &text,
    nge::sdl::Colour colour,
    nge::sdl::Colour bg = nge::sdl::Colour{0, 0, 0, 0}
  );
};
} // namespace nge

#endif