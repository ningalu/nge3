#ifndef NGE3_NGE_COMPONENTS_TEXT_H
#define NGE3_NGE_COMPONENTS_TEXT_H

#include <memory>
#include <string>

#include "nge/Components/SimpleComponent.h"
#include "ngsdl/Color.h"
#include "ngsdl/FontRenderType.h"

namespace nge {
namespace sdl {
class Font;
}
class Graphics;
} // namespace nge

namespace nge {
class Text : public SimpleComponent {
public:
  Text() = default;
  Text(
    const std::shared_ptr<Graphics> &graphics,
    const std::shared_ptr<sdl::Font> &font,
    const std::string &text,
    sdl::Color color = {255, 255, 255, 255},
    sdl::FontRenderType type = {sdl::FontRenderType::SOLID},
    sdl::Color bg = {0, 0, 0, 0}
  );
};
} // namespace nge

#endif