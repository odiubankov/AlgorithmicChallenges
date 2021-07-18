// https://leetcode.com/problems/valid-palindrome/
#ifndef ALGORITHMICCHALLENGES_125_VALIDPALINDROME_H
#define ALGORITHMICCHALLENGES_125_VALIDPALINDROME_H

#include <string>
#include <sstream>

using namespace std;

bool isPalindrome(string s) {
    stringstream ssRelevantChars;
    for (auto c : s) {
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9')) {
            if (c >= 'a' && c <= 'z') {
                ssRelevantChars << char(c + ('A' - 'a'));
            } else {
                ssRelevantChars << c;
            }
        }
    }

    s = ssRelevantChars.str();
    if (s.size() < 2)
        return true;

    int l = s.size() / 2 - 1;
    int r = s.size() - 1 - l;
    while (l >= 0) {
        if (s[l] != s[r])
            return false;
        --l;
        ++r;
    }

    return true;
}

#endif //ALGORITHMICCHALLENGES_125_VALIDPALINDROME_H
