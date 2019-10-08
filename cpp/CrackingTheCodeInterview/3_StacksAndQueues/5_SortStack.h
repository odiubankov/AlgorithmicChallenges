#ifndef ALGORITHMICCHALLENGES_5_SORTSTACK_H
#define ALGORITHMICCHALLENGES_5_SORTSTACK_H

#include <stack>

void sort(std::stack<int>& s) {
    std::stack<int> tmp;
    while (!s.empty()) {
        auto val = s.top();
        s.pop();
        while (!tmp.empty() && tmp.top() > val) {
            s.push(tmp.top());
            tmp.pop();
        }
        tmp.push(val);
    }
    while (!tmp.empty()) {
        s.push(tmp.top());
        tmp.pop();
    }
}

#endif //ALGORITHMICCHALLENGES_5_SORTSTACK_H
