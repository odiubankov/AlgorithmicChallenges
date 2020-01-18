/** https://leetcode.com/problems/word-search/#/description
*
* Given a 2D board and a word, find if the word exists in the grid.
*
* The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
*
* For example,
* Given board =
*
* [
*   ['A','B','C','E'],
*   ['S','F','C','S'],
*   ['A','D','E','E']
* ]
* word = "ABCCED", -> returns true,
* word = "SEE", -> returns true,
* word = "ABCB", -> returns false.
*
* Copyright 2017 Oleksii Diubankov
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef LEETCODESOLUTIONS_WORDSEARCH_H
#define LEETCODESOLUTIONS_WORDSEARCH_H

#include <vector>
#include <string>

namespace leetcode {

class Solution {
    using BoardT = std::vector<std::vector<char>>;
    static bool checkNextCell(
        BoardT &board,
        std::string::const_iterator charIter,
        const std::string::const_iterator &wordEnd,
        size_t i,
        size_t j) {
        if (*charIter != board[i][j])
            return false;
        board[i][j] = '*';
        auto nextIter = charIter + 1;
        if (nextIter == wordEnd)
            return true;
        if (i > 0 && checkNextCell(board, nextIter, wordEnd, i - 1, j))
            return true;
        if (i < (board.size() - 1) && checkNextCell(board, nextIter, wordEnd, i + 1, j))
            return true;
        if (j < (board.front().size() - 1) && checkNextCell(board, nextIter, wordEnd, i, j + 1))
            return true;
        if (j > 0 && checkNextCell(board, nextIter, wordEnd, i, j - 1))
            return true;
        board[i][j] = *charIter;
        return false;
    }

public:
    bool exist(BoardT &board, const std::string& word) {
        if (word.empty())
            return true;
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board.front().size(); ++j) {
                if (checkNextCell(board, begin(word), end(word), i, j))
                    return true;
            }
        }
        return false;
    }
};

}//namespace leetcode

#endif //LEETCODESOLUTIONS_WORDSEARCH_H
