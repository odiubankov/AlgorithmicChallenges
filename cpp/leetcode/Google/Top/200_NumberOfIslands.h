//https://leetcode.com/problems/number-of-islands/
#ifndef ALGORITHMICCHALLENGES_200_NUMBEROFISLANDS_H
#define ALGORITHMICCHALLENGES_200_NUMBEROFISLANDS_H

#include <vector>
#include <stack>

int numIslands(std::vector<std::vector<char>>& grid) {
    if (grid.empty() || grid.front().empty())
        return 0;
    int num = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == '1') {
                ++num;
                std::stack<std::pair<int, int>> island;
                island.emplace(i,j);
                while (!island.empty()) {
                    auto point = island.top();
                    island.pop();
                    grid[point.first][point.second] = '2';
                    if (point.first < (grid.size() - 1) && grid[point.first + 1][point.second] == '1')
                        island.emplace(point.first + 1, point.second);
                    if (point.first > 0 && grid[point.first - 1][point.second] == '1')
                        island.emplace(point.first - 1, point.second);
                    if (point.second > 0 && grid[point.first][point.second - 1] == '1')
                        island.emplace(point.first, point.second - 1);
                    if (point.second < (grid[point.first].size() - 1) && grid[point.first][point.second + 1] == '1')
                        island.emplace(point.first, point.second + 1);
                }
            }
        }
    }
    return num;
}

#endif //ALGORITHMICCHALLENGES_200_NUMBEROFISLANDS_H
