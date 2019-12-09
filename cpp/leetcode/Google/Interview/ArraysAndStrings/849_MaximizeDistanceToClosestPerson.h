//https://leetcode.com/problems/maximize-distance-to-closest-person/
#ifndef ALGORITHMICCHALLENGES_849_MAXIMIZEDISTANCETOCLOSESTPERSON_H
#define ALGORITHMICCHALLENGES_849_MAXIMIZEDISTANCETOCLOSESTPERSON_H

#include <vector>
using namespace std;

int maxDistToClosest(const vector<int>& seats) {
    const int OccupiedVal = 1;
    auto leftOccupiedIt = find(begin(seats), end(seats), OccupiedVal);
    int distanceLeft = distance(begin(seats), leftOccupiedIt);
    auto rightOccupiedIt = find(rbegin(seats), rend(seats), OccupiedVal);
    int distanceRight = distance(rbegin(seats), rightOccupiedIt);
    int maxDistance = max(distanceLeft, distanceRight);
    for (;;) {
        auto nextOccupiedIt = find(leftOccupiedIt + 1, end(seats), OccupiedVal);
        if (nextOccupiedIt == end(seats))
            break;
        int dist = distance(leftOccupiedIt, nextOccupiedIt) / 2;
        maxDistance = max(maxDistance, dist);
        leftOccupiedIt = nextOccupiedIt;
    }
    return maxDistance;
}

#endif //ALGORITHMICCHALLENGES_849_MAXIMIZEDISTANCETOCLOSESTPERSON_H
