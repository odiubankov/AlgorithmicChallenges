//https://leetcode.com/problems/find-median-from-data-stream/description/
#ifndef ALGORITHMICCHALLENGES_295_FINDMEDIANFROMDATASTREAM_H
#define ALGORITHMICCHALLENGES_295_FINDMEDIANFROMDATASTREAM_H

#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
    priority_queue<int, vector<int>, less<>> maxValQueue;
    priority_queue<int, vector<int>, greater<>> minValQueue;
public:
    void addNum(int num) {
        if (minValQueue.empty() || minValQueue.top() >= num) {
            maxValQueue.push(num);
        } else {
            minValQueue.push(num);
        }

        if (maxValQueue.size() < minValQueue.size()) {
            maxValQueue.push(minValQueue.top());
            minValQueue.pop();
        } else if ((maxValQueue.size() - minValQueue.size()) == 2) {
            minValQueue.push(maxValQueue.top());
            maxValQueue.pop();
        }
    }

    double findMedian() {
        if (maxValQueue.size() > minValQueue.size()) {
            return maxValQueue.top();
        }

        return (maxValQueue.top() + minValQueue.top()) / 2.0;
    }
};

#endif //ALGORITHMICCHALLENGES_295_FINDMEDIANFROMDATASTREAM_H
