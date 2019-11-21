#include "85_MaximalRectangle.h"
#include <gtest/gtest.h>

TEST(MaxRectangle, test) {
    vector<vector<char>> m {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
//    ASSERT_EQ(6, maximalRectangle(m));
    ASSERT_EQ(6, maximalRectangleDP(m));
}

TEST(MaxRectangle, test2) {
    vector<vector<char>> m {
        {'1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','0'},
        {'1','1','1','1','1','1','1','0'},
        {'1','1','1','1','1','0','0','0'},
        {'0','1','1','1','1','0','0','0'},
    };
    ASSERT_EQ(21, maximalRectangle(m));
    ASSERT_EQ(21, maximalRectangleDP(m));
}

TEST(MaxRectangle, test3) {
    vector<vector<char>> m {
        {'0','1','1','0','1'},
        {'1','1','0','1','0'},
        {'0','1','1','1','0'},
        {'1','1','1','1','0'},
        {'1','1','1','1','1'},
        {'0','0','0','0','0'}
    };
    ASSERT_EQ(9, maximalRectangleDP(m));
}
