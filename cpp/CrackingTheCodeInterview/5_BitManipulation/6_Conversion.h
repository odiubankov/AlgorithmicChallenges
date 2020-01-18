//https://leetcode.com/problems/hamming-distance/
#ifndef ALGORITHMICCHALLENGES_6_CONVERSION_H
#define ALGORITHMICCHALLENGES_6_CONVERSION_H

class SolutionHammingDistance {
public:
    int hammingDistance(int x, int y) {
        int xorRes = x ^ y;
        int res = 0;
        for (int i = 0; i < sizeof(x) * 8; ++i)
            if (xorRes & (1 << i))
                ++res;
        return res;
    }
};

#endif //ALGORITHMICCHALLENGES_6_CONVERSION_H
