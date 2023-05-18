#ifndef NGE_COMPONENTS_TEXT_H
#define NGE_COMPONENTS_TEXT_H

#include <memory>
#include <string>

#include "nge/Components/Drawing/Component.h"
#include "ngsdl/Color.h"
#include "ngsdl/FontRenderType.h"

namespace nge {
namespace sdl {
class Font;
}
class Graphics;
} // namespace nge

namespace nge {
class Text : public Component {
public:
  Text() = default;

  Text(
    const std::shared_ptr<Graphics> &graphics,
    const std::shared_ptr<sdl::Font> &font,
    const std::string &text,
    sdl::Color color = {0, 0, 0, 255},
    sdl::FontRenderType type = sdl::FontRenderType::SOLID,
    sdl::Color bg = {0, 0, 0, 0}
  );

  void UpdateText(
    const std::shared_ptr<sdl::Font> &font,
    const std::string &text,
    sdl::Color color = {0, 0, 0, 255},
    sdl::FontRenderType type = sdl::FontRenderType::SOLID,
    sdl::Color bg = {0, 0, 0, 0}
  );

  ~Text();
};
} // namespace nge

#endif