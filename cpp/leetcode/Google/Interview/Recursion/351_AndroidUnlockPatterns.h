//https://leetcode.com/problems/android-unlock-patterns/
#ifndef ALGORITHMICCHALLENGES_351_ANDROIDUNLOCKPATTERNS_H
#define ALGORITHMICCHALLENGES_351_ANDROIDUNLOCKPATTERNS_H

#include <vector>
#include <unordered_map>
using namespace std;

using KeysT = vector<vector<char>>;

struct UnlockPos {
private:
    KeysT& keys_;
    int row_, col_;

    pair<int, int> nextLeft() const {
        pair<int, int> next{row_, col_};
        do {
            --next.second;
        } while (isValid(next.first, next.second) && keys_[next.first][next.second] == 1);
        return next;
    }

    pair<int, int> nextRight() const {
        pair<int, int> next{row_, col_};
        do {
            ++next.second;
        } while (isValid(next.first, next.second) && keys_[next.first][next.second] == 1);
        return next;
    }

    pair<int, int> nextTop() const {
        pair<int, int> next{row_, col_};
        do {
            --next.first;
        } while (isValid(next.first, next.second) && keys_[next.first][next.second] == 1);
        return next;
    }

    pair<int, int> nextBottom() const {
        pair<int, int> next{row_, col_};
        do {
            ++next.first;
        } while (isValid(next.first, next.second) && keys_[next.first][next.second] == 1);
        return next;
    }

    pair<int, int> nextLeftTop() const {
        pair<int, int> next{row_, col_};
        do {
            --next.first;
            --next.second;
        } while (isValid(next.first, next.second) && keys_[next.first][next.second] == 1);
        return next;
    }

    pair<int, int> nextRightTop() const {
        pair<int, int> next{row_, col_};
        do {
            --next.first;
            ++next.second;
        } while (isValid(next.first, next.second) && keys_[next.first][next.second] == 1);
        return next;
    }

    pair<int, int> nextRightBottom() const {
        pair<int, int> next{row_, col_};
        do {
            ++next.first;
            ++next.second;
        } while (isValid(next.first, next.second) && keys_[next.first][next.second] == 1);
        return next;
    }

    pair<int, int> nextLeftBottom() const {
        pair<int, int> next{row_, col_};
        do {
            ++next.first;
            --next.second;
        } while (isValid(next.first, next.second) && keys_[next.first][next.second] == 1);
        return next;
    }

     vector<pair<int, int>> getNeighbours(int row, int col) const {
        return {nextLeft(), nextLeftTop(), nextTop(), nextRightTop(), nextRight(), nextRightBottom(),
                nextBottom(), nextLeftBottom(),
                {row - 1, col - 2}, { row - 1, col + 2 }, { row + 1, col + 2}, {row + 1, col - 2},
                {row - 2, col - 1}, { row - 2, col + 1 }, { row + 2, col + 1}, {row + 2, col - 1}};
    }

    bool isValid(int row, int col) const {
        return row >= 0 && row < keys_.size() && col >= 0 && col < keys_[row].size();
    }

    bool canGo(int row, int col) const {
         return isValid(row, col) && keys_[row][col] == 0;
    }

public:
    UnlockPos(KeysT& keys, int row, int col) : keys_{keys}, row_{row}, col_{col} {}
    void turnPosOn() { keys_[row_][col_] = 1; }
    void turnPosOff() { keys_[row_][col_] = 0; }
    vector<UnlockPos> getNextPositions() {
        vector<UnlockPos> nextPositions;
        for (const auto& neighbour : getNeighbours(row_, col_)) {
            if (canGo(neighbour.first, neighbour.second)) {
                nextPositions.emplace_back(keys_, neighbour.first, neighbour.second);
            }
        }
        return nextPositions;
    }
};

void countPatterns(UnlockPos pos, int minCnt, int maxCnt, int onCnt, int& counter) {
    if (onCnt >= minCnt)
        ++counter;
    if (onCnt < maxCnt) {
        pos.turnPosOn();
        for (auto nextPos : pos.getNextPositions())
            countPatterns(nextPos, minCnt, maxCnt, onCnt + 1, counter);
        pos.turnPosOff();
    }
}

int numberOfPatterns(int m, int n) {
    KeysT keys(3, vector<char>(3, 0));
    int counter = 0;
    for (int i = 0; i < keys.size(); ++i) {
        for (int j = 0; j < keys[i].size(); ++j) {
            countPatterns(UnlockPos{keys, i, j}, m, n, 1, counter);
        }
    }
    return counter;
}

#endif //ALGORITHMICCHALLENGES_351_ANDROIDUNLOCKPATTERNS_H
