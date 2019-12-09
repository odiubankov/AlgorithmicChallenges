//https://leetcode.com/problems/odd-even-jump/
#ifndef ALGORITHMICCHALLENGES_975_ODDEVENJUMP_H
#define ALGORITHMICCHALLENGES_975_ODDEVENJUMP_H

#include <vector>
#include <map>
using namespace std;

// Complexity O(n*lg(n))
struct Res {
    bool odd = false, even = false;
};
using ValsT = map<int, Res>;
int oddEvenJumps(const vector<int>& A) {
    if (A.empty())
        return 0;
    ValsT vals;
    int res = 1;
    vals[A.back()] = Res {true, true};
    for (int i = A.size() - 2; i >= 0; --i) {
        Res resI{};
        auto oddIt = vals.lower_bound(A[i]);
        if (oddIt != end(vals))
            resI.odd = oddIt->second.even;
        auto evenIt = end(vals);
        if (oddIt != end(vals) && oddIt->first == A[i]) {
            evenIt = oddIt;
        } else if (oddIt != begin(vals)) {
            evenIt = oddIt;
            --evenIt;
        }
        if (evenIt != end(vals))
            resI.even = evenIt->second.odd;
        if (resI.odd)
            ++res;
        vals[A[i]] = resI;
    }
    return res;
}

#endif //ALGORITHMICCHALLENGES_975_ODDEVENJUMP_H
