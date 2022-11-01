#ifndef NGE3_NGE_COMPONENTS_COMPONENT_H
#define NGE3_NGE_COMPONENTS_COMPONENT_H

#include "Components/Drawable.h"
#include "Components/Rotatable.h"
#include "Components/Translatable.h"

namespace nge {
class Component : public Drawable, public Rotatable, public Translatable {};
} // namespace nge

#endif