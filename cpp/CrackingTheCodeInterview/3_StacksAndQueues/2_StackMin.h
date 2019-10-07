#ifndef ALGORITHMICCHALLENGES_2_STACKMIN_H
#define ALGORITHMICCHALLENGES_2_STACKMIN_H

#include <stack>
#include <limits>

class StackMin {
public:
    void push(int val);
    int pop();
    int min() const;

private:
    std::stack<int> items_;
    std::stack<int> mins_;
    int currentMin_ = std::numeric_limits<int>::max();
};

#endif //ALGORITHMICCHALLENGES_2_STACKMIN_H
