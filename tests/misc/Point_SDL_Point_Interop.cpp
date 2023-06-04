#include "gtest/gtest.h"

#include <bit>
#include <cstdint>
#include <iostream>
#include <type_traits>

#include "SDL2/SDL.h"
#include "misc/Point.hpp"

TEST(Point_SDL_Point_Interop, Layout) {
  static_assert(
    std::is_standard_layout<ngl::Point<int32_t>>::value,
    "Rectangle<int32_t> is not standard layout and wont interop with SDL_Point"
  );
  static_assert(
    sizeof(ngl::Point<int32_t>) == sizeof(SDL_Point),
    "Rectangle<int32_t> is a different size to SDL_Point"
  );
}