//https://leetcode.com/problems/cracking-the-safe/
#ifndef ALGORITHMICCHALLENGES_753_CRACKINGTHESAFE_H
#define ALGORITHMICCHALLENGES_753_CRACKINGTHESAFE_H

#include <string>
#include <vector>
#include <math.h>
#include <unordered_set>
#include <sstream>
#include <stack>
using namespace std;

string crackSafe(int n, int k) {
    const int totalCombinations = pow(k, n);
    const int divider = pow(10, n - 1);
    // first - the number entered to safe; second - the digit which is added to the current number
    stack<pair<int, int>> path;
    // start from zero
    path.emplace(0, -1);
    // visit each number only once so that the total path is minimum
    unordered_set<int> visited{0};
    while (path.size() != totalCombinations) {
       int nextNumber = (path.top().first % divider) * 10;
       bool nextFound = false;
       // try out the next digit which is not tried yet
       for (int i = path.top().second + 1; i < k && !nextFound; ++i) {
           if (visited.find(nextNumber + i) == end(visited)) {
               path.top().second = i;
               nextNumber += i;
               path.emplace(nextNumber, -1);
               visited.insert(nextNumber);
               nextFound = true;
           }
       }
       // if next digit is not found go step back and try the whole chain again
       if (!nextFound) {
           visited.erase(path.top().first);
           path.pop();
       }
    }

    stringstream ss;
    path.pop();
    while (!path.empty()) {
        ss << path.top().second;
        path.pop();
    }

    for (int i = 0; i < n; ++i)
        ss << '0';

    return ss.str();
}

#endif //ALGORITHMICCHALLENGES_753_CRACKINGTHESAFE_H
