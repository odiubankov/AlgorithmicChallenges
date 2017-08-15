/*
* DFS: Connected Cell in a Grid
*
* Cracking the Coding Interview Challenges
* https://www.hackerrank.com/domains/tutorials/cracking-the-coding-interview
*
* Copyright 2017 Oleksii Diubankov
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef HACKERRANK_CONNECTEDCELLINGRID_H
#define HACKERRANK_CONNECTEDCELLINGRID_H

#include <vector>
#include <queue>
#include <set>
#include <cassert>
#include <iostream>

namespace hackerrank
{

int get_biggest_region(std::vector<std::vector<int> > grid)
{
    if (grid.empty() || grid.front().empty())
        return 0;

    std::vector<std::vector<bool> > visited(grid.size());
    for (std::size_t i = 0; i < grid.size(); ++i)
        visited[i] = std::vector<bool>(grid.front().size(), false);

    int region = 0;
    for (std::size_t i = 0; i < grid.size(); ++i) {
        for (std::size_t j = 0; j < grid.front().size(); ++j) {
            std::queue<std::pair<size_t, size_t>> toCheckQueue;
            toCheckQueue.emplace(i, j);
            int current = 0;
            while (!toCheckQueue.empty()) {
                auto &element = toCheckQueue.front();
                if (visited[element.first][element.second]) {
                    toCheckQueue.pop();
                    continue;
                }

                visited[element.first][element.second] = true;
                if (grid[element.first][element.second] == 1) {
                    ++current;
                }
                else {
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

}//namespace hackerrank

#endif //HACKERRANK_CONNECTEDCELLINGRID_H
