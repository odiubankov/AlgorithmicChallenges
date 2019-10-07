//https://leetcode.com/problems/implement-queue-using-stacks/
#ifndef ALGORITHMICCHALLENGES_4_QUEUEVIASTACKS_H
#define ALGORITHMICCHALLENGES_4_QUEUEVIASTACKS_H

#include <stack>

class MyQueue {
    std::stack<int> stackPush, stackPop;

    void fillStackPop() {
        if (stackPop.empty()) {
            while (!stackPush.empty()) {
                stackPop.push(stackPush.top());
                stackPush.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        stackPush.push(x);
    }

    int pop() {
        fillStackPop();
        int res = stackPop.top();
        stackPop.pop();
        return res;
    }

    int peek() {
        fillStackPop();
        return stackPop.top();
    }

    bool empty() {
        return stackPop.empty() && stackPush.empty();
    }
};

#endif //ALGORITHMICCHALLENGES_4_QUEUEVIASTACKS_H
