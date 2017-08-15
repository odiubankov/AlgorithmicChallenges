#include "../BinarySearchIceCreamParlor.h"
#include <gtest/gtest.h>

namespace hackerrank
{

TEST(BinarySearchIceCreamParlor, test1)
{
    int n = 5, m = 4;
    std::vector<IceCream> arr{IceCream{1, 1}, IceCream{4, 2}, IceCream{5, 3}, IceCream{3, 4}, IceCream{2, 5}};
    auto resultMin = std::numeric_limits<int>::max(), resultMax = std::numeric_limits<int>::min();
    sort(begin(arr), end(arr));
    for (int i = 0; i < n; ++i) {
        int search = m - arr[i].flavor;
        if (search >= arr[i].flavor) {
            int index = binarySearch(i, n - 1, arr, search);
            if (index != -1) {
                resultMin = std::min(arr[i].index, arr[index].index);
                resultMax = std::max(arr[i].index, arr[index].index);
                break;
            }
        }
    }

    ASSERT_EQ(resultMin, 1);
    ASSERT_EQ(resultMax, 4);
}

}//namespace hackerrank

