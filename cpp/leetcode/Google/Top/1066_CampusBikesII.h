//https://leetcode.com/problems/campus-bikes-ii/
#ifndef ALGORITHMICCHALLENGES_1066_CAMPUSBIKESII_H
#define ALGORITHMICCHALLENGES_1066_CAMPUSBIKESII_H

#include <vector>
#include <limits>
#include <unordered_map>
using namespace std;

int getDistance2(const vector<int>& worker, const vector<int>& bike) {
    return abs(worker.front() - bike.front()) +
        abs(worker.back() - bike.back());
}

int getMinManhattan(vector<bool>& usedBikes, const vector<vector<int>>& distances, int worker,
                    unordered_map<int, unordered_map<vector<bool>, int>>& cache) {
    if (worker == distances.size())
        return 0;
    auto cacheIt = cache[worker].find(usedBikes);
    if (cacheIt != end(cache[worker]))
        return cacheIt->second;
    int minManhattan = numeric_limits<int>::max();
    for (size_t bike = 0; bike < distances[worker].size(); ++bike) {
        if (usedBikes[bike])
            continue;
        usedBikes[bike] = true;
        int manhattan = distances[worker][bike] + getMinManhattan(usedBikes, distances, worker + 1, cache);
        usedBikes[bike] = false;
        if (manhattan < minManhattan) {
            minManhattan = manhattan;
        }
    }
    cache[worker][usedBikes] = minManhattan;
    return minManhattan;
}

int assignBikes2(const vector<vector<int>>& workers, const vector<vector<int>>& bikes) {
    vector<vector<int>> distances(workers.size(), vector<int>(bikes.size()));
    for (int worker = 0; worker < workers.size(); ++worker) {
        for (int bike = 0; bike < bikes.size(); ++bike)
            distances[worker][bike] = getDistance2(workers[worker], bikes[bike]);
    }

    vector<bool> usedBikes(bikes.size(), false);
    unordered_map<int, unordered_map<vector<bool>, int>> cache;
    return getMinManhattan(usedBikes, distances, 0,cache);
}

#endif //ALGORITHMICCHALLENGES_1066_CAMPUSBIKESII_H
