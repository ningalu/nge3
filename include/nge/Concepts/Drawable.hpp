#ifndef NGE3_NGE3_CONCEPTS_DRAWABLE_HPP
#define NGE3_NGE3_CONCEPTS_DRAWABLE_HPP

#include <concepts>

namespace nge {
// i cant find any good options for clang format and concepts
// clang-format off
template <typename T>
concept Drawable = requires(T t) {
  { t.Draw() } -> std::convertible_to<void>;
};
// clang-format on
} // namespace nge

#endif