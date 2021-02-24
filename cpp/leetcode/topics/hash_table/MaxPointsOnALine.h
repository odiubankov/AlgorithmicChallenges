/**
* https://leetcode.com/problems/max-points-on-a-line/#/description
*
* Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*
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

#ifndef LEETCODESOLUTIONS_MAXPOINTSONALINE_H
#define LEETCODESOLUTIONS_MAXPOINTSONALINE_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>

namespace leetcode
{

class Solution
{
public:
    std::size_t maxPoints(std::vector<std::vector<int>> const& points) {
        if (points.size() < 3)
            return points.size();

        std::size_t maxPointsOnLine = 2;
        for (auto p1It = begin(points); p1It != (end(points) - 1); ++p1It) {
            size_t equalPointsCnt = 0;
            std::unordered_map<long double, int> slopePoints;
            for (auto p2It = p1It + 1; p2It != end(points); ++p2It) {
                if (*p2It == *p1It) {
                    ++equalPointsCnt;
                    continue;
                }

                auto slope = std::numeric_limits<long double>::infinity();
                if (p1It->front() != p2It->front()) {
                    slope = static_cast<long double>(p1It->back() - p2It->back())
                            / static_cast<long double>(p1It->front() - p2It->front());
                }

                ++slopePoints[slope];
            }

            int maxSlopePoints = 0;
            for (auto& slopePointsCnt : slopePoints) {
                maxSlopePoints = std::max(maxSlopePoints, slopePointsCnt.second);
            }

            maxPointsOnLine = std::max(maxPointsOnLine, maxSlopePoints + equalPointsCnt + 1);
        }

        return maxPointsOnLine;
    }
};

}//namespace leetcode

#endif //LEETCODESOLUTIONS_MAXPOINTSONALINE_H
