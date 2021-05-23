#include "240_SearchA2DMatrixII.h"
#include <gtest/gtest.h>

TEST(SearchMatrix, test55) {
    std::vector<std::vector<int>> matrix{
            {1,4,7,11,15},
            {2,5,8,12,19},
            {3,6,9,16,22},
            {10,13,14,17,24},
            {18,21,23,26,30}
    };
    ASSERT_TRUE(searchMatrix(matrix, 5));
}

TEST(SearchMatrix, test21N) {
    std::vector<std::vector<int>> matrix{
            {1,1},
    };
    ASSERT_FALSE(searchMatrix(matrix, 2));
}

TEST(SearchMatrix, test21P) {
    std::vector<std::vector<int>> matrix{
            {-1,3},
    };
    ASSERT_TRUE(searchMatrix(matrix, -1));
}

TEST(SearchMatrix, test12P) {
    std::vector<std::vector<int>> matrix{
            {5},
            {6}
    };
    ASSERT_TRUE(searchMatrix(matrix, 5));
}

TEST(SearchMatrix, test13P) {
    std::vector<std::vector<int>> matrix{
            {1},
            {3},
            {5}
    };
    ASSERT_TRUE(searchMatrix(matrix, 5));
}

TEST(SearchMatrix, test15N) {
    std::vector<std::vector<int>> matrix{
            {1},
            {2},
            {3},
            {4},
            {5}
    };
    ASSERT_FALSE(searchMatrix(matrix, 6));
}

TEST(SearchMatrix, test55_2) {
    std::vector<std::vector<int>> matrix{
            {1,2,3,4,5},
            {6,7,8,9,10},
            {11,12,13,14,15},
            {16,17,18,19,20},
            {21,22,23,24,25}
    };
    ASSERT_TRUE(searchMatrix(matrix, 5));
}

TEST(SearchMatrix, test66) {
    std::vector<std::vector<int>> matrix{
            {3,3,8,13,13,18},
            {4,5,11,13,18,20},
            {9,9,14,15,23,23},
            {13,18,22,22,25,27},
            {18,22,23,28,30,33},
            {21,25,28,30,35,35},
            {24,25,33,36,37,40}
    };
    ASSERT_TRUE(searchMatrix(matrix, 21));
}
