#ifndef LEETCODESOLUTIONS_CONNECTEDCELLINGRID_H
#define LEETCODESOLUTIONS_CONNECTEDCELLINGRID_H

#include <vector>
#include <queue>

using namespace std;

namespace hackerrank
{
    int get_biggest_region(vector< vector<int> > grid)
    {
        if (grid.empty() || grid.front().empty())
            return 0;

        vector< vector<bool> > visited(grid.size());
        for (int i = 0; i < grid.size(); ++i)
            visited[i] = vector<bool>(grid.front().size(), false);

        int region = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.front().size(); ++i) {
                queue<pair<int, int>> toCheckQueue;
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
                    if (grid[i][j] == 1)
                        ++current;

                    auto left = element.second > 0;
                    auto up = element.first > 0;
                    auto right = element.first < grid.front().size() - 1;
                    auto down = element.second < grid.size() - 1;

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
