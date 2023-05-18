#ifndef NGE_COMPONENTS_DRAWABLE_H
#define NGE_COMPONENTS_DRAWABLE_H

#include <cstdint>
#include <memory>

namespace nge {
class Drawable {
public:
  virtual void Draw() = 0;
  virtual void SetScale(double n) = 0;
  [[nodiscard]] virtual bool Overlaps(int32_t x, int32_t y) const = 0;
  [[nodiscard]] virtual uint32_t GetDrawPriority() const;

  [[nodiscard]] static bool CompareDrawPriority(
    const std::shared_ptr<Drawable> &lhs, const std::shared_ptr<Drawable> &rhs
  ) noexcept;

  virtual ~Drawable() = 0;
};
} // namespace nge

#endif