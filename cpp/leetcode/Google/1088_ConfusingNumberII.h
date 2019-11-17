//https://leetcode.com/problems/confusing-number-ii/
#ifndef ALGORITHMICCHALLENGES_1088_CONFUSINGNUMBERII_H
#define ALGORITHMICCHALLENGES_1088_CONFUSINGNUMBERII_H

#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;


vector<vector<int>> getHalfs(int length) {
    if (length == 0)
        return {};
    static vector<int> digitsToConstruct{ 0, 1, 6, 8, 9 };
    int halfsCnt = pow(digitsToConstruct.size(), length);
    vector<vector<int>> halfs(halfsCnt, vector<int>(length));
    vector<vector<int>::const_iterator> digitsIt(length, begin(digitsToConstruct));
    for (auto& half : halfs) {
        for (size_t i = 0; i < length; ++i)
            half[i] = *digitsIt[i];
        for (size_t i = length - 1;; --i) {
            if (++digitsIt[i] != end(digitsToConstruct) || i == 0)
                break;
            digitsIt[i] = begin(digitsToConstruct);
        }
    }
    return halfs;
}

int addDigits(int number, const vector<int>& digits) {
    for (auto d : digits)
        number = number * 10 + d;
    return number;
}

int checkSame(const vector<int>& firstHalf, const vector<int>& secondHalf) {
    static unordered_map<int, int> digitMap{ {0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6} };
    for (int j = 0; j < firstHalf.size(); ++j) {
        if (firstHalf[j] != digitMap[secondHalf[secondHalf.size() - j - 1]])
            return false;
    }
    return true;
}

int confusingNumberII(int N) {
    if (N < 6)
        return 0;
    if (N == 6)
        return 1;
    if (N <= 9)
        return 2;
    int cnt = 2;
    for (int i = 2;; ++i) {//digits cnt
        bool evenLength = i % 2 == 0;
        int halfLength = i / 2;
        auto halfs = getHalfs(halfLength);
        for (const auto& firstHalf : halfs) {
            if (firstHalf.front() == 0)
                continue;
            int firstHalfNumber = addDigits(0, firstHalf);
            if (evenLength) {
                for (const auto& secondHalf : halfs) {
                    if (!checkSame(firstHalf, secondHalf)) {
                        int number = addDigits(firstHalfNumber, secondHalf);
                        if (number <= N)
                            ++cnt;
                        else
                            return cnt;
                    }
                }
            } else { //odd length
                static vector<int> digitsToConstruct{ 0, 1, 6, 8, 9 };
                for (int m : digitsToConstruct) {
                    bool changingMiddle = m == 6 || m == 9;
                    int withMiddle = addDigits(firstHalfNumber, {m});
                    for (const auto& secondHalf : halfs) {
                        if (changingMiddle || !checkSame(firstHalf, secondHalf)) {
                            int number = addDigits(withMiddle, secondHalf);
                            if (number <= N)
                                ++cnt;
                            else
                                return cnt;
                        }
                    }
                }
            }
        }
    }
}

#endif //ALGORITHMICCHALLENGES_1088_CONFUSINGNUMBERII_H
