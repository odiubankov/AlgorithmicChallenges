//https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
#ifndef ALGORITHMICCHALLENGES_857_MINIMUMCOSTTOHIREKWORKERS_H
#define ALGORITHMICCHALLENGES_857_MINIMUMCOSTTOHIREKWORKERS_H

#include <vector>
#include <map>
#include <limits>
#include <numeric>
#include <queue>
using namespace std;

struct Worker{
    int quality = 0;
    double ratio = 0.0;
    Worker(int q, double r) : quality{q}, ratio{r} {}
};

using QualityPriorityQueue = priority_queue<int, vector<int>, less<>>;

double mincostToHireWorkers(const vector<int>& quality, const vector<int>& wage, int K) {
    if (K == 0)
        return 0;
    vector<Worker> workers;
    workers.reserve(quality.size());
    for (auto qIt = begin(quality), wIt = begin(wage); qIt != end(quality); ++qIt, ++wIt) {
        double ratio = static_cast<double>(*wIt) / *qIt;
        workers.emplace_back(*qIt, ratio);
    }
    sort(begin(workers), end(workers),
         [](const Worker& w1, const Worker& w2){ return w1.ratio < w2.ratio; });
    int qualSum = 0;
    auto wIt = begin(workers);
    for (int i = 0; i < K; ++i, ++wIt)
        qualSum += wIt->quality;
    double minCost = qualSum * (wIt - 1)->ratio;
    QualityPriorityQueue qualityPriorityQueue;
    for_each(begin(workers), wIt,
        [&qualityPriorityQueue](const auto& w) { qualityPriorityQueue.push(w.quality); });
    for (; wIt != end(workers); ++wIt) {
        qualityPriorityQueue.push(wIt->quality);
        qualSum += wIt->quality;
        qualSum -= qualityPriorityQueue.top();
        qualityPriorityQueue.pop();
        double cost = wIt->ratio * qualSum;
        minCost = min(minCost, cost);
    }
    return minCost;
}

#endif //ALGORITHMICCHALLENGES_857_MINIMUMCOSTTOHIREKWORKERS_H
