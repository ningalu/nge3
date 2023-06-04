#include "gtest/gtest.h"

#include <bit>
#include <cstdint>
#include <iostream>
#include <type_traits>

#include "SDL2/SDL.h"
#include "misc/Rectangle.hpp"

TEST(Rectangle_SDL_Rect_Interop, Layout) {
  static_assert(
    std::is_standard_layout<ngl::Rectangle<int32_t>>::value,
    "Rectangle<int32_t> is not standard layout and wont interop with SDL_Rect"
  );
  static_assert(
    sizeof(ngl::Rectangle<int32_t>) == sizeof(SDL_Rect),
    "Rectangle<int32_t> is a different size to SDL_Rect"
  );
}

TEST(Rectangle_SDL_Rect_Interop, Access) {
  SDL_Rect a{1, 2, 3, 4};
  ASSERT_EQ(a.x, 1);
  ASSERT_EQ(a.y, 2);
  ASSERT_EQ(a.w, 3);
  ASSERT_EQ(a.h, 4);
  ngl::Rectangle<int32_t> b = std::bit_cast<ngl::Rectangle<int32_t>>(a);
  ASSERT_EQ(b.X(), 1);
  ASSERT_EQ(b.Y(), 2);
  ASSERT_EQ(b.W(), 3);
  ASSERT_EQ(b.H(), 4);
  SDL_Rect c = std::bit_cast<SDL_Rect>(b);
  ASSERT_EQ(c.x, 1);
  ASSERT_EQ(c.y, 2);
  ASSERT_EQ(c.w, 3);
  ASSERT_EQ(c.h, 4);
}

TEST(Rectangle_SDL_Rect_Interop, HasIntersection) {
  SDL_Rect a{0, 0, 50, 50};
  ngl::Rectangle<int32_t> b{51, 51, 100, 100};
  ASSERT_FALSE(SDL_HasIntersection(&a, std::bit_cast<SDL_Rect *>(&b)));
  b.SetX(40);
  b.SetY(40);
  ASSERT_TRUE(SDL_HasIntersection(&a, std::bit_cast<SDL_Rect *>(&b)));
}

TEST(Rectangle_SDL_Rect_Interop, test) {
  SDL_Rect a{0, 0, 50, 50};
  ngl::Rectangle<int32_t> b{51, 51, 100, 100};
  ASSERT_TRUE(true);
}
