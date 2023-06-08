#include "gtest/gtest.h"

#include "SDL2/SDL.h"
#include "ngsdl/Surface.h"
TEST(SurfaceTests, Layout) {
  static_assert(
    std::is_standard_layout<nge::sdl::Surface>::value,
    "nge::sdl::Surface is not standard layout and won't interop with "
    "SDL_Surface correctly"
  );
  static_assert(
    sizeof(nge::sdl::Surface) == sizeof(SDL_Surface),
    "nge::sdl::Surface is a different size to SDL_Surface and will not interop "
    "correctly"
  );
}