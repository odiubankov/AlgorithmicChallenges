//https://leetcode.com/contest/biweekly-contest-10/problems/stepping-numbers/
#ifndef ALGORITHMICCHALLENGES_STEPPINGNUMBERS_H
#define ALGORITHMICCHALLENGES_STEPPINGNUMBERS_H

#include <vector>

class SolutionSteppingNumbers {

    static bool addNumber(std::vector<int>& result, std::vector<int>& steppingNumbers, int low, int high, int number) {
        if (number > high)
            return false;
        else if (number >= low)
            result.push_back(number);
        steppingNumbers.push_back(number);
        return true;
    }

    static bool getNextSteppingNumbers(std::vector<int>& result, std::vector<int>& steppingNumbers, int low, int high) {
        std::vector<int> nextSteppingNumbers;
        for (auto n : steppingNumbers) {
            int lastDigit = n % 10;
            int nextNumber = n * 10;
            if (lastDigit != 0) {
                if (!addNumber(result, nextSteppingNumbers, low, high, nextNumber + lastDigit - 1))
                    return false;
            }

            if (lastDigit != 9) {
                if (!addNumber(result, nextSteppingNumbers, low, high, nextNumber + lastDigit + 1))
                    return false;
            }
        }

        steppingNumbers = nextSteppingNumbers;
        return true;
    }

public:
    std::vector<int> countSteppingNumbers(int low, int high) {
        std::vector<int> result;
        if (low == 0)
            result.push_back(0);

        std::vector<int> steppingNumbers;
        for (int i = 1; i <= 9; ++i) {
            if (i >= low && i <= high) {
                result.push_back(i);
            }

            steppingNumbers.push_back(i);
        }

        while (getNextSteppingNumbers(result, steppingNumbers, low, high));
        return result;
    }

};

#endif //ALGORITHMICCHALLENGES_STEPPINGNUMBERS_H
