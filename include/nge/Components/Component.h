#ifndef NGE3_NGE_COMPONENTS_COMPONENT_H
#define NGE3_NGE_COMPONENTS_COMPONENT_H

#include "nge/Components/Drawable.h"
#include "nge/Components/Rotatable.h"
#include "nge/Components/Translatable.h"

namespace nge {
class Component : public Drawable, public Rotatable, public Translatable {};
} // namespace nge

#endif