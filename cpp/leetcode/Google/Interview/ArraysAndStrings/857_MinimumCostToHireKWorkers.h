//https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
#ifndef ALGORITHMICCHALLENGES_857_MINIMUMCOSTTOHIREKWORKERS_H
#define ALGORITHMICCHALLENGES_857_MINIMUMCOSTTOHIREKWORKERS_H

#include <vector>
#include <map>
#include <limits>
#include <numeric>
using namespace std;

struct Worker{
    int quality = 0;
    double ratio = 0.0;
    Worker(int q, double r) : quality{q}, ratio{r} {}
};

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
    for (int i = 0; i < K; ++i) {
        qualSum += wIt->quality;
        ++wIt;
    }
    double minCost = qualSum * (wIt - 1)->ratio;
    vector<int> qualHeap;
    qualHeap.reserve(K + 1); // + 1 because in the cycle below one more item will be pushed & popped on each iter
    transform(begin(workers), wIt, back_inserter(qualHeap),
              [](const auto& w) { return w.quality; });
    make_heap(begin(qualHeap), end(qualHeap));
    for (; wIt != end(workers); ++wIt) {
        qualHeap.push_back(wIt->quality);
        push_heap(begin(qualHeap), end(qualHeap));
        qualSum += wIt->quality;
        pop_heap(begin(qualHeap), end(qualHeap));
        qualSum -= qualHeap.back();
        qualHeap.pop_back();
        double cost = wIt->ratio * qualSum;
        minCost = min(minCost, cost);
    }
    return minCost;
}

#endif //ALGORITHMICCHALLENGES_857_MINIMUMCOSTTOHIREKWORKERS_H
