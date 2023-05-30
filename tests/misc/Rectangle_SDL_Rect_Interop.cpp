#include "gtest/gtest.h"

#include "SDL2/SDL.h"
#include "misc/Rectangle.hpp"

#include <bit>
#include <cstdint>
#include <iostream>
#include <type_traits>

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
