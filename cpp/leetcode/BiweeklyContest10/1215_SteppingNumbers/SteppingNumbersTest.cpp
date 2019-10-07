#include "SteppingNumbers.h"
#include <gtest/gtest.h>

TEST(SteppingNumbers, Test) {
    SolutionSteppingNumbers s;
    std::vector<int> res{0,1,2,3,4,5,6,7,8,9,10,12,21};
    ASSERT_EQ(res, s.countSteppingNumbers(0, 21));
}
