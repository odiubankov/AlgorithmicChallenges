//https://leetcode.com/problems/cracking-the-safe/
#ifndef ALGORITHMICCHALLENGES_753_CRACKINGTHESAFE_H
#define ALGORITHMICCHALLENGES_753_CRACKINGTHESAFE_H

#include <string>
#include <vector>
#include <math.h>
#include <unordered_set>
using namespace std;

string crackSafe(int n, int k) {
    int totalCombinations = pow(k, n);
    int divider = pow(10, n - 1);
    vector<pair<int, int>> path;
    path.emplace_back(0, -1);
    unordered_set<int> visited;
    visited.insert(0);
    while (path.size() < totalCombinations) {
       int nextNumber = (path.back().first % divider) * 10;
       bool nextFound = false;
       for (int i = path.back().second + 1; i < k && !nextFound; ++i) {
           if (visited.find(nextNumber + i) == end(visited)) {
               path.back().second = i;
               nextNumber += i;
               path.emplace_back(nextNumber, -1);
               visited.insert(nextNumber);
               nextFound = true;
           }
       }
       if (!nextFound) {
           visited.erase(path.back().first);
           path.pop_back();
       }
    }
    string res(n, '0');
    res.reserve(n + path.size() - 1);
    for (const auto& node : path) {
        if (node.second == -1)
            break;
        res += to_string(node.second);
    }
    return res;
}

#endif //ALGORITHMICCHALLENGES_753_CRACKINGTHESAFE_H
