#include "3_ListOfDepth.h"

namespace{

void getListOfDepth(const BstNodePtr& node, ListOfDepth& lod, std::size_t level){
    if (!node)
        return;
    if (level == lod.size())
        lod.push_back(std::list<int>{});
    lod[level].push_back(node->val_);
    getListOfDepth(node->left_, lod, level + 1);
    getListOfDepth(node->right_, lod, level + 1);
}

}

ListOfDepth getListOfDepth(const Bst& bst){
    ListOfDepth lod;
    getListOfDepth(bst.head_, lod, 0);
    return lod;
}
