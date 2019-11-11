//https://leetcode.com/problems/time-based-key-value-store/
#ifndef ALGORITHMICCHALLENGES_981_TIMEBASEDKEYVALUESTOR_H
#define ALGORITHMICCHALLENGES_981_TIMEBASEDKEYVALUESTOR_H

#include <string>
#include <vector>
#include <unordered_map>


class TimeMap {
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> vals;
    static const std::string empty;

public:
    void set(std::string key, std::string value, int timestamp) {
        vals[std::move(key)].emplace_back(timestamp, std::move(value));
    }

    const std::string& get(const std::string& key, int timestamp) const {
        auto valIt = vals.find(key);
        if (valIt == end(vals))
            return empty;
        auto timestampIt = std::upper_bound(begin(valIt->second), end(valIt->second), std::make_pair(timestamp, ""),
            [](const auto& a, const auto& b){ return a.first < b.first; });
        if (timestampIt != begin(valIt->second))
            return (--timestampIt)->second;
        return empty;
    }
};

const std::string TimeMap::empty;

#endif //ALGORITHMICCHALLENGES_981_TIMEBASEDKEYVALUESTOR_H
