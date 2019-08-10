#include "2_MinimalTree.h"

namespace {

using RangeIt = std::vector<int>::const_iterator;

std::shared_ptr<BstNode> buildFromSortedRange(const RangeIt& rangeBegin, const RangeIt& rangeEnd, std::size_t size){
    if (size <= 0)
        return std::shared_ptr<BstNode>{};
    auto node = std::make_shared<BstNode>();
    //odd
    auto half = size / 2;
    auto middle = rangeBegin + half;
    node->val_ = *middle;
    node->left_ = buildFromSortedRange(rangeBegin, middle, half);
    std::size_t rightSize = half;
    if (size % 2 == 0)
        --rightSize;
    node->right_ = buildFromSortedRange(middle + 1, rangeEnd, rightSize);
    return node;
}

}

Bst buildTreeFromSortedContainer(const std::vector<int>& vals){
    Bst bst;
    bst.head_ = buildFromSortedRange(begin(vals), end(vals), vals.size());
    return bst;
}
