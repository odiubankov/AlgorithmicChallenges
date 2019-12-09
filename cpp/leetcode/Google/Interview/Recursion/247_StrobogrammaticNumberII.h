//https://leetcode.com/problems/strobogrammatic-number-ii/
#ifndef ALGORITHMICCHALLENGES_247_STROBOGRAMMATICNUMBERII_H
#define ALGORITHMICCHALLENGES_247_STROBOGRAMMATICNUMBERII_H

#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

using DigitsT = vector<char>;

void growCombinations(vector<string>& digitCombinations, const DigitsT& newDigits) {
    if (digitCombinations.empty()) {
        for (auto digit : newDigits)
            digitCombinations.push_back({digit});
    } else {
        vector<string> newCombinations;
        newCombinations.reserve(digitCombinations.size() * newDigits.size());
        for (auto middleDigit : newDigits) {
            for (auto combination : digitCombinations) {
                combination.push_back(middleDigit);
                newCombinations.push_back(move(combination));
            }
        }
        digitCombinations = move(newCombinations);
    }
}

void mirrorCombination(string& digits, bool oddLength) {
    static const unordered_map<char, char> digitMirror{{'1', '1'}, {'8', '8'}, {'0', '0'}, {'6', '9'}, {'9', '6'}};
    digits.reserve(digits.size() * 2);
    auto digitIt = rbegin(digits);
    if (oddLength)
        ++digitIt;
    for (;digitIt != rend(digits); ++digitIt)
        digits.push_back(digitMirror.at(*digitIt));
}

vector<string> findStrobogrammatic(int n) {
    static const DigitsT borderStroboDigits{'1', '8', '6', '9'}; // 0 can't be at the first place
    static const DigitsT noneBorderStroboDigits{'1', '8', '6', '9', '0'};
    static const DigitsT middleStroboDigits{'1', '8', '0'};
    if (n == 0)
        return {};
    vector<string> digitCombinations;
    if (n == 1) {
        growCombinations(digitCombinations, middleStroboDigits);
    } else {
        growCombinations(digitCombinations, borderStroboDigits);
        int halfLength = n / 2;
        for (int i = 1; i < halfLength; ++i)
            growCombinations(digitCombinations, noneBorderStroboDigits);
        bool oddLength = n % 2 != 0;
        if (oddLength)
            growCombinations(digitCombinations, middleStroboDigits);
        for (auto& combination : digitCombinations)
            mirrorCombination(combination, oddLength);
    }
    return digitCombinations;
}

#endif //ALGORITHMICCHALLENGES_247_STROBOGRAMMATICNUMBERII_H
