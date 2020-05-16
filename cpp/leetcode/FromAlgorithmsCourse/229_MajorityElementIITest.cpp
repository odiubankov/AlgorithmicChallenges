#include "229_MajorityElementII.h"
#include <gtest/gtest.h>

TEST(MajorityElement, test) {
    ASSERT_EQ(std::vector<int>{1}, majorityElement(std::vector<int>{4, 2, 1, 1}));
}

TEST(MajorityElement, test2) {
    std::vector<int> expectedRes{1, 2};
    ASSERT_EQ(expectedRes, majorityElement(std::vector<int>{1,2,2,3,2,1,1,3}));
}

TEST(MajorityElement, test3) {
    std::vector<int> expectedRes{0};
    ASSERT_EQ(expectedRes, majorityElement(std::vector<int>{0, 0, 0}));
}