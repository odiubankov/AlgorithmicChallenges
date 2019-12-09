//https://leetcode.com/problems/min-stack/
#ifndef ALGORITHMICCHALLENGES_155_MINSTACK_H
#define ALGORITHMICCHALLENGES_155_MINSTACK_H

#include <stack>

using namespace std;

class MinStack {
    stack<int> vals_, mins_;

public:
    void push(int x) {
        vals_.push(x);
        int newMin = x;
        if (!mins_.empty())
            newMin = min(mins_.top(), newMin);
        mins_.push(newMin);
    }

    void pop() {
        mins_.pop();
        vals_.pop();
    }

    int top() {
        return vals_.top();
    }

    int getMin() {
        return mins_.top();
    }
};

#endif //ALGORITHMICCHALLENGES_155_MINSTACK_H
