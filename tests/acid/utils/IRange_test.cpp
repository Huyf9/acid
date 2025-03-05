#include <gtest/gtest.h>
#include <acid/utils/IRange.h>


TEST(IRange, test) {
  acid::IRange<int> range(0, 10);
  int i = 0;
  for (int x : range) {
    EXPECT_EQ(x, i);
    ++i;
  }
  EXPECT_EQ(i, 10);
}

TEST(IRange, test2) {
  acid::IRange<int> range(10);
  int i = 0;
  for (int x : range) {
    EXPECT_EQ(x, i);
    ++i;
  }
  EXPECT_EQ(i, 10);
}
