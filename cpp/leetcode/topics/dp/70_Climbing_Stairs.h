// https://leetcode.com/problems/climbing-stairs/description/
#ifndef ALGORITHMICCHALLENGES_70_CLIMBING_STAIRS_H
#define ALGORITHMICCHALLENGES_70_CLIMBING_STAIRS_H

unordered_map<int, int> possibilitiesCnt;
int climbStairs(int n) {
    auto resIt = possibilitiesCnt.find(n);
    if (resIt != end(possibilitiesCnt))
        return resIt->second;
    int res = 0;
    if (n == 1)
        res = 1;
    else if (n == 2)
        res = 2;
    else if (n > 2)
        res = climbStairs(n - 1) + climbStairs(n - 2);
    possibilitiesCnt[n] = res;
    return res;
}

#endif //ALGORITHMICCHALLENGES_70_CLIMBING_STAIRS_H
