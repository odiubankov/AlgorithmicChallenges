//https://leetcode.com/problems/reverse-integer/
#ifndef ALGORITHMICCHALLENGES_7_REVERSEINTEGER_H
#define ALGORITHMICCHALLENGES_7_REVERSEINTEGER_H
#include <limits>
#include <cstdlib>
using namespace std;

int reverse(int x) {
    long long reversedVal = 0;
    bool negative = x < 0;
    auto lx = abs(static_cast<long long>(x));
    while (lx) {
        auto digit = lx % 10;
        reversedVal *= 10;
        reversedVal += digit;
        lx /= 10;
    }
    if (negative)
        reversedVal = -reversedVal;
    if (reversedVal > numeric_limits<int>::max() || reversedVal < numeric_limits<int>::min())
        reversedVal = 0;
    return static_cast<int>(reversedVal);
}

#endif //ALGORITHMICCHALLENGES_7_REVERSEINTEGER_H
