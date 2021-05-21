#include "../topics/recursion/WordSearch.h"
#include <gtest/gtest.h>

namespace leetcode
{

TEST(WordSearch, test)
{
    Solution solution;
    std::vector<std::vector<char>> matrix{
        std::vector<char>{'A', 'B', 'C', 'E'},
        std::vector<char>{'S', 'F', 'C', 'S'},
        std::vector<char>{'A', 'D', 'E', 'E'}};
//    EXPECT_TRUE(solution.exist(matrix, "ABCCED"));
    EXPECT_TRUE(solution.exist(matrix, "SEE"));
//    EXPECT_FALSE(solution.exist(matrix, "ABCB"));
}

}//namespace leetcode

