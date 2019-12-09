//https://leetcode.com/problems/knight-probability-in-chessboard/
#ifndef ALGORITHMICCHALLENGES_688_KNIGHTPROBABILITYCHESSBOARD_H
#define ALGORITHMICCHALLENGES_688_KNIGHTPROBABILITYCHESSBOARD_H
#include <array>
#include <vector>
#include <unordered_map>

struct Pos {
    int row;
    int col;
};

bool operator==(const Pos& pos1, const Pos& pos2) {
    return pos1.col == pos2.col && pos1.row == pos2.row;
}

namespace std {
    template <>
    struct hash<Pos> {
        std::size_t operator()(const Pos& pos) const {
            auto hashRow = hash<int>()(pos.row);
            auto hashCol = hash<int>()(pos.col);
            return hashRow ^ (hashCol << 1);
        }
    };
}

using namespace std;

constexpr size_t MovesCnt = 8;
using CacheT = unordered_map<Pos, unordered_map<int, double>>;

bool isValid(int N, const Pos& pos) {
    return pos.row >= 0 && pos.row < N && pos.col >= 0 && pos.col < N;
}

array<Pos, MovesCnt> getMovesFrom(const Pos& pos) {
    return {
        Pos{pos.row - 1, pos.col - 2},
        Pos{pos.row - 2, pos.col - 1},
        Pos{pos.row - 2, pos.col + 1},
        Pos{pos.row - 1, pos.col + 2},
        Pos{pos.row + 1, pos.col + 2},
        Pos{pos.row + 2, pos.col + 1},
        Pos{pos.row + 2, pos.col - 1},
        Pos{pos.row + 1, pos.col - 2}
    };
}

double probabilityToGo(int N, int K, const Pos& pos, CacheT& cache) {
    auto probIt = cache[pos].find(K);
    if (probIt != end(cache[pos]))
        return probIt->second;
    double prob = 0;
    auto nextMoves = getMovesFrom(pos);
    if (K > 1) {
        for (const auto& nextMove : nextMoves) {
            if (isValid(N, nextMove)) {
                prob += (probabilityToGo(N, K - 1, nextMove, cache) / MovesCnt);
            } else {
                prob += 1.0 / MovesCnt;
            }
        }
    } else {
        auto moveInvalid = [N](const Pos& pos) { return !isValid(N, pos); };
        size_t invalidMovesCnt = count_if(begin(nextMoves), end(nextMoves), moveInvalid);
        prob = static_cast<double>(invalidMovesCnt) / MovesCnt;
    }
    cache[pos][K] = prob;
    return prob;
}

double knightProbability(int N, int K, int row, int col) {
    if (K == 0)
        return 1.0;
    CacheT cache;
    return 1.0 - probabilityToGo(N, K, Pos{row, col}, cache);
}

#endif //ALGORITHMICCHALLENGES_688_KNIGHTPROBABILITYCHESSBOARD_H
