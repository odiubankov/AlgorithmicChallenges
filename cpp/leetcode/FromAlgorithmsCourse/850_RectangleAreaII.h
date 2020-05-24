//https://leetcode.com/problems/rectangle-area-ii/
#ifndef ALGORITHMICCHALLENGES_850_RECTANGLEAREAII_H
#define ALGORITHMICCHALLENGES_850_RECTANGLEAREAII_H

#include <vector>
#include <queue>
#include <limits>
#include <map>
#include <set>

using namespace std;

using RectangleT = vector<int>;
struct RectangleBeginComp {
    bool operator()(RectangleT const* r1, RectangleT const* r2) const noexcept {
        return (r1->front() > r2->front());
    }
};
using RectBeginQueueT = priority_queue<RectangleT const*, vector<RectangleT const*>, RectangleBeginComp>;

struct RectangleEndComp {
    bool operator()(RectangleT const* r1, RectangleT const* r2) const noexcept {
        return (r1->at(2) > r2->at(2));
    }
};
using RectEndQueueT = priority_queue<RectangleT const*, vector<RectangleT const*>, RectangleEndComp>;

using IsBeginT = bool;
using AreaHeightT = multiset<pair<int, IsBeginT>>;
auto constexpr MODULO = 1000000007;//10^9 + 7
using AreaT = unsigned long long;

void addRect(
        AreaHeightT& areaHeight,
        RectBeginQueueT& rectBeginQueue,
        RectEndQueueT& rectEndQueue) {
    areaHeight.insert(make_pair(rectBeginQueue.top()->at(1), true));
    areaHeight.insert(make_pair(rectBeginQueue.top()->at(3), false));
    rectEndQueue.push(rectBeginQueue.top());
    rectBeginQueue.pop();
}

void removeRect(
        AreaHeightT& areaHeight,
        RectEndQueueT& rectEndQueue) {
    areaHeight.erase(areaHeight.find(make_pair(rectEndQueue.top()->at(1), true)));
    areaHeight.erase(areaHeight.find(make_pair(rectEndQueue.top()->at(3), false)));
    rectEndQueue.pop();
}

AreaT getHeight(AreaHeightT const& areaHeight) {
    if (areaHeight.empty())
        return 0;
    AreaT totalHeight = 0;
    AreaT heightBegin = 0;
    int rectsCnt = 0;
    for (auto& height : areaHeight) {
        if (rectsCnt == 0) {
            heightBegin = height.first;
        }
        if (height.second) {
            ++rectsCnt;
        } else {
            --rectsCnt;
        }

        if (rectsCnt == 0) {
            AreaT heightEnd = height.first;
            totalHeight += (heightEnd - heightBegin);
        }
    }

    return totalHeight;
}

int rectangleArea(vector<RectangleT> const& rectangles) {
    if (rectangles.empty())
        return 0;
    RectBeginQueueT rectBeginQueue;
    for (auto& rect : rectangles) {
        rectBeginQueue.push(&rect);
    }
    RectEndQueueT rectEndQueue;
    AreaHeightT areaHeight;
    AreaT areaBegin = rectBeginQueue.top()->front();
    while (!rectBeginQueue.empty() && areaBegin == rectBeginQueue.top()->front()) {
        addRect(areaHeight, rectBeginQueue, rectEndQueue);
    }

    AreaT height = getHeight(areaHeight);
    AreaT area = 0;
    while (!rectBeginQueue.empty() || !rectEndQueue.empty()) {
        AreaT areaEnd = numeric_limits<int>::max();
        if (!rectBeginQueue.empty()) {
            areaEnd = rectBeginQueue.top()->front();
        }
        if (!rectEndQueue.empty()) {
            areaEnd = min<AreaT>(areaEnd, rectEndQueue.top()->at(2));
        }
        area += (areaEnd - areaBegin) * height;
        area %= MODULO;
        areaBegin = areaEnd;
        while (!rectBeginQueue.empty() && areaBegin == rectBeginQueue.top()->front()) {
            addRect(areaHeight, rectBeginQueue, rectEndQueue);
        }
        while (!rectEndQueue.empty() && areaBegin == rectEndQueue.top()->at(2)) {
            removeRect(areaHeight, rectEndQueue);
        }
        height = getHeight(areaHeight);
    }
    return area;
}

#endif //ALGORITHMICCHALLENGES_850_RECTANGLEAREAII_H
