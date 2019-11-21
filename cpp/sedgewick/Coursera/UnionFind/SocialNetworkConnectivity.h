//https://www.coursera.org/learn/algorithms-part1/quiz/SCxqJ/interview-questions-union-find-ungraded/attempt
#ifndef ALGORITHMICCHALLENGES_SOCIALNETWORKCONNECTIVITY_H
#define ALGORITHMICCHALLENGES_SOCIALNETWORKCONNECTIVITY_H

#include <vector>
using namespace std;

int root(const vector<int>& people, int index) {
    while (people[index] != index)
        index = people[index];
    return index;
}

//n - members cnt
//return an index at which point all members of network become connected
//m
int getAllConnectedTime(int n, const vector<pair<int, int>>& friendships) {
    //extra space n
    //time m*lg(n)
    vector<int> people(n);
    for (int i = 0; i < n; ++i)
        people[i] = i;
    vector<int> groupSize(n, 1);
    for (int i = 0; i < friendships.size(); ++i) {
        int root1 = root(people, friendships[i].first);
        int root2 = root(people, friendships[i].second);
        if (groupSize[root1] < groupSize[root2]) {
            people[root1] = root2;
            groupSize[root1] += groupSize[root2];
            if (groupSize[root1] == n)
                return i;
        } else {
            people[root2] = root1;
            groupSize[root2] += groupSize[root1];
            if (groupSize[root2] == n)
                return i;
        }
    }
    return -1;
}

#endif //ALGORITHMICCHALLENGES_SOCIALNETWORKCONNECTIVITY_H
