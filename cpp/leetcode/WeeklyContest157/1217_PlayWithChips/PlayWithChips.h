#ifndef ALGORITHMICCHALLENGES_PLAYWITHCHIPS_H
#define ALGORITHMICCHALLENGES_PLAYWITHCHIPS_H

#include <vector>
#include <unordered_map>

class SolutionPlayWithChips {
public:
    int minCostToMoveChips(const std::vector<int>& chips) {
        std::unordered_map<int, int> chipsAtPosition;
        for (auto i : chips)
            ++chipsAtPosition[i];

        auto oddCnt = 0;
        auto evenCnt = 0;
        for (const auto& posChips : chipsAtPosition) {
            if (posChips.first % 2 == 0)
                evenCnt += posChips.second;
            else
                oddCnt += posChips.second;
        }

        return std::min(oddCnt, evenCnt);
    }
};

#endif //ALGORITHMICCHALLENGES_PLAYWITHCHIPS_H
