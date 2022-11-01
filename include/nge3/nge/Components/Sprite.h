#ifndef NGE3_NGE_COMPONENTS_SPRITE_H
#define NGE3_NGE_COMPONENTS_SPRITE_H

#include <memory>
#include <tuple>

#include "Components/Component.h"
#include "nge3/ngsdl/Texture.h"

namespace nge {
class Graphics;
class Sprite : public Component {
public:
  Sprite() = default;
  Sprite(
    const std::shared_ptr<Graphics> &graphics, const std::string &filename
  );

  void SetScale(double scale);

  virtual void Rotate(double angle) override;
  virtual double GetAngle() override;
  virtual void SetAngle(double angle) override;

  virtual sdl::Point GetPos() override;
  virtual void SetPos(sdl::Point p) override;
  virtual void SetX(int x) override;
  virtual void SetY(int y) override;
  virtual void MoveX(int x) override;
  virtual void MoveY(int y) override;

  virtual void Draw() override;

protected:
  sdl::Rect src_, dst_;
  double angle_;

  std::shared_ptr<sdl::Texture> texture_;
  // i could probably do all the graphics stuff on the stack
  std::shared_ptr<Graphics> graphics_;
};
} // namespace nge

#endif