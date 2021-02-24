//https://leetcode.com/problems/rectangle-area-ii/
// line sweep algorithm
#ifndef ALGORITHMICCHALLENGES_850_RECTANGLEAREAII_H
#define ALGORITHMICCHALLENGES_850_RECTANGLEAREAII_H

#include <vector>
#include <map>

using namespace std;

using RectangleT = vector<int>;

enum class VerticalSide {
    Left,
    Right
};

enum class HorizontalSide {
    Top,
    Bottom
};

struct RectEdge {
    long long yBottom = 0;
    long long yTop = 0;
    VerticalSide side = VerticalSide::Left;
};

int rectangleArea(vector<RectangleT> const& rectangles) {
    multimap<long long, RectEdge> xPos;
    for (auto& rect : rectangles) {
        xPos.emplace(rect[0], RectEdge {rect[1], rect[3], VerticalSide::Left} );
        xPos.emplace(rect[2], RectEdge {rect[1], rect[3], VerticalSide::Right});
    }

    long long totalArea = 0;
    multimap<long long, HorizontalSide> yPos;
    auto xIt = begin(xPos);
    yPos.emplace(xIt->second.yBottom, HorizontalSide::Bottom);
    yPos.emplace(xIt->second.yTop, HorizontalSide::Top);
    long long prevX = xIt->first;
    long long currentHeight = xIt->second.yTop - xIt->second.yBottom;
    ++xIt;
    for (;xIt != end(xPos); ++xIt) {
        if (xIt->second.side == VerticalSide::Left) {
            yPos.emplace(xIt->second.yBottom, HorizontalSide::Bottom);
            yPos.emplace(xIt->second.yTop, HorizontalSide::Top);
        } else {
            auto yIt = yPos.find(xIt->second.yBottom);
            while (yIt->second != HorizontalSide::Bottom)
                ++yIt;
            yPos.erase(yIt);
            yIt = yPos.find(xIt->second.yTop);
            while (yIt->second != HorizontalSide::Top)
                ++yIt;
            yPos.erase(yIt);
        }

        totalArea += currentHeight * (xIt->first - prevX);
        totalArea %= 1000000007;
        prevX = xIt->first;

        currentHeight = 0;
        if (!yPos.empty()) {
            int segmentsCnt = 1;
            auto yIt = begin(yPos);
            long long yBegin = yIt->first;
            ++yIt;
            for (; yIt != end(yPos); ++yIt) {
                if (yIt->second == HorizontalSide::Bottom) {
                    if (segmentsCnt == 0) {
                        yBegin = yIt->first;
                    }
                    ++segmentsCnt;
                } else { // yIt->second == HorizontalSide::Top
                    --segmentsCnt;
                    if (segmentsCnt == 0) {
                        currentHeight += (yIt->first - yBegin);
                    }
                }
            }
        }
    }

    return totalArea;
}

#endif //ALGORITHMICCHALLENGES_850_RECTANGLEAREAII_H
