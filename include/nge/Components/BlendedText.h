#ifndef NGE_COMPONENTS_BLENDEDTEXT_H
#define NGE_COMPONENTS_BLENDEDTEXT_H

#include "nge/Components/Text.h"

namespace nge {
class BlendedText : public Text {
public:
  BlendedText(
    std::shared_ptr<Graphics> graphics,
    std::shared_ptr<sdl::Font> font,
    const std::string &text,
    nge::sdl::Colour colour
  );
};
} // namespace nge

#endif