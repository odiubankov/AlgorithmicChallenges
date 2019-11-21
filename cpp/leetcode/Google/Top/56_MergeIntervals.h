//https://leetcode.com/problems/merge-intervals/
#ifndef ALGORITHMICCHALLENGES_56_MERGEINTERVALS_H
#define ALGORITHMICCHALLENGES_56_MERGEINTERVALS_H

#include <vector>
#include <map>

std::vector<std::vector<int>> merge(const std::vector<std::vector<int>>& intervals) {
    std::map<int, int> begins, ends;
    for (const auto& interval : intervals) {
        bool merged = false;
        auto beginIt = begins.lower_bound(interval.front());
        while (beginIt != end(begins) && beginIt->first <= interval.back()) {
            merged = true;
            auto beginVal = beginIt->first;
            int endToUpdate = beginIt->second;
            if (beginIt == begin(begins)) {
                ends[endToUpdate] = interval.front();
                begins[interval.front()] = endToUpdate;
            } else {
                auto prevInterval = beginIt;
                --prevInterval;
                if (prevInterval->second >= interval.front()) {
                    int prevIntervalEnd = prevInterval->second;
                    ends[endToUpdate] = prevInterval->first;
                    ends.erase(prevIntervalEnd);
                    prevInterval->second = endToUpdate;
                } else {
                    begins[interval.front()] = endToUpdate;
                    ends[endToUpdate] = interval.front();
                }
            }
            if (beginVal != interval.front())
                begins.erase(beginVal);
            beginIt = begins.upper_bound(interval.front());
        }

        auto endIt = ends.lower_bound(interval.front());
        while (endIt != end(ends) && endIt->first <= interval.back()) {
            merged = true;
            int endVal = endIt->first;
            int beginToUpdate = endIt->second;
            if (endIt == --end(ends)) {
                begins[beginToUpdate] = interval.back();
                ends[interval.back()] = beginToUpdate;
            } else {
                auto nextInterval = endIt;
                ++nextInterval;
                if (nextInterval->second <= interval.back()) {
                    int nextIntervalBegin = nextInterval->second;
                    begins[beginToUpdate] = nextInterval->first;
                    begins.erase(nextIntervalBegin);
                    nextInterval->second = beginToUpdate;
                } else {
                    ends[interval.back()] = beginToUpdate;
                    begins[beginToUpdate] = interval.back();
                }
            }
            if (endVal != interval.back())
                ends.erase(endVal);
            auto endIt = ends.lower_bound(interval.front());
            if (endIt->first == interval.back())
                break;
        }

        if (!merged) {
            if (endIt == end(ends) || interval.front() < endIt->second) {
                begins[interval.front()] = interval.back();
                ends[interval.back()] = interval.front();
            }
        }
    }

    assert(begins.size() == ends.size());
    std::vector<std::vector<int>> result;
    result.reserve(begins.size());
    for (const auto& pair : begins) {
        std::vector<int> interval;
        interval.reserve(2);
        interval.push_back(pair.first);
        interval.push_back(pair.second);
        result.push_back(std::move(interval));
    }

    return result;
}

std::vector<std::vector<int>> mergeSimple(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty())
        return {};
    std::sort(begin(intervals), end(intervals));
    std::vector<std::vector<int>> result;
    auto it = begin(intervals);
    result.push_back(std::move(*it));
    ++it;
    for (;it != end(intervals); ++it)
        if (it->front() <= result.back().back()) {
            if (it->back() > result.back().back())
                result.back().back() = it->back();
        } else
            result.push_back(std::move(*it));
    return result;
}

#endif //ALGORITHMICCHALLENGES_56_MERGEINTERVALS_H
