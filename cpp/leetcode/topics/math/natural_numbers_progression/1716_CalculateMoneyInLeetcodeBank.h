#ifndef ALGORITHMICCHALLENGES_1716_CALCULATEMONEYINLEETCODEBANK_H
#define ALGORITHMICCHALLENGES_1716_CALCULATEMONEYINLEETCODEBANK_H

int getProgressionSum(int n) {
    return (n * (n + 1)) / 2;
}

int totalMoney(int n) {
    int completeWeeksCnt = n / 7;
    int total = 0;
    for (int i = 0; i != 7; ++i) {
        int lastNumber = completeWeeksCnt + i;
        total += getProgressionSum(lastNumber);
        total -= getProgressionSum(i);
    }

    int lastWeekDayVal = completeWeeksCnt + 1;
    for (int i = completeWeeksCnt * 7 + 1; i <= n; ++i) {
        total += lastWeekDayVal;
        ++lastWeekDayVal;
    }

    return total;
}

#endif //ALGORITHMICCHALLENGES_1716_CALCULATEMONEYINLEETCODEBANK_H
