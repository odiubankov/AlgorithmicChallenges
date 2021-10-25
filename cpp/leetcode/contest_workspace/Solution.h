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
#include <bitset>
#include <sstream>
#include <numeric>

using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
        tokens.push_back(token);
    return tokens;
}

using ItemsT = vector<int>;
using ItemItT = ItemsT::iterator;

bool canBeIncreasingImpl(long long prevVal, ItemItT item, ItemItT itemE, bool canSkip) {
    if (item == itemE)
        return true;

    if (canSkip) {
        if (*item > prevVal && canBeIncreasingImpl(*item, item + 1, itemE, true))
            return true;
        if (canBeIncreasingImpl(prevVal, item + 1, itemE, false))
            return true;
    } else {
        if (*item <= prevVal)
            return false;
        else
            return canBeIncreasingImpl(*item, item + 1, itemE, false);
    }
    return false;
}

bool canBeIncreasing(ItemsT& nums) {
    return canBeIncreasingImpl(numeric_limits<long long>::min(), begin(nums), end(nums), true);
}

string removeOccurrences(string s, string part) {
    int foundPos = s.find(part, 0);
    while (foundPos != string::npos) {
        string newS = s.substr(0, foundPos);
        newS.append(s.substr(foundPos + part.size()));
        s = std::move(newS);
        foundPos = s.find(part, max<int>(0, foundPos - part.size() + 1));
    }
    return s;
}

using ItemsT = vector<int>;
using IterT = ItemsT::iterator;
using CacheT = vector<unordered_map<long long, unordered_map<long long, long long>>>;
long long maxAltSum(bool pos, IterT it, IterT itE, long long posSum, long long negSum, CacheT& cachePos, CacheT& cacheNeg) {
    int dist = distance(it, itE);
    CacheT* rightCache;
    if (pos) {
        rightCache = &cachePos;
    } else {
        rightCache = &cacheNeg;
    }

    auto cacheIt1 = (*rightCache)[dist].find(posSum);
    if (cacheIt1 != end((*rightCache)[dist])) {
        auto cache2It = cacheIt1->second.find(negSum);
        if (cache2It != end(cacheIt1->second))
            return cache2It->second;
    }

    if (it == itE)
        return posSum - negSum;

    long long maxRes = 0;
    if (pos) {
        auto res = maxAltSum(true, it + 1, itE, posSum, negSum, cachePos, cacheNeg);
        maxRes = max(maxRes, res);
        res = maxAltSum(false, it + 1, itE, posSum + *it, negSum, cachePos, cacheNeg);
        maxRes = max(maxRes, res);
    } else {
        auto res = maxAltSum(false, it + 1, itE, posSum, negSum, cachePos, cacheNeg);
        maxRes = max(maxRes, res);
        res = maxAltSum(true, it + 1, itE, posSum, negSum + *it, cachePos, cacheNeg);
        maxRes = max(maxRes, res);
    }

    (*rightCache)[dist][posSum][negSum] = maxRes;
    return maxRes;
}

long long maxAlternatingSum(vector<int>& nums) {
    CacheT cachePos(nums.size() + 1);
    CacheT cacheNeg(nums.size() + 1);
    return maxAltSum(true, begin(nums), end(nums), 0, 0, cachePos, cacheNeg);
}

#endif //ALGORITHMICCHALLENGES_SOLUTION_H
