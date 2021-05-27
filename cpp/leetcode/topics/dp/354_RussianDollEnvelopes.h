// https://leetcode.com/problems/russian-doll-envelopes/description/

#ifndef ALGORITHMICCHALLENGES_354_RUSSIANDOLLENVELOPES_H
#define ALGORITHMICCHALLENGES_354_RUSSIANDOLLENVELOPES_H

#include <vector>
#include <algorithm>
#include <map>

// n^2
int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
    if (envelopes.empty())
        return 0;

    std::multimap<int, size_t> prevHeight;
    std::sort(begin(envelopes), end(envelopes));
    vector<int> insideCnt(envelopes.size(), 0);
    int res = 1;
    for (size_t i = 0; i != envelopes.size(); ++i) {
        for (auto prevIt = begin(prevHeight);
             prevIt != end(prevHeight) && prevIt->first < envelopes[i].back();
             ++prevIt) {

            if (envelopes[i].front() != envelopes[prevIt->second].front()) {
                insideCnt[i] = std::max(insideCnt[i], insideCnt[prevIt->second] + 1);
                res = std::max(res, insideCnt[i] + 1);
            }
        }

        prevHeight.emplace(envelopes[i].back(), i);
    }

    return res;
}

// nLogN
int maxEnvelopesNLogN(std::vector<std::vector<int>>& envelopes) {
    if (envelopes.empty())
        return 0;

    std::sort(begin(envelopes), end(envelopes),
              [](const auto& l, const auto& r) {
        if (l.front() == r.front())
            return l.back() > r.back();
        return l.front() < r.front();
    });

    std::vector<int> heights;
    for (const auto& envelope : envelopes) {
        auto heightIt = std::lower_bound(begin(heights), end(heights), envelope.back());
        if (heightIt == end(heights)) {
            heights.push_back(envelope.back());
        } else {
            *heightIt = envelope.back();
        }
    }
    return heights.size();
}

#endif //ALGORITHMICCHALLENGES_354_RUSSIANDOLLENVELOPES_H
