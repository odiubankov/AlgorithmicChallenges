//https://leetcode.com/problems/campus-bikes/
#ifndef ALGORITHMICCHALLENGES_1057_CAMPUSBIKES_H
#define ALGORITHMICCHALLENGES_1057_CAMPUSBIKES_H

#include <vector>
#include <array>
#include <tuple>
#include <algorithm>
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

vector<int> assignBikesBucketSort(vector<vector<int>> const& workers, vector<vector<int>> const& bikes) {
    std::array<vector<pair<int, int>>, 2001> distances;
    for (int worker = 0; worker < workers.size(); ++worker) {
        for (int bike = 0; bike < bikes.size(); ++bike)
            distances[getDistance(workers[worker], bikes[bike])].emplace_back(worker, bike);
    }

    int assignedWorkersCnt = 0;
    vector<int> workerBikes(workers.size(), -1);
    vector<bool> assignedBikes(bikes.size(), false);
    for (auto const& distance : distances) {
        for (auto const& workerBike : distance) {
            if (workerBikes[workerBike.first] == -1 && !assignedBikes[workerBike.second]) {
                workerBikes[workerBike.first] = workerBike.second;
                assignedBikes[workerBike.second] = true;
                if (++assignedWorkersCnt == workers.size())
                    return workerBikes;
            }
        }
    }
    return workerBikes;
}


#endif //ALGORITHMICCHALLENGES_1057_CAMPUSBIKES_H
