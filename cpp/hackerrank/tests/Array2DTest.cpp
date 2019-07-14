#include "../Array2D.h"
#include <gtest/gtest.h>

namespace hackerrank
{

TEST(Array2D, test)
{
    std::array<std::array<int, 6>, 6> array2d = {
        std::array<int, 6>{-9, -9, -9,  1, 1, 1},
        std::array<int, 6>{ 0, -9,  0,  4, 3, 2},
        std::array<int, 6>{-9, -9, -9,  1, 2, 3},
        std::array<int, 6>{ 0,  0,  8,  6, 6, 0},
        std::array<int, 6>{ 0,  0,  0, -2, 0, 0},
        std::array<int, 6>{ 0,  0,  1,  2, 4, 0}
    };

    ASSERT_EQ(hourglassSum(array2d), 28);
}

}//namespace hackerrank
