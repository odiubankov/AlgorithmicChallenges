#include "200_NumberOfIslands.h"
#include <gtest/gtest.h>

TEST(NumberOfIslands, test) {
    std::vector<std::vector<char>> grid1{{'1','1','1','1','0'},
                                         {'1','1','0','1','0'},
                                         {'1','1','0','0','0'},
                                         {'0','0','0','0','0'}};
    ASSERT_EQ(1, numIslands(grid1));

    std::vector<std::vector<char>> grid2{{'1','1','0','0','0'},
                                         {'1','1','0','0','0'},
                                         {'0','0','1','0','0'},
                                         {'0','0','0','1','1'}};
    ASSERT_EQ(3, numIslands(grid2));

    std::vector<std::vector<char>> grid3{{'1','0','1','1','1'},
                                         {'1','0','1','0','1'},
                                         {'1','1','1','0','1'}};
    ASSERT_EQ(1, numIslands(grid3));
}
