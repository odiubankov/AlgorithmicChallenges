#include "WordSearch.h"
#include <gtest/gtest.h>

TEST(WordSearch, test)
{
    wordsearch::Solution solution;
    vector<vector<char>> matrix {
        vector<char>{'A','B','C','E'},
        vector<char>{'S','F','C','S'},
        vector<char>{'A','D','E','E'} };
    EXPECT_TRUE(solution.exist(matrix, "ABCCED"));
    EXPECT_TRUE(solution.exist(matrix, "SEE"));
    EXPECT_FALSE(solution.exist(matrix, "ABCB"));
}
