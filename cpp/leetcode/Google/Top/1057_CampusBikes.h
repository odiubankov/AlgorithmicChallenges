//https://leetcode.com/problems/campus-bikes/
#ifndef ALGORITHMICCHALLENGES_1057_CAMPUSBIKES_H
#define ALGORITHMICCHALLENGES_1057_CAMPUSBIKES_H

#include <vector>
#include <array>
#include <tuple>
using namespace std;

int getDistance(const vector<int>& worker, const vector<int>& bike) {
    return abs(worker.front() - bike.front()) +
        abs(worker.back() - bike.back());
}

vector<int> assignBikes(const vector<vector<int>>& workers, const vector<vector<int>>& bikes) {
    vector<array<int, 3>> distances;
    distances.reserve(workers.size() * bikes.size());
    for (int worker = 0; worker < workers.size(); ++worker) {
        for (int bike = 0; bike < bikes.size(); ++bike)
            distances.push_back(array<int, 3>{getDistance(workers[worker], bikes[bike]), worker, bike});
    }
    sort(begin(distances), end(distances));
    vector<int> workerBikes(workers.size(), -1);
    vector<bool> assignedBikes(bikes.size(), false);
    for (auto distanceIt = begin(distances); distanceIt != end(distances); ++distanceIt) {
        size_t worker = (*distanceIt)[1];
        if (workerBikes[worker] != -1)
            continue;
        size_t bike = (*distanceIt)[2];
        if (assignedBikes[bike])
            continue;
        workerBikes[worker] = bike;
        assignedBikes[bike] = true;
    }
    return workerBikes;
}


#endif //ALGORITHMICCHALLENGES_1057_CAMPUSBIKES_H
