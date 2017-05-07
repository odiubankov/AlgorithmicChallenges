// https://leetcode.com/problems/word-search/#/description
/*
 Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
 */

#ifndef LEETCODESOLUTIONS_WORDSEARCH_H
#define LEETCODESOLUTIONS_WORDSEARCH_H

#include <vector>
#include <string>

using namespace std;

namespace wordsearch
{
class Solution {
    using BoardT = vector<vector<char>>;
    using VisitedCellsT = vector<vector<bool>>;
    bool checkNextCell(
        const BoardT& board,
        VisitedCellsT& visitedCells,
        string::iterator& charIter,
        const string::iterator& wordEnd,
        int i,
        int j)
    {
        ++charIter;
        if (charIter == wordEnd)
            return true;

        visitedCells[i][j] = true;

        //up
        if (i > 0 && *charIter == board[i - 1][j] &&!visitedCells[i - 1][j])
        {
            if (checkNextCell(board, visitedCells, charIter, wordEnd, i - 1, j))
                return true;
        }

        //down
        if (i < (board.size() - 1) &&
            *charIter == board[i + 1][j] &&
            !visitedCells[i + 1][j])
        {
            if (checkNextCell(board, visitedCells, charIter, wordEnd, i + 1, j))
                return true;
        }

        //right
        if (j < (board.front().size() - 1) &&
            *charIter == board[i][j + 1] &&
            !visitedCells[i][j + 1])
        {
            if (checkNextCell(board, visitedCells, charIter, wordEnd, i, j + 1))
                return true;
        }

        //left
        if (j > 0 &&
            *charIter == board[i][j - 1] &&
            !visitedCells[i][j - 1])
        {
            if (checkNextCell(board, visitedCells, charIter, wordEnd, i, j - 1))
                return true;
        }

        visitedCells[i][j] = false;
        --charIter;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())
            return true;

        if (board.empty() || board.front().empty())
            return false;

        auto wordBegin = begin(word);
        auto wordEnd = end(word);
        VisitedCellsT visitedCells(board.size(), vector<bool>(board.front().size(), false));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board.front().size(); ++j)
            {
                if (board[i][j] == word.front())
                {
                    if (checkNextCell(board, visitedCells, wordBegin, wordEnd, i, j))
                        return true;
                }
            }
        }

        return false;
    }
};
}

#endif //LEETCODESOLUTIONS_WORDSEARCH_H
