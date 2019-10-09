#ifndef ALGORITHMICCHALLENGES_9_BSTSEQUENCES_H
#define ALGORITHMICCHALLENGES_9_BSTSEQUENCES_H

#include "DataStructures/TreeNode.h"
#include <vector>

void weave(std::vector<std::vector<int>>& allSequences,
                                    std::vector<int> sequence,
                                    const std::vector<int>::const_iterator& it1, const std::vector<int>::const_iterator& it1End,
                                    const std::vector<int>::const_iterator& it2, const std::vector<int>::const_iterator& it2End) {
    if (it1 == it1End && it2 == it2End) {
        allSequences.push_back(std::move(sequence));
    }
    else if (it1 == it1End) {
        std::copy(it2, it2End, std::back_inserter(sequence));
        allSequences.push_back(std::move(sequence));
    } else if (it2 == it2End) {
        std::copy(it1, it1End, std::back_inserter(sequence));
        allSequences.push_back(std::move(sequence));
    } else {
        auto newSequence = sequence;
        newSequence.push_back(*it1);
        weave(allSequences, std::move(newSequence), it1 + 1, it1End, it2, it2End);
        sequence.push_back(*it2);
        weave(allSequences, std::move(sequence), it1, it1End, it2 + 1, it2End);
    }
}

std::vector<std::vector<int>> getInsertionSequences(TreeNode* root) {
    std::vector<std::vector<int>> result;
    std::vector<int> prefix;
    if (root)
        prefix.push_back(root->val);
    else{
        result.push_back(prefix);
        return result;
    }

    if (!root->left && !root->right) {
        result.push_back(std::move(prefix));
        return result;
    }
    std::vector<std::vector<int>> leftSequences, rightSequences;
    if (root->left)
        leftSequences = getInsertionSequences(root->left);
    else
        leftSequences.push_back({});
    if (root->right)
        rightSequences = getInsertionSequences(root->right);
    else
        rightSequences.push_back({});

    for (const auto& leftSequence : leftSequences) {
        for (const auto& rightSequence: rightSequences) {
            std::vector<std::vector<int>> combinationResults;
            weave(combinationResults, prefix, begin(leftSequence), end(leftSequence), begin(rightSequence), end(rightSequence));
            for (auto& res : combinationResults) {
                result.push_back(std::move(res));
            }
        }
    }

    return result;
}

#endif //ALGORITHMICCHALLENGES_9_BSTSEQUENCES_H
