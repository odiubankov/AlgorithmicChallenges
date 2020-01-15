#include "221_MaximalSquare.h"
#include <gtest/gtest.h>

TEST(MaximalSquare, test) {
    std::vector<std::vector<char>> matrix{
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    ASSERT_EQ(4, maximalSquareDP(matrix));
}

TEST(MaximalSquare, test2) {
    std::vector<std::vector<char>> matrix{
        {'1','1'},
        {'1','1'}
    };
    ASSERT_EQ(4, maximalSquare(matrix));
}
TEST(MaximalSquare, test3) {
    std::vector<std::vector<char>> matrix{
        {'0','0','0','1'},
        {'1','1','0','1'},
        {'1','1','1','1'},
        {'0','1','1','1'},
        {'0','1','1','1'},
    };
    ASSERT_EQ(9, maximalSquare(matrix));
}
