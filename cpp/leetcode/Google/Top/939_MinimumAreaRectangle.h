//https://leetcode.com/problems/minimum-area-rectangle/
#ifndef ALGORITHMICCHALLENGES_939_MINIMUMAREARECTANGLE_H
#define ALGORITHMICCHALLENGES_939_MINIMUMAREARECTANGLE_H

#include <vector>
#include <limits>
#include <algorithm>
#include <unordered_map>
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

#endif //ALGORITHMICCHALLENGES_939_MINIMUMAREARECTANGLE_H
