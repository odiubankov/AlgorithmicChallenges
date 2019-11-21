//https://leetcode.com/problems/string-transforms-into-another-string/
#ifndef ALGORITHMICCHALLENGES_1153_STRINGTRANSFORMSINTOANOTHERSTRING_H
#define ALGORITHMICCHALLENGES_1153_STRINGTRANSFORMSINTOANOTHERSTRING_H

#include <string>
#include <array>
#include <unordered_set>
using namespace std;

constexpr size_t getCharsCnt() { return 'z' - 'a' + 1; }
constexpr size_t getCharIndex(char c) { return c - 'a'; }

bool canConvert(string str1, const string& str2) {
    if (str1 == str2)
        return true;
    array<char, getCharsCnt()> mappings{};
    unordered_set<char> usedChars;
    fill(begin(mappings), end(mappings), 'A');
    for (size_t i = 0; i < str1.size(); ++i) {
        if (mappings[getCharIndex(str1[i])] != 'A') {
            if (mappings[getCharIndex(str1[i])] != str2[i])
                return false;
        } else {
            mappings[getCharIndex(str1[i])] = str2[i];
            usedChars.insert(str2[i]);
        }
    }
    return  usedChars.size() < getCharsCnt();
}

#endif //ALGORITHMICCHALLENGES_1153_STRINGTRANSFORMSINTOANOTHERSTRING_H
