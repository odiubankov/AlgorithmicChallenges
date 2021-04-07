//https://leetcode.com/problems/campus-bikes-ii/
#ifndef ALGORITHMICCHALLENGES_1066_CAMPUSBIKESII_H
#define ALGORITHMICCHALLENGES_1066_CAMPUSBIKESII_H

#include <vector>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>

using namespace std;

int getDistance2(const vector<int>& worker, const vector<int>& bike) {
    return abs(worker.front() - bike.front()) +
        abs(worker.back() - bike.back());
}

struct AssignedBikes {
    int cost_ = 0;
    size_t nextWorkerToAssignBike_ = 0;
    unsigned int assignedBikes_ = 0;
};

struct AssignedBikesComp {
    bool operator()(const AssignedBikes& bikes1, const AssignedBikes& bikes2) {
        return bikes1.cost_ > bikes2.cost_;
    }
};

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

//dijkstra priority queue
int assignBikesPriorityQueue(const vector<vector<int>>& workers, const vector<vector<int>>& bikes) {
    std::priority_queue<AssignedBikes, vector<AssignedBikes>, AssignedBikesComp> assignedBikesQueue;
    assignedBikesQueue.push(AssignedBikes{});
    std::unordered_set<pair<size_t, int>, pair_hash> visited;
    for (;;) {
        auto assignedBikes = assignedBikesQueue.top();
        if (assignedBikes.nextWorkerToAssignBike_ == workers.size())
            return assignedBikes.cost_;
        assignedBikesQueue.pop();
        auto visitedKey = make_pair(assignedBikes.nextWorkerToAssignBike_, assignedBikes.assignedBikes_);
        if (visited.find(visitedKey) != end(visited))
            continue;
        visited.insert(visitedKey);
        for (size_t i = 0; i != bikes.size(); ++i) {
            unsigned int bikeMask = (1 << i);
            if (!(assignedBikes.assignedBikes_ & bikeMask)) {
                AssignedBikes nextWorker = assignedBikes;
                nextWorker.assignedBikes_ |= bikeMask;
                ++nextWorker.nextWorkerToAssignBike_;
                nextWorker.cost_ += getDistance2(workers[assignedBikes.nextWorkerToAssignBike_], bikes[i]);
                assignedBikesQueue.push(nextWorker);
            }
        }
    }
}

#endif //ALGORITHMICCHALLENGES_1066_CAMPUSBIKESII_H
