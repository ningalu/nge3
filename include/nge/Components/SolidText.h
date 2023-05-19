#ifndef NGE_COMPONENTS_SOLIDTEXT_H
#define NGE_COMPONENTS_SOLIDTEXT_H

#include "nge/Components/Text.h"

namespace nge {
class SolidText : public Text {
public:
  SolidText(
    std::shared_ptr<Graphics> graphics,
    std::shared_ptr<sdl::Font> font,
    const std::string &text,
    nge::sdl::Colour colour
  );
};
} // namespace nge

#endif