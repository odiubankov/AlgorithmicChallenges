//https://leetcode.com/problems/random-pick-with-weight/
#ifndef ALGORITHMICCHALLENGES_528_RANDOMPICKWITHWEIGHT_H
#define ALGORITHMICCHALLENGES_528_RANDOMPICKWITHWEIGHT_H

#include <vector>
#include <random>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> ranges;
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> uni;

public:
    Solution(vector<int>& w) {
        int current = 0;
        for (auto val : w) {
            current += val;
            ranges.push_back(current);
        }
        uni = uniform_int_distribution<int>{0, ranges.back() - 1};
    }

    int pickIndex() {
        int targ = uni(rng);
        auto it = upper_bound(begin(ranges), end(ranges), targ);
        return distance(begin(ranges), it);
    }
};

class SolutionWithItemsRemoval {
    struct Node {
        Node* left_ = nullptr;
        Node* right_ = nullptr;
        int ballId_ = -1;
        int cnt_ = 0;
        int lessCnt_ = 0;
        int greaterCnt_ = 0;
    };

    void addItem(Node** node, int ballId, int cnt) {
        if (!(*node)) {
            (*node) = new Node();
            (*node)->ballId_ = ballId;
            (*node)->cnt_ = cnt;
        } else if (ballId > (*node)->ballId_) {
            (*node)->greaterCnt_ += cnt;
            addItem(&((*node)->right_), ballId, cnt);
        } else {
            (*node)->lessCnt_ += cnt;
            addItem(&((*node)->left_), ballId, cnt);
        }
    }

    using BallsCntT = std::vector<int>;
    Node* root_ = nullptr;
    void fillTree(const BallsCntT& balls, int from, int to) {
        if (from == to)
            return;

        const int cnt = to - from;
        const int midI = from + cnt / 2;
        addItem(&root_, midI, balls[midI]);
        fillTree(balls, from, midI);
        fillTree(balls, midI + 1, to);
    }

    int randomPickWithWeight(Node* node) {
        const int totalRange = node->lessCnt_ + node->cnt_ +  node->greaterCnt_;
        if (totalRange == 0)
            return -1;

        const int val = rand() % totalRange;
        if (val < node->lessCnt_) {
            --(node->lessCnt_);
            return randomPickWithWeight(node->left_);
        }

        if (val < (node->lessCnt_ + node->cnt_)) {
            --(node->cnt_);
            return node->ballId_;
        }

        --(node->greaterCnt_);
        return randomPickWithWeight(node->right_);
    }

public:
    explicit SolutionWithItemsRemoval(const std::vector<int>& balls) {
        srand(time(0));
        fillTree(balls, 0, balls.size());
    }

    int randomPickWithWeight() {
        if (!root_)
            return -1;
        return randomPickWithWeight(root_);
    }
};

#endif //ALGORITHMICCHALLENGES_528_RANDOMPICKWITHWEIGHT_H
