//https://leetcode.com/problems/path-with-maximum-gold/
#ifndef ALGORITHMICCHALLENGES_1219_PATHWITHMAXIMUMGOLD_H
#define ALGORITHMICCHALLENGES_1219_PATHWITHMAXIMUMGOLD_H

#include <vector>
#include <array>
#include <unordered_map>
using namespace std;

using CacheT = unordered_map<int, unordered_map<vector<bool>, int>>;

struct Point {
    int i_;
    int j_;
    Point (int i, int j) : i_ {i}, j_{j} {}
};

bool canVisit(const Point& p, const vector<vector<int>>& grid, const vector<bool>& visited) {
    return
        p.i_ >= 0 &&
        p.j_ >= 0 &&
        p.i_ < grid.size() &&
        p.j_ < grid[p.i_].size() &&
        grid[p.i_][p.j_] != 0 &&
        !visited[p.i_ * grid.front().size() + p.j_];
}

array<Point, 4> getConnectedPoints(const Point& p) {
    return array<Point, 4>{
        Point{p.i_, p.j_ + 1},
        Point{p.i_ + 1, p.j_},
        Point{p.i_, p.j_ - 1},
        Point{p.i_ - 1, p.j_}
    };
}

int getMaxSum(const Point& p, const vector<vector<int>>& grid, vector<bool>& visited, CacheT& cache) {
    if (canVisit(p, grid, visited)) {
        auto index = p.i_ * grid.front().size() + p.j_;
        auto cacheIt = cache[index].find(visited);
        if (cacheIt != end(cache[index]))
            return cacheIt->second;
        visited[index] = true;
        vector<int> childrenSums;
        for (auto cp : getConnectedPoints(p))
            childrenSums.push_back(getMaxSum(cp, grid, visited, cache));
        visited[index] = false;
        auto res = grid[p.i_][p.j_] + *max_element(begin(childrenSums), end(childrenSums));
        cache[index][visited] = res;
        return res;
    }
    return 0;
}

int getMaximumGold(const vector<vector<int>>& grid) {
    int maxGold = 0;
    CacheT cache;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            vector<bool> visited(grid.size() * grid.front().size(), false);
            maxGold = max(maxGold, getMaxSum({i, j}, grid, visited, cache));
        }
    }
    return maxGold;
}

#endif //ALGORITHMICCHALLENGES_1219_PATHWITHMAXIMUMGOLD_H
