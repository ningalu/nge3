#ifndef MISC_ARITHMETIC_H
#define MISC_ARITHMETIC_H

#include <concepts>
#include <type_traits>

namespace ngl {
template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;
}
#endif