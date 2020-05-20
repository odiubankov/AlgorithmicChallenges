//https://leetcode.com/problems/sliding-puzzle/
#ifndef ALGORITHMICCHALLENGES_773_SLIDINGPUZZLE_H
#define ALGORITHMICCHALLENGES_773_SLIDINGPUZZLE_H

#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <sstream>

using namespace std;

constexpr auto FINAL_BOARD = "123450";
constexpr auto ROWS_CNT = 2;
constexpr auto COLUMNS_CNT = 3;

struct BoardStep {
    string board;
    int steps = 0;
    int heuristics = 0;

    BoardStep(string board_, int steps_, int heuristics_)
      : board(move(board_))
      , steps(steps_)
      , heuristics(heuristics_)
      {}
};

struct BoardComp {
    bool operator()(BoardStep const& b1, BoardStep const& b2) const noexcept {
        return (b1.steps + b1.heuristics) > (b2.steps + b2.heuristics);
    }
};

size_t getIndex(int row, int col) {
    return row * COLUMNS_CNT + col;
}

int getHeuristics(const string& s) {
    int res = 0;
    for (size_t i = 0; i != s.length(); ++i) {
        if (s[i] != FINAL_BOARD[i])
            ++res;
    }
    return res;
}

vector<BoardStep> nextSteps(const BoardStep& boardStep) {
    vector<BoardStep> nextBoards;
    auto zeroPos = boardStep.board.find('0');
    int row = zeroPos / COLUMNS_CNT;
    int col = zeroPos - row * COLUMNS_CNT;
    if (row != 0) {
        auto nextBoard = boardStep.board;
        swap(nextBoard[zeroPos], nextBoard[getIndex(row - 1, col)]);
        nextBoards.emplace_back(nextBoard, boardStep.steps + 1, getHeuristics(nextBoard));
    }
    if (col != 0) {
        auto nextBoard = boardStep.board;
        swap(nextBoard[zeroPos], nextBoard[getIndex(row, col - 1)]);
        nextBoards.emplace_back(nextBoard, boardStep.steps + 1, getHeuristics(nextBoard));
    }
    if (row != ROWS_CNT - 1) {
        auto nextBoard = boardStep.board;
        swap(nextBoard[zeroPos], nextBoard[getIndex(row + 1, col)]);
        nextBoards.emplace_back(nextBoard, boardStep.steps + 1, getHeuristics(nextBoard));
    }
    if (col != COLUMNS_CNT - 1) {
        auto nextBoard = boardStep.board;
        swap(nextBoard[zeroPos], nextBoard[getIndex(row, col + 1)]);
        nextBoards.emplace_back(nextBoard, boardStep.steps + 1, getHeuristics(nextBoard));
    }
    return nextBoards;
}

string boardToString(vector<vector<int>> const & board) {
    stringstream ss;
    for (auto const& row : board) {
        for (auto const& col : row) {
            ss << col;
        }
    }
    return ss.str();
}

int slidingPuzzle(vector<vector<int>> const & board) {
    auto boardStr = boardToString(board);
    priority_queue<BoardStep, vector<BoardStep>, BoardComp> boardQueue;
    boardQueue.push(BoardStep{boardStr, 0, 0});
    unordered_set<string> visited;
    while (!boardQueue.empty()) {
        auto nextBoard = boardQueue.top();
        boardQueue.pop();
        if (visited.find(nextBoard.board) != end(visited))
            continue;
        if (nextBoard.board == FINAL_BOARD)
            return nextBoard.steps;
        visited.insert(nextBoard.board);
        auto nextBoards = nextSteps(nextBoard);
        for (auto const& nextBoard : nextBoards) {
            boardQueue.push(nextBoard);
        }
    }
    return -1;
}

#endif //ALGORITHMICCHALLENGES_773_SLIDINGPUZZLE_H
