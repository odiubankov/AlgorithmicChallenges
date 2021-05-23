// https://leetcode.com/problems/n-queens/

#include <vector>
#include <string>

#ifndef ALGORITHMICCHALLENGES_51_NQUEENS_H
#define ALGORITHMICCHALLENGES_51_NQUEENS_H

using BoardT = std::vector<std::string>;
using BoardsT = std::vector<BoardT>;

void tryQueens(BoardsT& boards, BoardT board, int n) {
    if (n == board.size()) {
        for (int i = 1; i != n; ++i) {
            for (int j = 0; j != n; ++j) {
                if (board[i][j] == '*')
                    board[i][j] = '.';
            }
        }
        boards.push_back(std::move(board));
        return;
    }

    for (int i = 0; i != board.size(); ++i) {
        if (board[n][i] == '.') {
            auto nextBoard = board;
            nextBoard[n][i] = 'Q';
            // vertical
            for (int j = n + 1; j != board.size(); ++j)
                nextBoard[j][i] = '*';
            // diagonal to left
            for (int j = n + 1, k = i - 1; j != board.size() && k >= 0; ++j, --k)
                nextBoard[j][k] = '*';
            // diagonal to right
            for (int j = n + 1, k = i + 1; j != board.size() && k != board.size(); ++j, ++k)
                nextBoard[j][k] = '*';
            tryQueens(boards, nextBoard, n + 1);
        }
    }
}

BoardsT solveNQueens(int n) {
    BoardsT boards;
    BoardT board(n, std::string(n, '.'));
    tryQueens(boards, board, 0);
    return boards;
}

#endif //ALGORITHMICCHALLENGES_51_NQUEENS_H
