//https://leetcode.com/problems/dinner-plate-stacks/
#ifndef ALGORITHMICCHALLENGES_3_STACKOFPLATES_H
#define ALGORITHMICCHALLENGES_3_STACKOFPLATES_H

#include <stack>
#include <vector>
#include <set>

class DinnerPlates {
private:
    int capacity_{1};
    std::vector<std::stack<int>> stacks_;
    std::set<std::size_t> nonFullStacks_;

public:
    DinnerPlates(int capacity)
    : capacity_{capacity} {}

    void push(int val) {
        std::size_t stackIndex = 0;
        if (nonFullStacks_.empty()) {
            stacks_.push_back(std::stack<int>{});
            stackIndex = stacks_.size() - 1;
            nonFullStacks_.insert(stackIndex);
        } else {
            stackIndex = *nonFullStacks_.begin();
        }

        stacks_[stackIndex].push(val);
        if (stacks_[stackIndex].size() == capacity_) {
            nonFullStacks_.erase(stackIndex);
        }
    }

    int pop() {
        if (stacks_.empty())
            return -1;

        int res = stacks_.back().top();
        stacks_.back().pop();
        while (!stacks_.empty() && stacks_.back().empty()) {
            stacks_.pop_back();
            if (!nonFullStacks_.empty())
                nonFullStacks_.erase(--end(nonFullStacks_));
        }

        if (!stacks_.empty())
            nonFullStacks_.insert(stacks_.size() - 1);
        return res;
    }

    int popAtStack(int index) {
        if (index == (stacks_.size() - 1))
            return pop();

        if (stacks_.size() <= index)
            return -1;

        if (stacks_[index].empty())
            return -1;

        int res = stacks_[index].top();
        stacks_[index].pop();
        nonFullStacks_.insert(index);
        return res;
    }
};

#endif //ALGORITHMICCHALLENGES_3_STACKOFPLATES_H
