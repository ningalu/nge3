#ifndef NGE3_NGE_COMPONENTS_ROTATABLE_H
#define NGE3_NGE_COMPONENTS_ROTATABLE_H

namespace nge {
class Rotatable {
public:
  virtual void Rotate(double angle) = 0;
  virtual double GetAngle() = 0;
  virtual void SetAngle(double angle) = 0;
  virtual ~Rotatable() = 0;
};
} // namespace nge

#endif