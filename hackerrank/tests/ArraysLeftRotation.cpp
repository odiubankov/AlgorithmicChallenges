#include "../ArraysLeftRotation.h"
#include <gtest/gtest.h>

namespace hackerrank
{

TEST(ArraysLeftRotation, test)
{
    std::vector<int> srcArray{1, 2, 3, 4, 5};
    auto resultArray = array_left_rotation(srcArray, static_cast<int>(srcArray.size()), 1);
    std::vector<int> expectedResult{2, 3, 4, 5, 1};
    ASSERT_EQ(resultArray, expectedResult);

    resultArray = hackerrank::array_left_rotation(srcArray, static_cast<int>(srcArray.size()), 5);
    ASSERT_EQ(resultArray, srcArray);
}

}//namespace hackerrank
