#ifndef NGE_NGE3_COMPONENTS_TRANSLATABLE_H
#define NGE_NGE3_COMPONENTS_TRANSLATABLE_H

#include "ngsdl/Point.h"

namespace nge {

class Translatable {
public:
  virtual sdl::Point GetPos() = 0;
  virtual void SetPos(sdl::Point p) = 0;
  virtual void SetPos(int32_t x, int32_t y) = 0;
  virtual void SetX(int x) = 0;
  virtual void SetY(int y) = 0;
  virtual void MoveX(int x) = 0;
  virtual void MoveY(int y) = 0;

  virtual ~Translatable() = 0;
};
} // namespace nge

#endif