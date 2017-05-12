#ifndef LEETCODESOLUTIONS_CONNECTEDCELLINGRID_H
#define LEETCODESOLUTIONS_CONNECTEDCELLINGRID_H

#include <vector>
#include <queue>
#include <set>
#include <assert.h>
#include <iostream>

using namespace std;

namespace hackerrank
{
    int get_biggest_region(vector< vector<int> > grid)
    {
        if (grid.empty() || grid.front().empty())
            return 0;

        vector< vector<bool> > visited(grid.size());
        for (std::size_t i = 0; i < grid.size(); ++i)
            visited[i] = vector<bool>(grid.front().size(), false);

        int region = 0;
        for (std::size_t i = 0; i < grid.size(); ++i) {
            for (std::size_t j = 0; j < grid.front().size(); ++j) {
                queue<pair<size_t, size_t>> toCheckQueue;
                toCheckQueue.emplace(i, j);
                int current = 0;
                while (!toCheckQueue.empty())
                {
                    auto& element = toCheckQueue.front();
                    if (visited[element.first][element.second])
                    {
                        toCheckQueue.pop();
                        continue;
                    }

                    visited[element.first][element.second] = true;
                    if (grid[element.first][element.second] == 1)
                    {
                      ++current;
                    }
                    else
                    {
                      toCheckQueue.pop();
                      continue;
                    }

                    auto left = element.second > 0;
                    auto up = element.first > 0;
                    auto right = element.second < (grid.front().size() - 1);
                    auto down = element.first < (grid.size() - 1);

                    if (left)
                        toCheckQueue.emplace(element.first, element.second - 1);

                    if (left && up)
                        toCheckQueue.emplace(element.first - 1, element.second - 1);

                    if (up)
                        toCheckQueue.emplace(element.first - 1, element.second);

                    if (up && right)
                        toCheckQueue.emplace(element.first - 1, element.second + 1);

                    if (right)
                        toCheckQueue.emplace(element.first, element.second + 1);

                    if (right && down)
                        toCheckQueue.emplace(element.first + 1, element.second + 1);

                    if (down)
                        toCheckQueue.emplace(element.first + 1, element.second);

                    if (down && left)
                        toCheckQueue.emplace(element.first + 1, element.second - 1);

                    toCheckQueue.pop();
                }

                if (current > region)
                    region = current;
            }
        }

        return region;
    }
}

#endif //LEETCODESOLUTIONS_CONNECTEDCELLINGRID_H
