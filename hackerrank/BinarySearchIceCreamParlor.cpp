#include "BinarySearchIceCreamParlor.h"
#include <gtest/gtest.h>

TEST(BinarySearchIceCreamParlor, test1)
{
  using namespace hackerrank;
  int n = 5, m = 4;
  vector<IceCream> arr{ IceCream{1, 1}, IceCream{ 4, 2 }, IceCream{ 5, 3 }, IceCream{ 3, 4 }, IceCream{ 2, 5 } };
  auto resultMin = std::numeric_limits<int>::max(), resultMax = std::numeric_limits<int>::min();
  sort(begin(arr), end(arr));
  for (int i = 0; i < n; ++i) {
    int search = m - arr[i].flavor;
    if (search >= arr[i].flavor) {
      int index = binarySearch(i, n - 1, arr, search);
      if (index != -1) {
        resultMin = min(arr[i].index, arr[index].index);
        resultMax = max(arr[i].index, arr[index].index);
        break;
      }
    }
  }

  ASSERT_EQ(resultMin, 1);
  ASSERT_EQ(resultMax, 4);
}