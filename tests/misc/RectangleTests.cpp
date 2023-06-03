#include "gtest/gtest.h"

#include "misc/Rectangle.hpp"

#include <cstdint>
#include <iostream>

TEST(RectangleTests, Access) {
  ngl::Rectangle<int32_t> r{20, 30, 15, 10};
  ASSERT_EQ(r.X(), 20);
  ASSERT_EQ(r.Y(), 30);
  ASSERT_EQ(r.W(), 15);
  ASSERT_EQ(r.H(), 10);
  ASSERT_EQ(r.X<double>(), 20.0);
}

TEST(RectangleTests, DirectXAssignmentCastFloating) {
  ngl::Rectangle<int32_t> r{20, 30, 15, 10};
  ASSERT_EQ(r.X(), 20);
  ASSERT_EQ(r.X<double>(), 20.0);
  r.SetX<double>(21.5);
  ASSERT_EQ(r.X(), 21);
  r.SetX(20);
  ASSERT_EQ(r.X(), 20);
}
TEST(RectangleTests, DirectYAssignmentCastFloating) {
  ngl::Rectangle<int32_t> r{20, 30, 15, 10};
  r.SetY<double>(21.5);
  ASSERT_EQ(r.Y(), 21);
  r.SetY(20);
  ASSERT_EQ(r.Y(), 20);
}
TEST(RectangleTests, DirectWAssignmentCastFloating) {
  ngl::Rectangle<int32_t> r{20, 30, 15, 10};
  r.SetW<double>(21.5);
  ASSERT_EQ(r.W(), 21);
  r.SetW(20);
  ASSERT_EQ(r.W(), 20);
}
TEST(RectangleTests, DirectHAssignmentCastFloating) {
  ngl::Rectangle<int32_t> r{20, 30, 15, 10};
  r.SetH<double>(21.5);
  ASSERT_EQ(r.H(), 21);
  r.SetH(20);
  ASSERT_EQ(r.H(), 20);
}

TEST(RectangleTests, DirectXAssignmentCastNarrow) {
  ngl::Rectangle<int32_t> r{20, 30, 15, 10};
  ASSERT_EQ(r.X(), 20);
  r.SetX<int16_t>(21);
  ASSERT_EQ(r.X(), 21);
  r.SetX(20);
  ASSERT_EQ(r.X(), 20);
}
TEST(RectangleTests, DirectYAssignmentCastNarrow) {
  ngl::Rectangle<int32_t> r{20, 30, 15, 10};
  r.SetY<int16_t>(21);
  ASSERT_EQ(r.Y(), 21);
  r.SetY(20);
  ASSERT_EQ(r.Y(), 20);
}
TEST(RectangleTests, DirectWAssignmentCastNarrow) {
  ngl::Rectangle<int32_t> r{20, 30, 15, 10};
  r.SetW<int16_t>(21);
  ASSERT_EQ(r.W(), 21);
  r.SetW(20);
  ASSERT_EQ(r.W(), 20);
}
TEST(RectangleTests, DirectHAssignmentCastNarrow) {
  ngl::Rectangle<int32_t> r{20, 30, 15, 10};
  r.SetH<int16_t>(21);
  ASSERT_EQ(r.H(), 21);
  r.SetH(20);
  ASSERT_EQ(r.H(), 20);
}

TEST(RectangleTests, DirectXAssignmentCastWide) {
  ngl::Rectangle<int32_t> r{20, 30, 15, 10};
  ASSERT_EQ(r.X(), 20);
  r.SetX<int64_t>(4'294'967'296);
  // narrowing starts here
  ASSERT_NE(r.X(), 4'294'967'296);
  r.SetX(20);
  ASSERT_EQ(r.X(), 20);
}
TEST(RectangleTests, DirectYAssignmentCastWide) {
  ngl::Rectangle<int32_t> r{20, 30, 15, 10};
  r.SetY<int64_t>(4'294'967'296);
  ASSERT_NE(r.Y(), 4'294'967'296);
  r.SetY(20);
  ASSERT_EQ(r.Y(), 20);
}
TEST(RectangleTests, DirectWAssignmentCastWide) {
  ngl::Rectangle<int32_t> r{20, 30, 15, 10};
  r.SetW<int64_t>(4'294'967'296);
  ASSERT_NE(r.W(), 4'294'967'296);
  r.SetW(20);
  ASSERT_EQ(r.W(), 20);
}
TEST(RectangleTests, DirectHAssignmentCastWide) {
  ngl::Rectangle<int32_t> r{20, 30, 15, 10};
  r.SetH<int64_t>(4'294'967'296);
  ASSERT_NE(r.H(), 4'294'967'296);
  r.SetH(20);
  ASSERT_EQ(r.H(), 20);
}

TEST(RectangleTests, IntersectsRectangle_NoIntersectionAxis) {
  ngl::Rectangle<int32_t> r1{0, 0, 50, 50}, r2{51, 51, 50, 50};
  ASSERT_FALSE(r1.Intersects(r2));
  ASSERT_FALSE(r2.Intersects(r1));
}
TEST(RectangleTests, IntersectsRectangle_IntersectXAxis) {
  ngl::Rectangle<int32_t> r1{0, 0, 50, 50}, r2{25, 51, 50, 50};
  ASSERT_FALSE(r1.Intersects(r2));
  ASSERT_FALSE(r2.Intersects(r1));
}
TEST(RectangleTests, IntersectsRectangle_IntersectYAxis) {
  ngl::Rectangle<int32_t> r1{0, 0, 50, 50}, r2{51, 25, 50, 50};
  ASSERT_FALSE(r1.Intersects(r2));
  ASSERT_FALSE(r2.Intersects(r1));
}
TEST(RectangleTests, IntersectsRectangle_Intersects) {
  ngl::Rectangle<int32_t> r1{0, 0, 50, 50}, r2{25, 25, 50, 50};
  ASSERT_TRUE(r1.Intersects(r2));
  ASSERT_TRUE(r2.Intersects(r1));
}

TEST(RectangleTests, IntersectsRectangle_NoIntersectionAxis_Double) {
  ngl::Rectangle<int32_t> r1{0, 0, 50, 50};
  ngl::Rectangle<double> r2{51, 51, 50, 50};
  ASSERT_FALSE(r1.Intersects(r2));
  ASSERT_FALSE(r2.Intersects(r1));
}
TEST(RectangleTests, IntersectsRectangle_IntersectXAxis_Double) {
  ngl::Rectangle<int32_t> r1{0, 0, 50, 50};
  ngl::Rectangle<double> r2{25, 51, 50, 50};
  ASSERT_FALSE(r1.Intersects(r2));
  ASSERT_FALSE(r2.Intersects(r1));
}
TEST(RectangleTests, IntersectsRectangle_IntersectYAxis_Double) {
  ngl::Rectangle<int32_t> r1{0, 0, 50, 50};
  ngl::Rectangle<double> r2{51, 25, 50, 50};
  ASSERT_FALSE(r1.Intersects(r2));
  ASSERT_FALSE(r2.Intersects(r1));
}
TEST(RectangleTests, IntersectsRectangle_Intersects_Double) {
  ngl::Rectangle<int32_t> r1{0, 0, 50, 50};
  ngl::Rectangle<double> r2{25, 25, 50, 50};
  ASSERT_TRUE(r1.Intersects(r2));
  ASSERT_TRUE(r2.Intersects(r1));
}