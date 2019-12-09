//https://leetcode.com/problems/candy/
#ifndef ALGORITHMICCHALLENGES_135_CANDY_H
#define ALGORITHMICCHALLENGES_135_CANDY_H

#include <vector>
#include <map>
#include <numeric>
using namespace std;

int candy(const vector<int>& ratings) {
    map<int, vector<size_t>> ratingPositions;
    for (size_t i = 0; i < ratings.size(); ++i)
        ratingPositions[ratings[i]].push_back(i);
    vector<int> candies(ratings.size(), 0);
    for (const auto& rating : ratingPositions) {
        for (auto pos : rating.second) {
            int childCandies = 1;
            if (pos != 0 && candies[pos - 1] != 0 && ratings[pos - 1] != rating.first)
                childCandies = candies[pos - 1] + 1;
            if (pos != ratings.size() - 1 && candies[pos + 1] != 0 && childCandies <= candies[pos + 1])
                childCandies = candies[pos + 1] + 1;
            candies[pos] = childCandies;
        }
    }
    return accumulate(begin(candies), end(candies), 0);
}

int getProgressionSum(bool prevProgressionEndsWithOne, bool growingProgression, int progressionSize) {
    int firstNumber = 1;
    if (growingProgression && prevProgressionEndsWithOne)
        firstNumber = 2;
    int lastNumber = firstNumber + (progressionSize - 1);
    return ((firstNumber + lastNumber) * progressionSize) / 2;
}

int candyLinear(const vector<int>& ratings) {
    if (ratings.empty())
        return 0;
    int progressionSize = 1;
    size_t candies = 0;
    bool growingProgression = false;
    bool prevProgressionEndsWithOne = false;
    int prevProgressionSize = 0;
    for (auto ratingIt = begin(ratings) + 1; ratingIt != end(ratings); ++ratingIt) {
        if (progressionSize == 1) {
            if (*ratingIt > *(ratingIt - 1)) {
                growingProgression = true;
                ++progressionSize;
            } else if (*ratingIt < *(ratingIt - 1)) {
                growingProgression = false;
                ++progressionSize;
            } else { //equal
                candies += 1;
                prevProgressionEndsWithOne = true;
                prevProgressionSize = 1;
            }
        } else {
            if ((growingProgression && *ratingIt > *(ratingIt - 1)) ||
                (!growingProgression && *ratingIt < *(ratingIt - 1))) {
                ++progressionSize;
            } else {
                candies += getProgressionSum(prevProgressionEndsWithOne, growingProgression, progressionSize);
                if (!growingProgression) {
                    if (prevProgressionSize != 0 && progressionSize >= prevProgressionSize)
                        candies += (progressionSize - prevProgressionSize + 1);
                    prevProgressionEndsWithOne = true;
                }
                prevProgressionSize = progressionSize;
                progressionSize = 1;
                growingProgression = *ratingIt > *(ratingIt - 1);
            }
        }
    }
    candies += getProgressionSum(prevProgressionEndsWithOne, growingProgression, progressionSize);
    if (!growingProgression) {
        if (prevProgressionSize != 0 && progressionSize >= prevProgressionSize)
            candies += (progressionSize - prevProgressionSize + 1);
    }
    return candies;
}

int candyTwoArrays(const vector<int>& ratings) {
    if (ratings.size() < 2)
        return ratings.size();
    vector<int> leftToRight(ratings.size(), 1);
    auto rightToLeft = leftToRight;
    {
        auto candiesIt = begin(leftToRight) + 1;
        for (auto ratingIt = begin(ratings) + 1;
             ratingIt != end(ratings);
             ++ratingIt, ++candiesIt) {
            if (*ratingIt > *(ratingIt - 1))
                *candiesIt = *(candiesIt - 1) + 1;
        }
    }
    {
        auto candiesIt = rbegin(rightToLeft) + 1;
        for (auto ratingIt = rbegin(ratings) + 1;
             ratingIt != rend(ratings);
             ++ratingIt, ++candiesIt) {
            if (*ratingIt > *(ratingIt - 1))
                *candiesIt = *(candiesIt - 1) + 1;
        }
    }
    int totalCandies = 0;
    for (auto left = begin(leftToRight), right = begin(rightToLeft); left != end(leftToRight); ++left, ++right)
        totalCandies += max(*left, *right);
    return totalCandies;
}

#endif //ALGORITHMICCHALLENGES_135_CANDY_H
