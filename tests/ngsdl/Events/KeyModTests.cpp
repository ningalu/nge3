#include "gtest/gtest.h"

#include "ngsdl/Events/KeyMod.h"

TEST(KeyModTests, Bitwise_Ops) {
  nge::sdl::KeyMod k1 = nge::sdl::KeyMod::ALT;
  nge::sdl::KeyMod k2 = nge::sdl::KeyMod::CAPS;
  nge::sdl::KeyMod k3 = k1 | k2;
  EXPECT_NE(k3, k1);
  EXPECT_NE(k3, k2);
  EXPECT_TRUE(k3 & k1);
  EXPECT_TRUE(k3 & k2);
}