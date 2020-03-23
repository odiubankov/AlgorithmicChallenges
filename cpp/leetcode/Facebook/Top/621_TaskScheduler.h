//https://leetcode.com/problems/task-scheduler/
#ifndef ALGORITHMICCHALLENGES_621_TASKSCHEDULER_H
#define ALGORITHMICCHALLENGES_621_TASKSCHEDULER_H

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <array>

using namespace std;

int leastInterval(const vector<char>& tasks, int n) {
    if (n == 0)
        return tasks.size();
    unordered_map<char, int> tasksCnt;
    for (char t : tasks)
        ++tasksCnt[t];
    vector<char> tasksOrder;
    tasksOrder.reserve(tasksCnt.size());
    vector<pair<char, int>> order;
    order.reserve(tasksCnt.size());
    copy(begin(tasksCnt), end(tasksCnt), back_inserter(order));
    auto cntComp = [](const auto& l, const auto& r) { return l.second > r.second; };
    sort(begin(order), end(order), cntComp);
    int iterN = n;
    int totalIterCnt = 0;
    while (!order.empty()) {
        int i = 0;
        for (; i <= n && i < order.size() && order[i].second != 0; ++i) {
            --order[i].second;
            ++totalIterCnt;
        }
        if (i == order.size() && order.front().second > 0)
            totalIterCnt += n - i + 1;

        sort(begin(order), end(order), cntComp);
        order.erase(find_if(begin(order), end(order), [](const auto& val) { return val.second == 0; }), end(order));
    }
    return totalIterCnt;
}

constexpr size_t alphabetSize() { return 'Z' - 'A' + 1; };
constexpr size_t charIndex(char c) { return c - 'A'; }

int leastIntervalCountEmptySlots(const vector<char>& tasks, int n) {
    if (tasks.empty())
        return 0;

    array<int, alphabetSize()> tasksCnt{};
    for (auto t : tasks)
        ++tasksCnt[charIndex(t)];

    auto mostOftenTaskCntIt = max_element(begin(tasksCnt), end(tasksCnt));
    int emptySlots = (*mostOftenTaskCntIt - 1) * n;
    for (auto it = begin(tasksCnt); it != end(tasksCnt); ++it) {
        if (it != mostOftenTaskCntIt) {
            emptySlots -= min(*it, *mostOftenTaskCntIt - 1);
        }
    }

    int intervals = tasks.size();
    if (emptySlots > 0)
        intervals += emptySlots;
    return intervals;
}

#endif //ALGORITHMICCHALLENGES_621_TASKSCHEDULER_H
