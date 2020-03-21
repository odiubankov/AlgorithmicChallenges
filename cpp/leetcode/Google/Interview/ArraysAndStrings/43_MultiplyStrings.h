//https://leetcode.com/problems/multiply-strings/
#ifndef ALGORITHMICCHALLENGES_43_MULTIPLYSTRINGS_H
#define ALGORITHMICCHALLENGES_43_MULTIPLYSTRINGS_H
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> toDigits(const string& num) {
    vector<int> digits;
    digits.reserve(num.length());
    for (auto c : num)
        digits.push_back(c - '0');
    return digits;
}

string multiply(const string& num1, const string& num2) {
    auto num1Digits = toDigits(num1), num2Digits = toDigits(num2);
    vector<vector<int>> toSum;
    for (auto dig2 = rbegin(num2Digits); dig2 != rend(num2Digits); ++dig2) {
        int mem = 0;
        vector<int> res(distance(rbegin(num2Digits), dig2), 0);
        for (auto dig1 = rbegin(num1Digits); dig1 != rend(num1Digits); ++dig1) {
            int mulRes = *dig2 * *dig1 + mem;
            res.push_back(mulRes % 10);
            mem = mulRes / 10;
        }
        while (mem > 0) {
            res.push_back(mem % 10);
            mem /= 10;
        }
        toSum.push_back(move(res));
    }
    vector<int> resDigits;
    resDigits.reserve(toSum.back().size());
    int mem = 0;
    for (size_t i = 0; i < toSum.back().size(); ++i) {
        int val = mem;
        for (auto toSumIt = begin(toSum); toSumIt != end(toSum); ++toSumIt) {
            if (toSumIt->size() > i) {
                val += (*toSumIt)[i];
            }
        }
        resDigits.push_back(val % 10);
        mem = val / 10;
    }
    while (mem > 0) {
        resDigits.push_back(mem % 10);
        mem /= 10;
    }
    string resStr;
    resStr.reserve(resDigits.size());
    for (auto digitIt = find_if(rbegin(resDigits), rend(resDigits), [](auto d) { return d != 0; }); digitIt != rend(resDigits); ++digitIt)
        resStr.push_back('0' + *digitIt);
    if (resStr.empty())
        return "0";
    return resStr;
}

int charToNum(char c) { return c - '0'; }

string multiplySimple(const string& num1, const string& num2) {
    string res(num1.size() + num2.size(), '0');
    for (int i = num1.size() - 1; i >= 0; --i) {
        for (int j = num2.size() - 1; j >= 0; --j) {
            int sum = (charToNum(num1.at(i))) * (charToNum(num2.at(j))) + charToNum(res.at(i + j + 1));
            res[i + j + 1] = sum % 10 + '0';
            res[i + j] += sum / 10;
        }
    }

    auto startPos = res.find_first_not_of("0");
    return startPos != string::npos ? res.substr(startPos) : "0";
}

#endif //ALGORITHMICCHALLENGES_43_MULTIPLYSTRINGS_H
