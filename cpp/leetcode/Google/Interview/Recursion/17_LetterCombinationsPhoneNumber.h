//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#ifndef ALGORITHMICCHALLENGES_17_LETTERCOMBINATIONSPHONENUMBER_H
#define ALGORITHMICCHALLENGES_17_LETTERCOMBINATIONSPHONENUMBER_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

using StrItT = string::iterator;

void getCombinations(StrItT it, StrItT itE, vector<string>& combinations, string prefix) {
    if (it == itE) {
        combinations.push_back(move(prefix));
    } else {
        static const unordered_map<char, string> digitChars{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        for (auto c : digitChars.at(*it)) {
            getCombinations(it + 1, itE, combinations, prefix + c);
        }
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty())
        return {};
    vector<string> combinations;
    getCombinations(begin(digits), end(digits), combinations, "");
    return combinations;
}

#endif //ALGORITHMICCHALLENGES_17_LETTERCOMBINATIONSPHONENUMBER_H
