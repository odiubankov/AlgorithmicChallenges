//https://leetcode.com/problems/bulls-and-cows/
#ifndef ALGORITHMICCHALLENGES_299_BULLSANDCOWS_H
#define ALGORITHMICCHALLENGES_299_BULLSANDCOWS_H

#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

string getHint(const string& secret, const string& guess) {
    unordered_map<char, int> charCnt;
    for (auto c : secret)
        ++charCnt[c];
    int bulls = 0;
    for (size_t i = 0; i < guess.length() && i < secret.length(); ++i) {
        if (guess[i] == secret[i]) {
            ++bulls;
            --charCnt[guess[i]];
        }
    }
    int cows = 0;
    for (size_t i = 0; i < guess.length(); ++i) {
        if (((i < secret.length() && guess[i] != secret[i]) || i >= secret.length()) && charCnt[guess[i]] > 0) {
            --charCnt[guess[i]];
            ++cows;
        }
    }
    std::ostringstream ss;
    ss << bulls << "A" << cows << "B";
    return ss.str();
}

#endif //ALGORITHMICCHALLENGES_299_BULLSANDCOWS_H
