#include "gtest/gtest.h"

#include <type_traits>

#include "SDL2/SDL.h"

#include "ngsdl/Color.h"

using nge::sdl::Colour;

TEST(PointTests, Layout) {
  static_assert(
    std::is_standard_layout<Colour>::value,
    "nge::sdl::Colour is not standard layout and won't interop with SDL_Color "
    "correctly"
  );
  static_assert(
    sizeof(Colour) == sizeof(SDL_Color),
    "nge::sdl::Colour is a different size to SDL_Color and will not interop "
    "correctly"
  );
}
TEST(PointTests, Interop) {
  Colour c1 = Colour{56, 73, 14, 255};
  SDL_Color c2 = std::bit_cast<SDL_Color>(c1);
  ASSERT_EQ(c1.r, c2.r);
  ASSERT_EQ(c1.g, c2.g);
  ASSERT_EQ(c1.b, c2.b);
  ASSERT_EQ(c1.a, c2.a);
}