//https://leetcode.com/problems/implement-strstr/
#ifndef ALGORITHMICCHALLENGES_28_IMPLEMENTSTRSTR_H
#define ALGORITHMICCHALLENGES_28_IMPLEMENTSTRSTR_H

#include <string>
#include <cmath>

using namespace std;

namespace {
    const unsigned long long MODULUS = pow(2,31);
    const int NPOS = -1;
}

constexpr size_t getAlphabetSize() { return 'z' - 'a' + 1; }
constexpr size_t getCharIndex(char c) { return c - 'a'; }

unsigned long long getStrHash(const string& str) {
    unsigned long long hashVal = 0;
    for (auto character : str) {
        hashVal *= getAlphabetSize();
        hashVal += getCharIndex(character);
        hashVal %= MODULUS;
    }
    return hashVal;
}

unsigned long long getFirstCharMultiplier(size_t length) {
    unsigned long long firstCharacterMultiplier = 1;
    for (size_t i = 0; i < length - 1; ++i)
        firstCharacterMultiplier = (firstCharacterMultiplier * getAlphabetSize()) % MODULUS;
    return firstCharacterMultiplier;
}

unsigned long long rollHash(
    unsigned long long hash,
    unsigned long long firstCharacterMultiplier,
    char toRemove,
    char toAdd) {
    hash -= getCharIndex(toRemove) * firstCharacterMultiplier;
    hash *= getAlphabetSize();
    hash += getCharIndex(toAdd);
    hash %= MODULUS;
    return hash;
}

int strStr(const string& haystack, const string& needle) {
    if (needle.length() > haystack.length())
        return -1;
    if (needle.empty())
        return 0;
    const auto needleHash = getStrHash(needle);
    auto strHash = getStrHash(haystack.substr(0, needle.length()));
    if (strHash == needleHash)
        return 0;
    const auto firstCharacterMultiplier = getFirstCharMultiplier(needle.length());
    for (size_t start = 1; start != (haystack.length() - needle.length() + 1); ++start) {
        strHash = rollHash(
            strHash,
            firstCharacterMultiplier,
            haystack[start -1],
            haystack[start + needle.length() - 1]);
        if (strHash == needleHash)
            return start;
    }
    return NPOS;
}

#endif //ALGORITHMICCHALLENGES_28_IMPLEMENTSTRSTR_H
