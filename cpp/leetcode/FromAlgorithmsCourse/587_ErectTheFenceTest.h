//https://leetcode.com/problems/erect-the-fence/
#ifndef ALGORITHMICCHALLENGES_587_ERECTTHEFENCETEST_H
#define ALGORITHMICCHALLENGES_587_ERECTTHEFENCETEST_H

#include <vector>
#include <algorithm>
#include <limits>
#include <stack>
#include <array>
#include <math.h>

using namespace  std;
using Tree = vector<int>;

bool isCounterClockWise(array<Tree, 3> const & trees) {
    int triangleArea = ((trees[1].front() - trees[0].front()) *
            (trees[2].back() - trees[0].back())) -
            ((trees[1].back() - trees[0].back()) *
            (trees[2].front() - trees[0].front()));
    return triangleArea >= 0;
}

vector<Tree> outerTrees(vector<Tree> const & trees) {
    if (trees.size() <= 3)
        return trees;

    auto bottomRightTree = *std::max_element(begin(trees), end(trees),
            [](Tree const& t1, Tree const& t2){
        if (t1.back() == t2.back()) {
            return t1.front() < t2.front();
        } else {
            return t1.back() > t2.back();
        }
    });
    vector<pair<double, Tree>> slopes;
    slopes.reserve(trees.size() - 1);
    for (auto const & tree : trees) {
        if (tree != bottomRightTree) {
            auto slope = atan2(tree.back() - bottomRightTree.back(),
                               tree.front() - bottomRightTree.front());
            slopes.emplace_back(slope, tree);
        }
    }
    auto slopeComparator =[](auto const& s1, auto const & s2) {
        if (std::abs(s1.first - s2.first) > std::numeric_limits<double>::epsilon()) {
            return s1.first < s2.first;
        } else if (s1.second.back() != s2.second.back()) {
            return s1.second.back() < s2.second.back();
        } else {
            return s1.second.front() < s2.second.front();
        }
    };
    sort(begin(slopes), end(slopes), slopeComparator);
    vector<Tree> outerTrees;
    outerTrees.push_back(bottomRightTree);
    for (auto slopeIt = begin(slopes); slopeIt != end(slopes);) {
        if (outerTrees.size() < 3) {
            outerTrees.push_back(slopeIt->second);
            ++slopeIt;
        } else {
            if (isCounterClockWise({outerTrees[outerTrees.size() - 2], outerTrees.back(), slopeIt->second})) {
                outerTrees.push_back(slopeIt->second);
                ++slopeIt;
            } else {
                outerTrees.pop_back();
            }
        }
    }

    return outerTrees;
}

#endif //ALGORITHMICCHALLENGES_587_ERECTTHEFENCETEST_H
