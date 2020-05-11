#include "../StockMaximize.h"
#include <gtest/gtest.h>

namespace hackerrank
{

TEST(StockMaximize, test1)
{
    std::vector<long long> srcArray{5, 3, 2};
    ASSERT_EQ(stockmax(srcArray), 0);
}

}//namespace hackerrank
