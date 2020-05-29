#ifndef ALGORITHMICCHALLENGES_943_FINDTHESHORTESTSUPERSTRING_H
#define ALGORITHMICCHALLENGES_943_FINDTHESHORTESTSUPERSTRING_H

#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

using OverlapsT = vector<vector<int>>;
size_t constexpr MaxLength = 12;
using RemainingStringsT = std::bitset<MaxLength>;
using FirstStringIndexT = size_t;
using CacheT = unordered_map<RemainingStringsT, vector<vector<size_t>>>;

void findShortestSuperstring(
        CacheT& cache, vector<string> const& A,
        OverlapsT const& overlaps, RemainingStringsT remainingStrings) {
    if (cache.find(remainingStrings) != end(cache)) {
        return;
    }

    for (size_t i = 0; i != MaxLength; ++i) {
        if (remainingStrings.test(i)) {

            
            auto remainingStringsCopy
        }
    }
}

string shortestSuperstring(vector<string> const& A) {
    OverlapsT overlaps(A.size(), vector<int>(A.size(), 0));
    for (size_t i = 0; i != A.size(); ++i) {
        for (size_t j = 0; j != A.size(); ++j) {
            for (int k = 1; k != A[i].size(); ++k) {
                if (A[i].substr(k) == A[j].substr(0, A[i].size() - k)) {
                    overlaps[i][j] = k;
                    break;
                }
            }
        }
    }


    CacheT cache;
    RemainingStringsT remainingStrings(0);
    remainingStrings.flip();
}

#endif //ALGORITHMICCHALLENGES_943_FINDTHESHORTESTSUPERSTRING_H
