#include "8_ZeroMatrix.h"
#include <gtest/gtest.h>

TEST(ZeroMatrix, ZeroInMiddle) {
    std::vector<std::vector<int>> matrix {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    setZeroes(matrix);

    std::vector<std::vector<int>> zeroedMatrix {
        {1,0,1},
        {0,0,0},
        {1,0,1}
    };
    ASSERT_EQ(matrix, zeroedMatrix);
}

TEST(ZeroMatrix, ZeroInFirstRowAndColumn) {
    std::vector<std::vector<int>> matrix {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    setZeroes(matrix);

    std::vector<std::vector<int>> zeroedMatrix {
        {0,0,0,0},
        {0,4,5,0},
        {0,3,1,0}
    };
    ASSERT_EQ(matrix, zeroedMatrix);
}
