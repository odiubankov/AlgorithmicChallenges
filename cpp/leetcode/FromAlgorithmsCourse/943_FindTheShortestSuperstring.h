//https://leetcode.com/problems/find-the-shortest-superstring/
#ifndef ALGORITHMICCHALLENGES_943_FINDTHESHORTESTSUPERSTRING_H
#define ALGORITHMICCHALLENGES_943_FINDTHESHORTESTSUPERSTRING_H

#include <vector>
#include <string>
#include <unordered_map>
#include <bitset>
#include <exception>
#include <sstream>

using namespace std;

/* Overlaps matrix. overlaps[i][j] identifies how many symbols intersect between A[i] and A[j]*/
using OverlapsT = vector<vector<int>>;

/* Bitset defines the indexes of strings that are not used in the combination yet
 * e.g. 0011 0000 0000 will defines that strings A[2] and A[3] are not used yet
 * */
size_t constexpr MaxLength = 12;
using RemainingStringsT = bitset<MaxLength>;

/*Order of indexes defines a combination*/
using CombinationT = vector<size_t>;

/*Multiple combinations*/
using CombinationsT = vector<CombinationT>;

/*Cache shortest combinations with each index that is not use yet*/
using CacheT = unordered_map<RemainingStringsT, CombinationsT>;

/*Get first set index in bitset*/
size_t getStringIndex(RemainingStringsT remainingStrings) {
    for (size_t i = 0; i != MaxLength; ++i) {
        if (remainingStrings.test(i))
            return i;
    }
    throw runtime_error("Index not found");
}

/*Fill the cache with combinations*/
void findShortestSuperstring(
        CacheT& cache, vector<string> const& A,
        OverlapsT const& overlaps, RemainingStringsT remainingStrings) {
    if (cache.find(remainingStrings) != end(cache)) {
        //Do nothing if cache is filled already
        return;
    }

    if (remainingStrings.count() == 1) {
        //There is only one possible combination from one index
        cache[remainingStrings] = CombinationsT{CombinationT{getStringIndex(remainingStrings)}};
        return;
    }

    for (size_t i = 0; i != MaxLength; ++i) {
        //find the shortest combination with having index i as first item in combination
        if (remainingStrings.test(i)) {
            //reset the index i and recursively find all optimal for the remaining indexes
            auto remainingStringsCopy = remainingStrings;
            remainingStringsCopy.reset(i);
            findShortestSuperstring(cache, A, overlaps, remainingStringsCopy);

            //find shortest combination with index i as first one
            auto shortestPathLength = numeric_limits<size_t>::max();
            CombinationT shortestPathCombination;
            for (auto const& combination : cache.at(remainingStringsCopy)) {
                //first string is always included completely
                auto length = A[i].size();
                auto prevIndex = i;
                for (auto index : combination) {
                    //all following strings are included without their overlap with previous string
                    length += (A[index].size() - overlaps[prevIndex][index]);
                    prevIndex = index;
                }
                if (shortestPathLength > length) {
                    shortestPathLength = length;
                    shortestPathCombination = combination;
                }
            }
            CombinationT finalCombination{i};
            move(begin(shortestPathCombination), end(shortestPathCombination), back_inserter(finalCombination));
            //cache found combination
            cache[remainingStrings].push_back(move(finalCombination));
        }
    }
}

//fill overlaps matrix
OverlapsT getOverlaps(vector<string> const& A) {
    OverlapsT overlaps(A.size(), vector<int>(A.size(), 0));
    for (size_t i = 0; i != A.size(); ++i) {
        for (size_t j = 0; j != A.size(); ++j) {
            for (int k = 1; k != A[i].size(); ++k) {
                if (A[i].substr(k) == A[j].substr(0, A[i].size() - k)) {
                    overlaps[i][j] = A[i].size() - k;
                    break;
                }
            }
        }
    }
    return overlaps;
}

RemainingStringsT getAllIndexes(size_t stringsCnt) {
    RemainingStringsT remainingStrings(0);
    for (std::size_t i = 0; i != stringsCnt; ++i)
        remainingStrings.set(i);
    return remainingStrings;
}

CombinationT getShortestPathCombination(CombinationsT const& combinations,
        vector<string> const& A, OverlapsT const& overlaps) {
    auto shortestPathLength = numeric_limits<size_t>::max();
    CombinationT shortestPathCombination;
    for (auto const& combination : combinations) {
        auto indexIt = begin(combination);
        auto length = A[*indexIt].size();
        auto prevIndex = *indexIt;
        ++indexIt;
        for (;indexIt != end(combination); ++indexIt) {
            length += (A[*indexIt].size() - overlaps[prevIndex][*indexIt]);
            prevIndex = *indexIt;
        }
        if (shortestPathLength > length) {
            shortestPathLength = length;
            shortestPathCombination = combination;
        }
    }
    return shortestPathCombination;
}

string convertCombinationToString(CombinationT const& combination, vector<string> const& A, OverlapsT const& overlaps) {
    stringstream ss;
    auto indexIt = begin(combination);
    ss << A[*indexIt];
    auto prevIndex = *indexIt;
    ++indexIt;
    for (; indexIt != end(combination); ++indexIt) {
        ss << A[*indexIt].substr(overlaps[prevIndex][*indexIt]);
        prevIndex = *indexIt;
    }
    return ss.str();
}

string shortestSuperstring(vector<string> const& A) {
    if (A.empty())
        return "";
    auto overlaps = getOverlaps(A);
    CacheT cache;
    auto remainingStrings = getAllIndexes(A.size());
    findShortestSuperstring(cache, A, overlaps, remainingStrings);
    auto shortestPathCombination = getShortestPathCombination(cache.at(remainingStrings), A, overlaps);
    return convertCombinationToString(shortestPathCombination, A, overlaps);
}

#endif //ALGORITHMICCHALLENGES_943_FINDTHESHORTESTSUPERSTRING_H
