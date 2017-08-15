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

namespace leetcode
{

struct Point
{
    int x{0};
    int y{0};

    Point(int a, int b)
        : x(a), y(b)
    {}
};

class Solution
{
public:
    unsigned long maxPoints(std::vector<Point> &points)
    {
        if (points.size() < 3)
            return points.size();

        unsigned long maxPointsOnLine = 2;
        int i = 0;
        while (i < points.size() - 2) {
            unsigned long equalPointsCnt = 0;
            std::unordered_map<long double, int> slopePoints;
            for (int j = i + 1; j < points.size(); ++j) {
                auto slope = std::numeric_limits<long double>::infinity();
                if (points[i].x == points[j].x) {
                    if (points[i].y == points[j].y) {
                        ++equalPointsCnt;
                        continue;
                    }
                }
                else {
                    slope = static_cast<long double>(points[i].y - points[j].y)
                        / static_cast<long double>(points[i].x - points[j].x);
                }

                auto emplaceRes = slopePoints.emplace(slope, 2);
                if (!emplaceRes.second) {
                    ++emplaceRes.first->second;
                }
            }

            if (slopePoints.empty()) {
                if (equalPointsCnt + 1 > maxPointsOnLine) {
                    maxPointsOnLine = equalPointsCnt + 1;
                }
            }
            else {
                for (const auto &slope: slopePoints) {
                    if (slope.second + equalPointsCnt > maxPointsOnLine) {
                        maxPointsOnLine = slope.second + equalPointsCnt;
                    }
                }
            }

            ++i;
        }


        return maxPointsOnLine;
    }
};

}//namespace leetcode

#endif //LEETCODESOLUTIONS_MAXPOINTSONALINE_H
