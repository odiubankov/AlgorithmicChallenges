//https://leetcode.com/contest/biweekly-contest-13/problems/encode-number/
#ifndef ALGORITHMICCHALLENGES_1256_ENCODENUMBER_H
#define ALGORITHMICCHALLENGES_1256_ENCODENUMBER_H

#include <string>
#include <bitset>
using namespace std;

string encode(int num) {
    auto s = std::bitset< 64 >( num + 1 ).to_string();
    return s.substr(s.find('1') + 1);
}

#endif //ALGORITHMICCHALLENGES_1256_ENCODENUMBER_H
