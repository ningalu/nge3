#include "gtest/gtest.h"

#include "Point.h"

TEST(PointTests, Addition) {
  using namespace nge::sdl;
  Point p1 = {5, 5}, p2 = {10, 10};
  Point p3 = p1 + p2;
  Point expected = {15, 15};
  ASSERT_EQ(expected, p3);
  p1 += p2;
  ASSERT_EQ(p3, p1);
}

TEST(PointTests, Subtraction) {
  using namespace nge::sdl;
  Point p1 = {2, 3}, p2 = {5, 7};
  Point p3 = p2 - p1;
  Point expected = {3, 4};
  ASSERT_EQ(expected, p3);
  p2 -= p1;
  ASSERT_EQ(p3, p2);
}

TEST(PointTests, Multiplication) {
  using namespace nge::sdl;
  Point p1 = {2, 3}, p2 = {5, 7};
  Point p3 = p2 * p1;
  Point expected = {10, 21};
  ASSERT_EQ(expected, p3);
  p2 *= p1;
  ASSERT_EQ(p3, p2);
  Point original_p1 = {2, 3};
  ASSERT_EQ(original_p1, p1);
}

TEST(PointTests, Division) {
  using namespace nge::sdl;
  Point p1 = {18, 21}, p2 = {3, 7};
  Point p3 = p1 / p2;
  Point expected = {6, 3};
  ASSERT_EQ(expected, p3);
  p1 /= p2;
  ASSERT_EQ(p3, p1);
  Point original_p2 = {3, 7};
  ASSERT_EQ(original_p2, p2);
}