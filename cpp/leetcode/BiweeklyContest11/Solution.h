//https://leetcode.com/contest/biweekly-contest-11
#ifndef ALGORITHMICCHALLENGES_SOLUTION_H
#define ALGORITHMICCHALLENGES_SOLUTION_H
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <algorithm>
#include <array>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int missingNumber(const vector<int>& arr) {
    if (arr.size() == 3) {
        auto firstDiff = arr[1] - arr[0];
        auto secondDiff = arr[2] - arr[1];
        if ((arr[0] + 2*secondDiff) == arr[1])
            return arr[0] + secondDiff;
        return arr[1] + firstDiff;
    }

    int correctDiff = std::numeric_limits<int>::max();
    std::array<int, 3> diffs{arr[1] - arr[0], arr[2] - arr[1], arr[3]-arr[2]};
    for (std::size_t i = 0; i < 3; ++i) {
        for (std::size_t j = 0; j < 3; ++j) {
            if (i == j)
                continue;
            if (diffs[i] == diffs[j]) {
                correctDiff = diffs[i];
                break;
            }
        }
        if (correctDiff != std::numeric_limits<int>::max())
            break;
    }

    for (std::size_t i = 1; i < arr.size(); ++i) {
        if ((arr[i] - arr[i - 1]) != correctDiff)
            return arr[i - 1] + correctDiff;
    }
}

vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
    std::sort(begin(slots1), end(slots1));
    std::sort(begin(slots2), end(slots2));
    auto it1 = begin(slots1);
    auto it2 = begin(slots2);
    for (;it1 != end(slots1) && it2 != end(slots2);) {
        int commonBegin = std::max(it1->front(), it2->front());
        int commonEnd = std::min(it1->back(), it2->back());
        if ((commonEnd - commonBegin) >= duration)
            return {commonBegin, commonBegin + duration};
        if (it1->back() < it2->back())
            ++it1;
        else
            ++it2;
    }
    return {};
}

double probabilityOfHeads(const vector<double>& prob, int target) {
    std::vector<std::vector<double>> probabilities;
    probabilities.resize(prob.size() + 1);
    for (auto& probability : probabilities)
        probability.resize(target + 1, 0);
    probabilities[0][0] = 1;
    for (int i = 1; i <= prob.size(); ++i)
        for (int j = 0; j <= target && j <= i; ++j)
            if (j == 0)
                probabilities[i][j] = probabilities[i - 1][j] * (1.0 - prob[i - 1]);
            else if (j == i)
                probabilities[i][j] = probabilities[i - 1][j - 1] * prob[i - 1];
            else
                probabilities[i][j] = probabilities[i - 1][j] * (1.0 - prob[i - 1]) + probabilities[i - 1][j - 1] * prob[i - 1];
    return probabilities.back().back();
}

#endif //ALGORITHMICCHALLENGES_SOLUTION_H
