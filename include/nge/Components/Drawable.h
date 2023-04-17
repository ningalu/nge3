#ifndef NGE3_NGE_COMPONENTS_DRAWABLE_H
#define NGE3_NGE_COMPONENTS_DRAWABLE_H

namespace nge {
class Drawable {
public:
  virtual void Draw() = 0;
  virtual ~Drawable() = 0;
};
} // namespace nge

#endif