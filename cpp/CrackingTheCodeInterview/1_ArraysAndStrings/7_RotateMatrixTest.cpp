#include "7_RotateMatrix.h"
#include <gtest/gtest.h>

TEST(RotateMatrix, Rotate3x3) {
    std::vector<std::vector<int>> matrix {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    rotate(matrix);

    std::vector<std::vector<int>> rotatedMatrix {
        {7,4,1},
        {8,5,2},
        {9,6,3}
    };
    ASSERT_EQ(matrix, rotatedMatrix);
}

TEST(RotateMatrix, Rotate4x4) {
    std::vector<std::vector<int>> matrix {
        { 5, 1, 9,11},
        { 2, 4, 8,10},
        {13, 3, 6, 7},
        {15,14,12,16},
    };

    rotate(matrix);

    std::vector<std::vector<int>> rotatedMatrix {
        {15,13, 2, 5},
        {14, 3, 4, 1},
        {12, 6, 8, 9},
        {16, 7,10,11}
    };
    ASSERT_EQ(matrix, rotatedMatrix);
}

TEST(RotateMatrix, RotateEmpty) {
    std::vector<std::vector<int>> matrix;

    rotate(matrix);

    std::vector<std::vector<int>> rotatedMatrix;
    ASSERT_EQ(matrix, rotatedMatrix);
}
