#ifndef NGE3_NGE3_VIEW_H
#define NGE3_NGE3_VIEW_H

#include "ngsdl/Rectangle.h"

namespace nge {
class View {
public:
  virtual void Render();

protected:
  sdl::Rect viewport_;

private:
};
} // namespace nge

#endif