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

namespace leetcode
{

class Solution
{
    using BoardT = std::vector<std::vector<char>>;
    using VisitedCellsT = std::vector<std::vector<bool>>;
    bool checkNextCell(
        const BoardT &board,
        VisitedCellsT &visitedCells,
        std::string::iterator &charIter,
        const std::string::iterator &wordEnd,
        int i,
        int j)
    {
        ++charIter;
        if (charIter == wordEnd)
            return true;

        visitedCells[i][j] = true;

        //up
        if (i > 0 && *charIter == board[i - 1][j] && !visitedCells[i - 1][j]) {
            if (checkNextCell(board, visitedCells, charIter, wordEnd, i - 1, j))
                return true;
        }

        //down
        if (i < (board.size() - 1) &&
            *charIter == board[i + 1][j] &&
            !visitedCells[i + 1][j]) {
            if (checkNextCell(board, visitedCells, charIter, wordEnd, i + 1, j))
                return true;
        }

        //right
        if (j < (board.front().size() - 1) &&
            *charIter == board[i][j + 1] &&
            !visitedCells[i][j + 1]) {
            if (checkNextCell(board, visitedCells, charIter, wordEnd, i, j + 1))
                return true;
        }

        //left
        if (j > 0 &&
            *charIter == board[i][j - 1] &&
            !visitedCells[i][j - 1]) {
            if (checkNextCell(board, visitedCells, charIter, wordEnd, i, j - 1))
                return true;
        }

        visitedCells[i][j] = false;
        --charIter;
        return false;
    }

public:
    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        if (word.empty())
            return true;

        if (board.empty() || board.front().empty())
            return false;

        auto wordBegin = begin(word);
        auto wordEnd = end(word);
        VisitedCellsT visitedCells(board.size(), std::vector<bool>(board.front().size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.front().size(); ++j) {
                if (board[i][j] == word.front()) {
                    if (checkNextCell(board, visitedCells, wordBegin, wordEnd, i, j))
                        return true;
                }
            }
        }

        return false;
    }
};

}//namespace leetcode

#endif //LEETCODESOLUTIONS_WORDSEARCH_H
