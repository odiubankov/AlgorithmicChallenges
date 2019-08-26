#include "3_ListOfDepth.h"

namespace{

void getListOfDepthRecursion(const BstNodePtr& node, ListOfDepth& lod, std::size_t level){
    if (!node)
        return;
    if (level == lod.size())
        lod.push_back(std::vector<int>{});
    lod[level].push_back(node->val_);
    getListOfDepthRecursion(node->left_, lod, level + 1);
    getListOfDepthRecursion(node->right_, lod, level + 1);
}

}

ListOfDepth getListOfDepthRecursion(const Bst& bst){
    ListOfDepth lod;
    getListOfDepthRecursion(bst.head_, lod, 0);
    return lod;
}

ListOfDepth getListOfDepthIterative(const Bst& bst){
    ListOfDepth lod;
    std::vector<BstNodePtr> currentNodes, nextNodes;
    if (bst.head_)
        currentNodes.push_back(bst.head_);
    while (!currentNodes.empty()) {
        std::vector<int> level;
        for (const auto& node : currentNodes){
            level.push_back(node->val_);
            if (node->left_)
                nextNodes.push_back(node->left_);
            if (node->right_)
                nextNodes.push_back(node->right_);
        }
        lod.push_back(std::move(level));
        currentNodes = std::move(nextNodes);
        nextNodes.clear();
    }
    return lod;
}
