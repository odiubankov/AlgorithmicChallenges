#include "../CoinChange.h"
#include <gtest/gtest.h>

namespace hackerrank
{

TEST(CoinChange, test1)
{
    std::vector<long long> srcArray{1, 2, 3};
    ASSERT_EQ(getWays(4, srcArray), 4);
}

}
