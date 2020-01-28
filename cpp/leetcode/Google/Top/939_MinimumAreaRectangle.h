//https://leetcode.com/problems/minimum-area-rectangle/
#ifndef ALGORITHMICCHALLENGES_939_MINIMUMAREARECTANGLE_H
#define ALGORITHMICCHALLENGES_939_MINIMUMAREARECTANGLE_H

#include <vector>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void eraseDuplicates(vector<int>& vals) {
    sort(begin(vals), end(vals));
    vals.erase(unique( begin(vals), end(vals)), end(vals));
}

int minAreaRect(const vector<vector<int>>& points) {
    unordered_map<int,vector<int>> xMap, yMap;
    for (auto& point : points) {
        xMap[point.front()].push_back(point.back());
        yMap[point.back()].push_back(point.front());
    }

    for (auto& val : xMap)
        eraseDuplicates(val.second);

    for (auto& val : yMap)
        eraseDuplicates(val.second);

    bool rectFound = false;
    int minArea = numeric_limits<int>::max();
    for (const auto& xVal : xMap) {
        for (auto yFirstIt = begin(xVal.second); yFirstIt != end(xVal.second); ++yFirstIt) {
            auto ySecondIt = yFirstIt;
            ++ySecondIt;
            for (;ySecondIt != end(xVal.second); ++ySecondIt) {
                auto xFirstIt = begin(yMap[*yFirstIt]);
                auto xSecondIt = begin(yMap[*ySecondIt]);
                while (xFirstIt != end(yMap[*yFirstIt]) && xSecondIt != end(yMap[*ySecondIt])) {
                    if (*xFirstIt < *xSecondIt || *xFirstIt == xVal.first) {
                        ++xFirstIt;
                    } else if (*xSecondIt < *xFirstIt || *xSecondIt == xVal.first) {
                        ++xSecondIt;
                    } else {
                        rectFound = true;
                        int area = abs(*xFirstIt - xVal.first) * abs(*yFirstIt - *ySecondIt);
                        if (area < minArea)
                            minArea = area;
                        ++xFirstIt;
                        ++xSecondIt;
                    }
                }
            }
        }
    }
    return rectFound ? minArea : 0;
}

struct VectorHash {
    std::hash<int> hasher;
    size_t operator()(const std::vector<int>& v) const {
        return hasher(v.front()) ^ hasher(v.back());
    }
};

int minAreaRectDiagonal(vector<vector<int>>& points) {
    unordered_set<vector<int>, VectorHash> pointsHashSet;
    for (auto& point : points)
        pointsHashSet.insert(point);
    
    int minAreRect = 0;

    for (auto point1It = begin(points); point1It != end(points); ++point1It) {
        for (auto point2It = point1It + 1; point2It != end(points); ++point2It) {
            if (point1It->front() != point2It->front() && 
                point1It->back() != point2It->back()) {
                if (pointsHashSet.find({point1It->front(), point2It->back()}) != end(pointsHashSet) && 
                    pointsHashSet.find({point2It->front(), point1It->back()}) != end(pointsHashSet)) {
                    int area = abs(point1It->front() - point2It->front()) * abs(point1It->back() - point2It->back());
                    if (minAreRect == 0) {
                        minAreRect = area;
                    } else {
                        minAreRect = min(minAreRect, area);
                    }
                }
            }
        }
    }

    return minAreRect;
}

#endif //ALGORITHMICCHALLENGES_939_MINIMUMAREARECTANGLE_H
