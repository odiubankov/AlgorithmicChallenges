//https://leetcode.com/contest/weekly-contest-158/problems/queens-that-can-attack-the-king/
#ifndef ALGORITHMICCHALLENGES_QUEENSTHATCANATTACKTHEKING_H
#define ALGORITHMICCHALLENGES_QUEENSTHATCANATTACKTHEKING_H

#include <vector>
#include <array>

class SolutionQueensAttackTheKing {
public:
    std::vector<std::vector<int>> queensAttacktheKing(const std::vector<std::vector<int>>& queens, const std::vector<int>& king) {
        std::array<std::array<bool, 8>, 8> chessBoard{};
        for (auto& row : chessBoard)
            for (auto& col : row)
                col = false;

        for (const auto& queen : queens)
            chessBoard[queen.front()][queen.back()] = true;

        std::vector<std::vector<int>> res;
        //left
        for (int i = king.back() - 1; i >= 0; --i) {
            if (chessBoard[king.front()][i]) {
                res.push_back({king.front(), i});
                break;
            }
        }
        //right
        for (int i = king.back() + 1; i < 8; ++i) {
            if (chessBoard[king.front()][i]) {
                res.push_back({king.front(), i});
                break;
            }
        }
        //top
        for (int i = king.front() - 1; i >=0; --i) {
            if (chessBoard[i][king.back()]) {
                res.push_back({i, king.back()});
                break;
            }
        }
        //bottom
        for (int i = king.front() + 1; i < 8; ++i) {
            if (chessBoard[i][king.back()]) {
                res.push_back({i, king.back()});
                break;
            }
        }
        //left & top
        for (int i = king.front() - 1, j = king.back() - 1; i >= 0 && j >= 0; --i, --j) {
            if (chessBoard[i][j]) {
                res.push_back({i, j});
                break;
            }
        }
        //right & top
        for (int i = king.front() - 1, j = king.back() + 1; i >= 0 && j < 8; --i, ++j) {
            if (chessBoard[i][j]) {
                res.push_back({i, j});
                break;
            }
        }
        //right & bottom
        for (int i = king.front() + 1, j = king.back() + 1; i < 8 && j < 8; ++i, ++j) {
            if (chessBoard[i][j]) {
                res.push_back({i, j});
                break;
            }
        }
        //left & bottom
        for (int i = king.front() + 1, j = king.back() - 1; i < 8 && j >= 0; ++i, --j) {
            if (chessBoard[i][j]) {
                res.push_back({i, j});
                break;
            }
        }

        return res;
    }
};

#endif //ALGORITHMICCHALLENGES_QUEENSTHATCANATTACKTHEKING_H
