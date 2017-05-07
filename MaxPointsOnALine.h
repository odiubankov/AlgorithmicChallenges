//https://leetcode.com/problems/max-points-on-a-line/#/description
/*
 Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 */

#ifndef LEETCODESOLUTIONS_MAXPOINTSONALINE_H
#define LEETCODESOLUTIONS_MAXPOINTSONALINE_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

namespace maxpointsonaline
{

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() < 3)
            return points.size();

        int maxPointsOnLine = 2;
        int i = 0;
        while (i < points.size() - 2)
        {
            int equalPointsCnt = 0;
            unordered_map<double, int> slopePoints;
            for (int j = i + 1; j < points.size(); ++j)
            {
                auto slope = std::numeric_limits<double>::infinity();
                if (points[i].x == points[j].x)
                {
                    if (points[i].y == points[j].y)
                    {
                        ++equalPointsCnt;
                        continue;
                    }
                }
                else
                {
                    slope = static_cast<double>(points[i].y - points[j].y)/ static_cast<double>(points[i].x - points[j].x);
                }

                auto emplaceRes = slopePoints.emplace(slope, 2);
                if (!emplaceRes.second)
                {
                    ++emplaceRes.first->second;
                }
            }

            if (slopePoints.empty())
            {
                if (equalPointsCnt + 1 > maxPointsOnLine)
                {
                    maxPointsOnLine = equalPointsCnt + 1;
                }
            }
            else
            {
                for (const auto& slope: slopePoints)
                {
                    if (slope.second + equalPointsCnt > maxPointsOnLine)
                    {
                        maxPointsOnLine = slope.second + equalPointsCnt;
                    }
                }
            }

            ++i;
        }


        return maxPointsOnLine;
    }
};
}

#endif //LEETCODESOLUTIONS_MAXPOINTSONALINE_H
