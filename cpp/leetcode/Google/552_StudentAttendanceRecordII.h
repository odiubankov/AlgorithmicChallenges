//https://leetcode.com/problems/student-attendance-record-ii/
#ifndef ALGORITHMICCHALLENGES_552_STUDENTATTENDANCERECORDII_H
#define ALGORITHMICCHALLENGES_552_STUDENTATTENDANCERECORDII_H

int moduloAdd(const vector<int>& numbers) {
    int res = numbers.front();
    for (auto it = begin(numbers) + 1; it != end(numbers); ++it) {
        res += *it;
        res %= 1000000007;
    }
    return res;
}

int checkRecord(int n) {
    if (n == 1)
        return 3;
    //i == 2
    int noAbsenceEndOneLate = 1;
    int noAbsenceEndPresent = 2;
    int noAbsenceEndTwoLates = 1;
    int absenceEndPresent = 1;
    int absenceEndOneLate = 1;
    int absenceEndAbsence = 2;
    int absenceEndTwoLates = 0;
    for (int i = 3; i <= n; ++i) {
        int nextNoAbsenceEndOneLate = noAbsenceEndPresent;
        int nextNoAbsenceEndPresent = moduloAdd({noAbsenceEndOneLate, noAbsenceEndPresent, noAbsenceEndTwoLates});
        int nextNoAbsenceEndTwoLates = noAbsenceEndOneLate;
        int nextAbsenceEndPresent = moduloAdd({absenceEndPresent, absenceEndOneLate, absenceEndAbsence, absenceEndTwoLates});
        int nextAbsenceEndOneLate = moduloAdd({absenceEndPresent, absenceEndAbsence});
        int nextAbsenceEndAbsence = moduloAdd({noAbsenceEndOneLate, noAbsenceEndPresent, noAbsenceEndTwoLates});
        int nextAbsenceEndTwoLates = absenceEndOneLate;
        noAbsenceEndOneLate = nextNoAbsenceEndOneLate;
        noAbsenceEndPresent = nextNoAbsenceEndPresent;
        noAbsenceEndTwoLates = nextNoAbsenceEndTwoLates;
        absenceEndPresent = nextAbsenceEndPresent;
        absenceEndOneLate = nextAbsenceEndOneLate;
        absenceEndAbsence = nextAbsenceEndAbsence;
        absenceEndTwoLates = nextAbsenceEndTwoLates;
    }
    return moduloAdd({noAbsenceEndOneLate, noAbsenceEndPresent, noAbsenceEndTwoLates, absenceEndPresent, absenceEndOneLate,
        absenceEndAbsence, absenceEndTwoLates});
}

#endif //ALGORITHMICCHALLENGES_552_STUDENTATTENDANCERECORDII_H
