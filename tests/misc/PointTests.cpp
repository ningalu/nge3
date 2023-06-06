#include "gtest/gtest.h"

#include <type_traits>

#include "misc/Point.hpp"

TEST(PointTests, Access) {
  ngl::Point<int32_t> p{20, 30};
  ASSERT_EQ(p.X(), 20);
  static_assert(std::is_same<decltype(p.X()), int32_t>::value);
  ASSERT_EQ(p.Y(), 30);
  static_assert(std::is_same<decltype(p.Y()), int32_t>::value);
  ASSERT_EQ(p.X<double>() + 0.5, 20.5);
  static_assert(std::is_same<decltype(p.X<double>()), double>::value);
  ASSERT_EQ(p.Y<double>() + 0.5, 30.5);
  static_assert(std::is_same<decltype(p.Y<double>()), double>::value);
}

TEST(PointTests, Within_Enclosed_NoEnclosedAxis) {
  ngl::Point<int32_t> p{0, 0};
  ngl::Rectangle<int32_t> r{10, 10, 100, 100};
  EXPECT_FALSE(p.Within(r));
}
TEST(PointTests, Within_Enclosed_XAxis) {
  ngl::Point<int32_t> p{200, 30};
  ngl::Rectangle<int32_t> r{10, 10, 100, 100};
  EXPECT_FALSE(p.Within(r));
}
TEST(PointTests, Within_Enclosed_YAxis) {
  ngl::Point<int32_t> p{20, 200};
  ngl::Rectangle<int32_t> r{10, 10, 100, 100};
  EXPECT_FALSE(p.Within(r));
}
TEST(PointTests, Within_Enclosed_FullyEnclosed) {
  ngl::Point<int32_t> p{20, 30};
  ngl::Rectangle<int32_t> r{10, 10, 100, 100};
  EXPECT_TRUE(p.Within(r));
}

TEST(PointTests, Distance_Integer) {
  ngl::Point<int32_t> p1{0, 0}, p2{1, 1};
  EXPECT_EQ(p1.Distance(p2), std::sqrt(2));
  EXPECT_EQ(p1.Distance(p2), p2.Distance(p1));
}
TEST(PointTests, Distance_float) {
  ngl::Point<double> p1{0, 0}, p2{1, 1};
  EXPECT_EQ(p1.Distance(p2), std::sqrt(2));
  EXPECT_EQ(p1.Distance(p2), p2.Distance(p1));
}