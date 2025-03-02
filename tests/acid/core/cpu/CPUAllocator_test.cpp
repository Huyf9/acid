#include <gtest/gtest.h>
#include <acid/core/cpu/CPUAllocator.h>

using namespace acid;

TEST(CPUAllocator, allocate) {
  CPUAllocator allocator;
  auto data1 = allocator.allocate(1);
  EXPECT_NE(data1.get(), nullptr);
  auto data2 = allocator.allocate(2);
  EXPECT_NE(data1.get(), nullptr);
  auto data3 = allocator.allocate(100);
  EXPECT_NE(data1.get(), nullptr);
}

TEST(CPUAllocator, reallocate) {
  CPUAllocator allocator;
  auto data1 = allocator.allocate(1);
  EXPECT_NE(data1.get(), nullptr);
  allocator.reallocate(data1, 2);
  EXPECT_NE(data1.get(), nullptr);
  allocator.reallocate(data1, 100);
  EXPECT_NE(data1.get(), nullptr);
}

TEST(CPUAllocator, free) {
  CPUAllocator allocator;
  auto data1 = allocator.allocate(1);
  auto data2 = allocator.allocate(2);
  EXPECT_EQ(data1.get_deleter().target<deleteFunc>(),
            data2.get_deleter().target<deleteFunc>());
}
